-------------------------------------------------------------------------------------------------------------
Setup the ntuple-maker, modified to include AK8 CHS-pruned jets as used in SMP-21-014
-------------------------------------------------------------------------------------------------------------
cmsrel CMSSW_10_6_17
cd CMSSW_10_6_17/src
cmsenv
git cms-init

#EGM id
git cms-merge-topic jainshilpi:ULV1_backport10616_forUsers
git clone https://github.com/jainshilpi/EgammaPostRecoTools.git -b ULV0 
mv EgammaPostRecoTools/python/EgammaPostRecoTools.py RecoEgamma/EgammaTools/python/.
git clone https://github.com/jainshilpi/EgammaAnalysis-ElectronTools.git -b UL2017SSV2 EgammaAnalysis/ElectronTools/data/
git cms-addpkg EgammaAnalysis/ElectronTools
scram b -j 8

#B-fragmentation analyzer
mkdir TopQuarkAnalysis 
cd TopQuarkAnalysis
git clone -b 94x https://gitlab.cern.ch/psilva/BFragmentationAnalyzer.git
scram b -j 8
cd -

#Jet toolbox stuff 
cd $CMSSW_BASE/src
git clone git@github.com:cms-jet/JetToolbox.git JMEAnalysis/JetToolbox -b jetToolbox_102X_v3
cp /afs/cern.ch/work/k/kshcheli/public/jonathan/toolboxstuff JMEAnalysis/JetToolbox/python/jetToolbox_cff.py

#This package
cd $CMSSW_BASE/src
git clone git@github.com:jjhollar/TopLJets2015.git -b 106_protonreco

scram b -j8

-------------------------------------------------------------------------------------------------------------
Run the ntuple-maker, modified to include AK8 CHS-pruned jets as used in SMP-21-014
-------------------------------------------------------------------------------------------------------------
cd TopLJets2015/TopAnalysis/test
cmsRun runMiniAnalyzer_cfg.py
