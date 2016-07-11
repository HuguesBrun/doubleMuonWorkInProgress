# doubleMuonWorkInProgress
#do the fit of single mu17
cmsRun fitMuonTriggerNew_Mu17eff_data.py  lateData  //(or earlyData, there's some bugs in earlyData)
#do clean pair for mu17mu8 eg.
root -b -q -l  /afs/cern.ch/user/a/agrebeny/eos/cms/store/group/phys_smp/VJets/Bonzai13TeVoutput/tmp/test_WithWeights_new_Lumi.root cleanPairs.cxx++  
#use the micro to get the eff of doubleMuon trigger
cmsRun fitMuonTriggerNew_Mu17Mu8_data.py lateData EffMu17Mu8nodz //(#IDS = ["EffMu17Mu8nodz","EffMu17TkMu8nodz","pathOrnodz",]
#IDS = ["EffMu17Mu8","EffMu17TkMu8","pathOr",])

