import ROOT
import sys
import os

baseDir=sys.argv[1]
optimList=[os.path.join(baseDir,d) for d in os.listdir(baseDir) if 'optim_' in d] 
toCheck=[]
for d in optimList:

    for ch in [121,169,22]:

        try:
            fIn=ROOT.TFile.Open(os.path.join(d,'shapes_%d.root'%ch))
            if fIn.IsZombie():
                raise Exception('corrupted')
            elif fIn.TestBit(ROOT.TFile.kRecovered) : 
                raise Exception('recovered')
            else:
                size=fIn.GetListOfKeys().GetSize()
                if size==0: 
                    raise Exception('no keys')
            fIn.Close()
        except Exception as e:
            print 'Will submit',d,'for',ch,'error:',e
            toCheck.append( '%s,%d'%(d.split('_')[-1],ch) )

if len(toCheck)>0:

    resub=os.path.join(baseDir,'zxstatana_scan_resub.sub')
    with open(resub,'w') as f:
        f.write('executable  = %s/optim_$(optimId)/optimJob_$(finalState).sh\n'%os.path.abspath(baseDir))
        f.write('output       = zxstatana_scan_resub.out\n')
        f.write('error        = zxstatana_scan_resub.err\n')
        f.write('log          = zxstatana_scan_resub.log\n')
        f.write('+JobFlavour = "tomorrow"\n')
        f.write('request_cpus = 4\n')
        f.write('queue optimId,finalState from (\n')
        for j in toCheck: f.write('\t%s\n'%j)
        f.write(')\n')

    print '%d resubmission jobs can be found in %s'%(len(toCheck),resub)
    os.system('condor_submit %s'%resub)
    
