import os
import sys
import optparse
import ROOT
import commands
import getpass
import pickle
import numpy
from subprocess import Popen, PIPE, STDOUT

from TopLJets2015.TopAnalysis.Plot import *
from TopLJets2015.TopAnalysis.dataCardTools import *

"""
customize getting the distributions for hypothesis testing
"""
def getDistsForHypoTest(fIn,systfIn,cat,rawSignalList,opt,outDir):

    obs,exp=getDistsFrom(fIn.Get('%s_%s_1.0w'%(cat,opt.dist)))

    #signal hypothesis
    _,expMainHypo=getDistsFrom(fIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,opt.mainHypo)))
    expAltHypo=None
    if len(opt.altHypoFromSim)>0 :
        _,expAltHypo=getDistsFrom(systfIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,opt.altHypo)),opt.expAltHypoFromSim)
    else:
        _,expAltHypo=getDistsFrom(fIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,opt.altHypo)))

    #replace DY shape from alternative sample
    try:
        if opt.replaceDYshape:
            _,altDY=getDistsFrom(systfIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,opt.mainHypo)),'DY')
            nbins=exp['DY'].GetNbinsX()
            sf=exp['DY'].Integral(0,nbins+1)/altDY['DY'].Integral(0,nbins+1)
            altDY['DY'].Scale(sf)

            #save a plot with the closure test
            if outDir!="" and opt.doValidation:
                plot=Plot('DY_%s_%s'%(cat,opt.dist))
                plot.savelog=False
                plot.doChi2=True
                plot.wideCanvas=False
                plot.plotformats=['pdf','png']
                plot.add(exp['DY'],  "MG5_aMC@NLO FxFx (NLO)", 1, False, False)
                plot.add(altDY['DY'],"Madgraph MLM (LO)",      2, False, False)
                plot.finalize()
                plot.show(outDir=outDir,lumi=12900,noStack=True)

            #all done here
            exp['DY'].Delete()
            exp['DY']=altDY['DY']
    except:
        pass

    #add signal hypothesis to expectations
    for proc in rawSignalList:
        try:
            newProc=('%s%3.1fw'%(proc,opt.mainHypo)).replace('.','p')
            expMainHypo[proc].SetName(newProc)
            exp[newProc]=expMainHypo[proc]
            newProc=('%s%3.1fw'%(proc,opt.altHypo)).replace('.','p')
            expAltHypo[proc].SetName(newProc)
            exp[newProc]=expAltHypo[proc]
        except:
            pass

    #delete the nominal expectations
    for proc in rawSignalList: 
        try:
            exp[proc].Delete()
            del exp[proc]
        except:
            pass
    return obs,exp

"""
save distributions to file
"""
def saveToShapesFile(outFile,shapeColl,directory=''):
    fOut=ROOT.TFile.Open(outFile,'UPDATE')
    if len(directory)==0:
        fOut.cd()
    else:
        if not fOut.Get(directory):
            fOut.mkdir(directory)
        outDir=fOut.Get(directory)
        outDir.cd()
    for key in shapeColl:
        #remove bin labels
        shapeColl[key].GetXaxis().Clear()

        #convert to TH1D (projections are TH1D)
        if not shapeColl[key].InheritsFrom('TH1D') :
            h=ROOT.TH1D()
            shapeColl[key].Copy(h)
            shapeColl[key]=h

        shapeColl[key].Write(key,ROOT.TObject.kOverwrite)
    fOut.Close()


"""
prepare the steering script for combine
"""
def doCombineScript(opt,args,outDir,dataCardList):

    altHypoTag=('%3.1fw'%opt.altHypo).replace('.','p')

    scriptname='%s/steerHypoTest.sh'%outDir
    script=open(scriptname,'w')
    print 'Starting script',scriptname
    script.write('#\n')
    script.write('# Generated by %s with git hash %s for standard (alternative) hypothesis %3.1f (%3.1f)\n' % (getpass.getuser(),
                                                                                                               commands.getstatusoutput('git log --pretty=format:\'%h\' -n 1')[1],
                                                                                                               opt.mainHypo,
                                                                                                               opt.altHypo) )
    script.write('### environment setup\n')
    script.write('COMBINE=%s\n'%opt.combine)
    script.write('SCRIPTDIR=`dirname ${0}`\n')
    script.write('cd ${COMBINE}\n')
    script.write('eval `scramv1 r -sh`\n')
    script.write('cd ${SCRIPTDIR}\n')
    script.write('\n')
    script.write('### combine datacard and start workspace\n')
    script.write('combineCards.py %s > datacard.dat\n'%dataCardList)
    script.write('text2workspace.py datacard.dat -P HiggsAnalysis.CombinedLimit.TopHypoTest:twoHypothesisTest -m 172.5 --PO verbose --PO altSignal=%s --PO muFloating -o workspace.root\n'%altHypoTag)
    script.write('python ${COMBINE}/HiggsAnalysis/CombinedLimit/test/systematicsAnalyzer.py datacard.dat --all -m 172.5 -f html > systs.html\n')
    script.write('\n')
    script.write('### likelihood scans and fits\n')
    script.write('for x in 0 1; do\n')
    script.write('   combine workspace.root -M MultiDimFit -m 172.5 -P x --floatOtherPOI=1  --algo=grid --points=50 -t -1 --expectSignal=1 --setPhysicsModelParameters x=${x},r=1  -n x_scan_${x}_exp --saveWorkspace;\n')
    script.write('   combine workspace.root -M MaxLikelihoodFit -m 172.5 --redefineSignalPOIs x  -t -1 --expectSignal=1 --setPhysicsModelParameters x=${x},r=1  -n x_fit_${x}_exp --saveWorkspace;\n')
    script.write('done\n')
    script.write('combine workspace.root -M MultiDimFit -m 172.5 -P x --floatOtherPOI=1  --algo=grid --points=50 -n x_scan_obs --minimizerTolerance 0.001 --robustFit=1 --saveWorkspace;\n')
    script.write('combine workspace.root -M MaxLikelihoodFit -m 172.5 --redefineSignalPOIs x --minimizerTolerance 0.001   -n x_fit_obs --saveWorkspace --robustFit=1;\n')
    script.write('\n')
    script.close()

    return scriptname

"""
instantiates one datacard per category
"""
def doDataCards(opt,args):

    # what are our signal processes?
    rawSignalList=opt.signal.split(',')
    ttScenarioList=['tbart']
    mainSignalList,altSignalList=[],[]
    if 'tbart' in rawSignalList:
        ttScenarioList = [('tbart%3.1fw'%h).replace('.','p') for h in [opt.mainHypo,opt.altHypo]]
        mainSignalList += [ttScenarioList[0]]
        altSignalList  += [ttScenarioList[1]]
    tWScenarioList=['tW']
    if 'tW' in rawSignalList:
        tWScenarioList = [('tW%3.1fw'%h).replace('.','p') for h in [opt.mainHypo,opt.altHypo]]
        mainSignalList += [tWScenarioList[0]]
        altSignalList  += [tWScenarioList[1]]

    #define RATE systematics : syst,val,pdf,whiteList,blackList  (val can be a list of values [-var,+var])
    rateSysts=[
          ('lumi_13TeV',       1.062,    'lnN',    [],                  ['DY']),
          ('DYnorm_*CH*',      1.30,     'lnN',    ['DY'],              []),
          ('Wnorm_th',         1.30,     'lnN',    ['W'],               []),
          ('tWnorm_th',        1.054,    'lnN',    tWScenarioList,      []),
          ('tnorm_th',         1.044,    'lnN',    ['tch'],             []),
          ('VVnorm_th',        1.20,     'lnN',    ['Multiboson'],      []),
          ('tbartVnorm_th',    1.30,     'lnN',    ['tbartV'],          []),
          #('sel_*CH*',         1.02,     'lnN',    tWScenarioList+ttScenarioList+['W','tch','Multiboson','tbartV'], ['DY']),
    ]
    
    #define the SHAPE systematics from weighting, varying object scales, efficiencies, etc.
    # syst,weightList,whiteList,blackList,shapeTreatement=0 (none), 1 (shape only), 2 (factorizeRate),nsigma
    weightingSysts=[ 
        ('jes',            ['jes'],                                    [],             ['DY'], 2, 1.0),
        ('jer',            ['jer'],                                    [],             ['DY'], 2, 1.0),
        ('trig_*CH*',      ['trig'],                                   [],             ['DY'], 2, 1.0),
        ('sel_*CH*',       ['sel'],                                    [],             ['DY'], 2, 1.0),
        ('les_*CH*',       ['les'],                                    [],             ['DY'], 2, 1.0),
        ('ltag',           ['ltag'],                                   [],             ['DY'], 2, 1.0),
        ('btag',           ['btag'],                                   [],             ['DY'], 2, 1.0),
        ('pu',             ['pu'],                                     [],             ['DY'], 1, 1.0),
        ('tttoppt',        ['toppt'],                                  ttScenarioList, [],     1, 1.0),
        ('ttMEqcdscale',   ['gen%d'%ig for ig in[3,5,6,4,8,10] ],      ttScenarioList, [],     1, 1.0),
        ('ttPDF',          ['gen%d'%(11+ig) for ig in xrange(0,100) ], ttScenarioList, [],     0, 1.0)
        ]

    #define the SHAPE systematics from dedicated samples : syst,{procs,samples}, shapeTreatment (see above) nsigma
    fileShapeSysts = [
        ('mtop'      ,     {'tbart':['t#bar{t} m=169.5','t#bar{t} m=175.5'],
                            'tW':   ['tW m=169.5','tW m=175.5']}                 , 0, 1./6.),
        ('ttPSScale' ,     {'tbart':['t#bar{t} scale down','t#bar{t} scale up']} , 2, 1.0  ),
        ('ttGenerator',    {'tbart':['t#bar{t} amc@nlo FxFx']},                    1, 1.0  ),
        ('ttPartonShower', {'tbart':['t#bar{t} Herwig++']},                        1, 1.0  ),
        ('tWttInterf',     {'tW':   ['tW DS']},                                    1, 1.0 ),
        ('tWQCDScale',     {'tW':   ['tW scale down','tW scale up']},              1, 1.0 )
        ]


    # prepare output directory
    outDir='%s/hypotest_%3.1fvs%3.1f%s_%s'%(opt.output,
                                            opt.mainHypo,
                                            opt.altHypo, 
                                            'sim' if len(opt.altHypoFromSim)!=0 else '',
                                            'data' if opt.pseudoData==-1 else '%3.1f%s_pseudodata'%(opt.pseudoData, 'sim' if len(opt.pseudoDataFromSim)!=0 else ''))
    os.system('mkdir -p %s'%outDir)
    os.system('rm -rf %s/*'%outDir)

    # get data and nominal expectations and prepare output file
    fIn=ROOT.TFile.Open(opt.input)
    systfIn=None
    if opt.systInput:
        systfIn=ROOT.TFile.Open(opt.systInput)

    # prepare output ROOT file
    outFile='%s/shapes.root'%outDir
    fOut=ROOT.TFile.Open(outFile,'RECREATE')
    fOut.Close()

    # parse the categories to consider
    dataCardList=''
    for cat in opt.cat.split(','):
        lfs='EE'
        if 'EM' in cat : lfs='EM'
        if 'MM' in cat : lfs='MM'

        #data and nominal shapes
        obs,exp=getDistsForHypoTest(fIn,systfIn,cat,rawSignalList,opt,outDir)
              
        #recreate data if requested        
        if opt.pseudoData!=-1:
            pseudoSignal=None
            print '\t pseudo-data is being generated',
            if len(opt.pseudoDataFromSim) and systfIn:
                print 'injecting signal from',opt.pseudoDataFromSim
                _,pseudoSignal=getDistsFrom(systfIn.Get('%s_%s_1.0w'%(cat,opt.dist)),opt.pseudoDataFromSim)
            else:
                print 'injecting signal from weighted',opt.pseudoData            
                _,pseudoSignal=getDistsFrom(fIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,opt.pseudoData)))
            obs.Reset('ICE')
            for proc in exp:
                if not proc in mainSignalList+altSignalList: 
                    obs.Add( exp[proc] )
            for proc in pseudoSignal:
                accept=False
                for sig in rawSignalList: 
                    if sig==proc: accept=True
                if not accept : continue
                obs.Add( pseudoSignal[proc] )
            for xbin in xrange(0,obs.GetNbinsX()+2): obs.SetBinContent(xbin,int(obs.GetBinContent(xbin)))
        
        #start the datacard header
        datacardname='%s/datacard_%s.dat'%(outDir,cat)
        dataCardList+='%s=%s '%(cat,os.path.basename(datacardname))
        datacard=open(datacardname,'w')
        print 'Starting datacard',datacardname
        datacard.write('#\n')
        datacard.write('# Generated by %s with git hash %s for analysis category %s\n' % (getpass.getuser(),
                                                                                          commands.getstatusoutput('git log --pretty=format:\'%h\' -n 1')[1],
                                                                                          cat) )

        datacard.write('#\n')
        datacard.write('imax *\n')
        datacard.write('jmax *\n')
        datacard.write('kmax *\n')
        datacard.write('-'*50+'\n')
        datacard.write('shapes *        * shapes.root %s_%s/$PROCESS %s_%s_$SYSTEMATIC/$PROCESS\n'%(cat,opt.dist,cat,opt.dist))

        #observation
        datacard.write('-'*50+'\n')
        datacard.write('bin 1\n')
        datacard.write('observation %3.1f\n' % obs.Integral())

        #nominal expectations
        print '\t nominal expectations',len(exp)-1
        datacard.write('-'*50+'\n')
        datacard.write('\t\t\t %16s'%'bin')
        for i in xrange(0,len(exp)): datacard.write('%15s'%'1')
        datacard.write('\n')
        datacard.write('\t\t\t %16s'%'process')
        for sig in mainSignalList: datacard.write('%15s'%sig)
        for sig in altSignalList:  datacard.write('%15s'%sig)
        for proc in exp:
            if proc in mainSignalList+altSignalList : continue
            datacard.write('%15s'%proc)
        datacard.write('\n')
        datacard.write('\t\t\t %16s'%'process')
        procCtr=-len(mainSignalList)-len(altSignalList)+1
        for sig in mainSignalList: 
            datacard.write('%15s'%str(procCtr))
            procCtr+=1
        for sig in altSignalList:  
            datacard.write('%15s'%str(procCtr))
            procCtr+=1
        for proc in exp:
            if proc in mainSignalList+altSignalList : continue
            datacard.write('%15s'%str(procCtr))
            procCtr+=1
        datacard.write('\n')
        datacard.write('\t\t\t %16s'%'rate')
        for sig in mainSignalList: datacard.write('%15s'%('%3.2f'%(exp[sig].Integral())))
        for sig in altSignalList:  datacard.write('%15s'%('%3.2f'%(exp[sig].Integral())))
        for proc in exp:
            if proc in mainSignalList+altSignalList : continue
            datacard.write('%15s'%('%3.2f'%(exp[proc].Integral())))
        datacard.write('\n')
        datacard.write('-'*50+'\n')

        #save to nominal to shapes file
        nomShapes=exp.copy()
        nomShapes['data_obs']=obs
        saveToShapesFile(outFile,nomShapes,('%s_%s'%(cat,opt.dist)))

        #rate systematics
        print '\t rate systematics',len(rateSysts)
        for syst,val,pdf,whiteList,blackList in rateSysts:
            if '*CH*' in syst : syst=syst.replace('*CH*',lfs)
            datacard.write('%32s %8s'%(syst,pdf))
            entryTxt=''
            try:
                entryTxt='%15s'%('%3.3f/%3.3f'%(ROOT.TMath.Max(val[0],0.01),val[1]))
            except:
                entryTxt='%15s'%('%3.3f'%val)
            for sig in mainSignalList:
                if (len(whiteList)==0 and not sig in blackList) or sig in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for sig in altSignalList:  
                if (len(whiteList)==0 and not sig in blackList) or sig in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for proc in exp:
                if proc in mainSignalList+altSignalList : continue
                if (len(whiteList)==0 and not proc in blackList) or proc in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            datacard.write('\n')


        #weighting systematics
        for syst,weightList,whiteList,blackList,shapeTreatment,nsigma in weightingSysts:

            if '*CH*' in syst : syst=syst.replace('*CH*',lfs)

            #get shapes and adapt them
            iexpUp,iexpDn=None,None            
            if len(weightList)==1:
                _,iexpUp=getDistsForHypoTest(fIn,systfIn,weightList[0]+"up"+cat,rawSignalList,opt)
                _,iexpDn=getDistsForHypoTest(fIn,systfIn,weightList[0]+"dn"+cat,rawSignalList,opt)
            else:

                #put all the shapes in a 2D histogram
                iexp2D={}                
                for iw in xrange(0,len(weightList)):
                    w=weightList[iw]
                    _,kexp=getDistsForHypoTest(fIn,systfIn,w+cat,rawSignalList,opt)
                    for proc in kexp:
                        nbins=kexp[proc].GetNbinsX()
                        if not proc in iexp2D:
                            name =kexp[proc].GetName()+'2D'
                            title=kexp[proc].GetTitle()
                            xmin =kexp[proc].GetXaxis().GetXmin()
                            xmax =kexp[proc].GetXaxis().GetXmax()
                            nReplicas=len(weightList)
                            iexp2D[proc]=ROOT.TH2D(name,title,nbins,xmin,xmax,nReplicas,0,nReplicas)
                            iexp2D[proc].SetDirectory(0)
                        for xbin in xrange(0,nbins+2):
                            iexp2D[proc].SetBinContent(xbin,iw+1,kexp[proc].GetBinContent(xbin))

                #create the up/down variations
                iexpUp,iexpDn={},{}
                for proc in iexp2D:
                        
                    #create the base shape
                    if not proc in iexpUp:
                        tmp=iexp2D[proc].ProjectionX("tmp",1,1)
                        tmp.Reset('ICE')
                        iexpUp[proc]=tmp.Clone(iexp2D[proc].GetName().replace('2D','up'))
                        iexpUp[proc].SetDirectory(0)
                        iexpDn[proc]=tmp.Clone(iexp2D[proc].GetName().replace('2D','dn'))
                        iexpDn[proc].SetDirectory(0)
                        tmp.Delete()

                    #project each bin shape for the different variations
                    for xbin in xrange(0,iexp2D[proc].GetNbinsX()+2):
                        tmp=iexp2D[proc].ProjectionY("tmp",xbin,xbin)                          
                        tvals=numpy.zeros(tmp.GetNbinsX())
                        for txbin in xrange(1,tmp.GetNbinsX()+1) : tvals[txbin-1]=tmp.GetBinContent(txbin)
                        
                        #mean and RMS based
                        if 'PDF' in syst:                   
                            mean=numpy.mean(tvals)
                            rms=numpy.std(tvals)                              
                            iexpUp[proc].SetBinContent(xbin,mean+rms)
                            iexpDn[proc].SetBinContent(xbin,ROOT.TMath.Max(mean-rms,1.0e-4))

                        #envelope based
                        else:
                            imax=numpy.max(tvals)
                            if iexpUp[proc].GetBinContent(xbin)>0 : imax=ROOT.TMath.Max(iexpUp[proc].GetBinContent(xbin),imax)
                            iexpUp[proc].SetBinContent(xbin,imax)

                            imin=numpy.min(tvals)
                            if iexpDn[proc].GetBinContent(xbin)>0 : imin=ROOT.TMath.Min(iexpDn[proc].GetBinContent(xbin),imin)
                            iexpDn[proc].SetBinContent(xbin,imin)                              
                          
                        tmp.Delete()


                    #all done, can remove the 2D histo from memory
                    iexp2D[proc].Delete()
            

            #check the shapes
            iRateVars={}
            if shapeTreatment>0:
                for proc in iexpUp:
                    nbins=iexpUp[proc].GetNbinsX()

                    #normalize shapes to nominal expectations
                    n=exp[proc].Integral(0,nbins+2)
                    nUp=iexpUp[proc].Integral(0,nbins+2)
                    if nUp>0: iexpUp[proc].Scale(n/nUp)
                    nDn=iexpDn[proc].Integral(0,nbins+2)
                    if nDn>0: iexpDn[proc].Scale(n/nDn)

                    #save a rate systematic from the variation of the yields
                    if n==0 : continue
                    nvarUp=ROOT.TMath.Abs(1-nUp/n)
                    nvarDn=ROOT.TMath.Abs(1-nDn/n )    
                    iRateVars[proc]=1.0+0.5*(nvarUp+nvarDn)
                    if iRateVars[proc]<1.001 : del iRateVars[proc]
                    

            #write the shapes to the ROOT file                    
            saveToShapesFile(outFile,iexpUp,('%s_%s_%sUp'%(cat,opt.dist,syst)))
            saveToShapesFile(outFile,iexpDn,('%s_%s_%sDown'%(cat,opt.dist,syst)))

            #fill in the datacard
            datacard.write('%32s %8s'%(syst,'shape'))
            entryTxt='%15s'%('%3.3f'%nsigma)
            for sig in mainSignalList:
                if (len(whiteList)==0 and not sig in blackList) or sig in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for sig in altSignalList:  
                if (len(whiteList)==0 and not sig in blackList) or sig in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for proc in exp:
                if proc in mainSignalList+altSignalList : continue
                if (len(whiteList)==0 and not proc in blackList) or proc in whiteList:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            datacard.write('\n')

            #write the rate systematics as well
            if shapeTreatment!=2 : continue
            datacard.write('%32s %8s'%(syst+'Rate',pdf))
            for sig in mainSignalList:
                if sig in iRateVars and ((len(whiteList)==0 and not sig in blackList) or sig in whiteList):
                    datacard.write('%15s'%('%3.3f'%iRateVars[sig]))
                else:
                    datacard.write('%15s'%'-')
            for sig in altSignalList:  
                if sig in iRateVars and ((len(whiteList)==0 and not sig in blackList) or sig in whiteList):
                    datacard.write('%15s'%('%3.3f'%iRateVars[sig]))
                else:
                    datacard.write('%15s'%'-')
            for proc in exp:
                if proc in mainSignalList+altSignalList : continue
                if proc in iRateVars and ((len(whiteList)==0 and not proc in blackList) or proc in whiteList):
                    datacard.write('%15s'%('%3.3f'%iRateVars[proc]))
                else:
                    datacard.write('%15s'%'-')
            datacard.write('\n')


        #systematics from dedicated samples
        print '\t simulated systematics',len(fileShapeSysts)
        for syst,procsAndSamples,shapeTreatment,nsigma in fileShapeSysts:

            if '*CH*' in syst : syst=syst.replace('*CH*',lfs)

            iexpUp,iexpDn={},{}
            for proc in procsAndSamples:
                samples=procsAndSamples[proc]
                
                hyposToGet=[opt.mainHypo]
                isSignal=False
                if proc in rawSignalList:
                    isSignal=True
                    hyposToGet.append( opt.altHypo )

                jexpDn,jexpUp=None,None
                for hypo in hyposToGet:
                    if len(samples)==2:
                        _,jexpDn=getDistsFrom(systfIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,hypo)),samples[0])
                        _,jexpUp=getDistsFrom(systfIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,hypo)),samples[1])
                    else:
                        _,jexpUp=getDistsFrom(systfIn.Get('%s_%s_%3.1fw'%(cat,opt.dist,hypo)),samples[0])
                        
                    newProc=proc
                    if isSignal:
                        newProc=('%s%3.1fw'%(proc,hypo)).replace('.','p')

                    jexpUp.values()[0].SetName(newProc)
                    iexpUp[newProc]=jexpUp.values()[0]

                    #if down variation is not found, mirror it
                    try:
                        jexpDn.values()[0].SetName(newProc)
                        iexpDn[newProc]=jexpDn.values()[0]
                    except:
                        idnHisto=jexpUp.values()[0].Clone()
                        idnHisto.SetDirectory(0)
                        for xbin in xrange(0,idnHisto.GetNbinsX()+2):
                            nomVal=exp[newProc].GetBinContent(xbin)
                            newVal=idnHisto.GetBinContent(xbin)
                            diff=ROOT.TMath.Abs(newVal-nomVal)
                            if newVal>nomVal: nomVal-= ROOT.TMath.Max(diff,1e-4)
                            else: nomVal+=diff
                            idnHisto.SetBinContent(xbin,nomVal)
                        iexpDn[newProc]=idnHisto

            #check the shapes
            iRateVars={}
            if shapeTreatment>0:
                for proc in iexpUp:
                    nbins=iexpUp[proc].GetNbinsX()

                    #normalize shapes to nominal expectations
                    n=exp[proc].Integral(0,nbins+2)
                    nUp=iexpUp[proc].Integral(0,nbins+2)
                    if nUp>0: iexpUp[proc].Scale(n/nUp)
                    nDn=iexpDn[proc].Integral(0,nbins+2)
                    if nDn>0: iexpDn[proc].Scale(n/nDn)

                    #save a rate systematic from the variation of the yields
                    if n==0 : continue
                    nvarUp=ROOT.TMath.Abs(1-nUp/n)
                    nvarDn=ROOT.TMath.Abs(1-nDn/n )    
                    iRateVars[proc]=1.0+0.5*(nvarUp+nvarDn)
                    if iRateVars[proc]<1.001 : del iRateVars[proc]

            #write the shapes to the ROOT file                    
            saveToShapesFile(outFile,iexpUp,('%s_%s_%sUp'%(cat,opt.dist,syst)))
            saveToShapesFile(outFile,iexpDn,('%s_%s_%sDown'%(cat,opt.dist,syst)))

            #fill in the datacard
            datacard.write('%32s %8s'%(syst,'shape'))
            entryTxt='%15s'%('%3.3f'%nsigma)
            for sig in mainSignalList:
                if sig in iexpUp:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for sig in altSignalList:
                if sig in iexpUp:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            for proc in exp:
                if proc in mainSignalList+altSignalList : continue
                if proc in iexpUp:
                    datacard.write(entryTxt)
                else:
                    datacard.write('%15s'%'-')
            datacard.write('\n')

            #write the rate systematics as well
            if shapeTreatment!=2 : continue
            datacard.write('%32s %8s'%(syst+'Rate',pdf))
            for sig in mainSignalList:
                if sig in iRateVars :
                    datacard.write('%15s'%('%3.3f'%iRateVars[sig]))
                else:
                    datacard.write('%15s'%'-')
            for sig in altSignalList:  
                if sig in iRateVars :
                    datacard.write('%15s'%('%3.3f'%iRateVars[sig]))
                else:
                    datacard.write('%15s'%'-')
            for proc in exp:
                if proc in mainSignalList+altSignalList : continue
                if proc in iRateVars :
                    datacard.write('%15s'%('%3.3f'%iRateVars[proc]))
                else:
                    datacard.write('%15s'%'-')
            datacard.write('\n')



        print '\t ended datacard generation'
        datacard.close()
    
        if opt.doValidation:
            print '\t running validation'    
            for proc in rawSignalList:
                newProc=('%s%3.1fw'%(proc,opt.mainHypo)).replace('.','p')
                for uncList in [ 'jes,jer,les_*CH*', 
                                 'trig_*CH*,sel_*CH*',
                                 'btag,ltag,pu',
                                 'ttPSScale,ttMEqcdscale,ttPDF,tttoppt',
                                 'ttGenerator,ttPartonShower',
                                 'mtop',
                                 'tWttInterf,tWQCDScale'
                                 ]:
                    if 'tW' in proc and ('ttPS' in uncList or 'ttGen' in uncList) : continue
                    if 'tbart' in proc and 'tWttInterf' in uncList : continue
                    uncList=uncList.replace('*CH*',lfs)
                    plotter=Popen(['python',
                                   '%s/src/TopLJets2015/TopAnalysis/test/TopWidthAnalysis/getShapeUncPlots.py'%(os.environ['CMSSW_BASE']),
                                   '-i','%s/shapes.root'%outDir,
                                   '--cats','%s'%cat,
                                   '--obs', '%s'%opt.dist,
                                   '--proc','%s'%newProc,
                                   '-o','%s'%outDir,
                                   '--uncs','%s'%uncList],
                                  stdout=PIPE,
                                  stderr=STDOUT)
                    plotter.communicate()

    return outDir,dataCardList

"""
steer the script
"""
def main():

    ROOT.gROOT.SetBatch()
    ROOT.gStyle.SetOptTitle(0)
    ROOT.gStyle.SetOptStat(0)

    #configuration
    usage = 'usage: %prog [options]'
    parser = optparse.OptionParser(usage)
    parser.add_option(      '--combine',            dest='combine',            help='CMSSW_BASE for combine installation',         default=None,        type='string')
    parser.add_option('-i', '--input',              dest='input',              help='input plotter',                               default=None,        type='string')
    parser.add_option(      '--systInput',          dest='systInput',          help='input plotter for systs from alt samples',    default=None,        type='string')
    parser.add_option('-d', '--dist',               dest='dist',               help='distribution',                                default='minmlb',    type='string')
    parser.add_option(      '--pseudoData',         dest='pseudoData',         help='pseudo data to use (-1=real data)',           default=1.0,         type=float)
    parser.add_option(      '--replaceDYshape',     dest='replaceDYshape',     help='use DY shape from syst file',                 default=False,       action='store_true')
    parser.add_option(      '--doValidation',       dest='doValidation',       help='create validation plots',                     default=False,       action='store_true')
    parser.add_option(      '--pseudoDataFromSim',  dest='pseudoDataFromSim',  help='pseudo data from dedicated sample',           default='',          type='string')
    parser.add_option(      '--mainHypo',           dest='mainHypo',  help='main hypothesis',                                      default=1.0,         type=float)
    parser.add_option(      '--altHypo',            dest='altHypo',   help='alternative hypothesis',                               default=4.0,         type=float)  
    parser.add_option(      '--altHypoFromSim',     dest='altHypoFromSim',   help='alternative hypothesis from dedicated sample',  default='',          type='string')
    parser.add_option('-s', '--signal',             dest='signal',             help='signal (csv)',                                default='tbart,tW',  type='string')
    parser.add_option('-c', '--cat',                dest='cat',                help='categories (csv)',                         
                      default='lowptEE1b,lowptEE2b,highptEE1b,highptEE2b,lowptEM1b,lowptEM2b,highptEM1b,highptEM2b,lowptMM1b,lowptMM2b,highptMM1b,highptMM2b',    
                      type='string')
    parser.add_option('-o', '--output',             dest='output',             help='output directory',                            default='datacards', type='string')
    (opt, args) = parser.parse_args()

    outDir,dataCardList=doDataCards(opt,args)
    scriptname=doCombineScript(opt,args,outDir,dataCardList)
    print 'Running statistical analysis'
    runCombine=Popen(['sh',scriptname],stdout=PIPE,stderr=STDOUT)
    runCombine.communicate()

"""
for execution from another script
"""
if __name__ == "__main__":
    sys.exit(main())
