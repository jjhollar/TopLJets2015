-------------------------------------------------------------------------------------------------------------
Setup the ntuple-maker a la Pedro, modified to include AK8 CHS-pruned jets as used in SMP-21-014
-------------------------------------------------------------------------------------------------------------
	cmsrel CMSSW_10_6_17

	cd CMSSW_10_6_17/src

	cmsenv

	git cms-init

###EGM id

	git cms-merge-topic jainshilpi:ULV1_backport10616_forUsers

     	git clone https://github.com/jainshilpi/EgammaPostRecoTools.git -b ULV0 

     	mv EgammaPostRecoTools/python/EgammaPostRecoTools.py RecoEgamma/EgammaTools/python/.

     	git clone https://github.com/jainshilpi/EgammaAnalysis-ElectronTools.git -b UL2017SSV2 EgammaAnalysis/ElectronTools/data/

     	git cms-addpkg EgammaAnalysis/ElectronTools

     	scram b -j 8

###B-fragmentation analyzer

     	mkdir TopQuarkAnalysis 

	cd TopQuarkAnalysis

	git clone -b 94x https://gitlab.cern.ch/psilva/BFragmentationAnalyzer.git

	scram b -j 8

	cd -

###Jet toolbox stuff 

     	cd $CMSSW_BASE/src

	git clone git@github.com:cms-jet/JetToolbox.git JMEAnalysis/JetToolbox -b jetToolbox_102X_v3

	cp /afs/cern.ch/work/k/kshcheli/public/jonathan/toolboxstuff JMEAnalysis/JetToolbox/python/jetToolbox_cff.py

###This package

        cd $CMSSW_BASE/src

	git clone git@github.com:jjhollar/TopLJets2015.git -b 106_protonreco

	scram b -j8

-------------------------------------------------------------------------------------------------------------
Run the ntuple-maker, modified to include AK8 CHS-pruned jets as used in SMP-21-014
(default is set for 2018 data)
-------------------------------------------------------------------------------------------------------------

	cd TopLJets2015/TopAnalysis/test

	cmsRun runMiniAnalyzer_cfg.py

### To run on MC, change these lines as appropriate in runMiniAnalyzer_cfg.py (or on the command line):

     	AK8JECERA      [options are "2016MC", "2017MC", "2018MC"]
	
	options.register('runOnData', True) [should be set to False for MC)
	
	options.register('era', 'era2018',...)   [options are 'era2016', 'era2017', 'era2018']

	process = cms.Process("MiniAnalysis", eras.Run2_2018)  [options are eras.Run2_2016, eras.Run2_2017, eras.Run2_2018]

	options.register('inputFile',...) [input file names, if not using crab]

	options.register('outFilename',) [output file name]

-------------------------------------------------------------------------------------------------------------
Run a macro to apply more cuts, and write a reduced output ntuple for use with fitting code
(the list of input files should be defined in Blah.h)
-------------------------------------------------------------------------------------------------------------

	cd TopLJets2015/TopAnalysis/test

	root -l Blah.C 

	[0] Blah b

	[1] b.Loop()

-------------------------------------------------------------------------------------------------------------
Description of selections applied (hopefully JetMET-like)
-------------------------------------------------------------------------------------------------------------

###In the analyzer

      - Single muon trigger

      - at least 1 loose muon with pT>53 GeV and |eta|<2.1

      - at least 1 AK4 jet with pT>30 GeV, |eta|<2.4, passing b-tagging (DeepCSV<0.4168)

      - MET > 40 GeV

###In the Blah.C macro

      - AK8 CHS pruned jet with pT>200GeV

      - DeltaR between the AK8 jet and the b-jet between 0.8 and 2.0

      - DeltaR between the muon and the b-jet >=0.3

      - Leptonic W pT (reconstructed from muon+MET) > 200 GeV

      - DeltaR between the muon and the AK8 jet > 1.570

      - Delta phi between the AK8 jet and MET > 2.09

      - tau21ddt < =0.75 to pass the W-tagging, tau21ddt > 0.75 to fail the W-tagging