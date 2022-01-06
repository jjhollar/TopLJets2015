#define Blah_cxx
#include "Blah.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Blah::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Blah.C
//      root> Blah t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Int_t nent = fChain->GetEntries();

   std::cout << "Entries = " << nent << std::endl;

   TLorentzVector mu, met, nu, bjet, fatjet, wlep, whad, genak8jet; 

   TH1F *h1 = new TH1F("h1","h1",40,0,200);
   TH1F *h2 = new TH1F("h2","h2",40,0,200);

   float SelectedJet_tau21_ddt, SelectedJet_mass,SelectedJet_pt,dr_LepJet,dphi_MetJet;
   int HLT_Mu50, genmatchedAK8;

   TFile *fx = new TFile("WTaggingSkim_SingleMu_2018CABCD.root","RECREATE");
   TTree *mytree = new TTree("mytree","Example fitter tree");
   mytree->Branch("SelectedJet_tau21_ddt",&SelectedJet_tau21_ddt,"SelectedJet_tau21_ddt/F");
   mytree->Branch("SelectedJet_mass",&SelectedJet_mass,"SelectedJet_mass/F");
   mytree->Branch("SelectedJet_pt",&SelectedJet_pt,"SelectedJet_pt/F");
   mytree->Branch("genmatchedAK8",&genmatchedAK8,"genmatchedAK8/I");
   mytree->Branch("dr_LepJet",&dr_LepJet,"dr_LepJet/F");
   mytree->Branch("dphi_MetJet",&dphi_MetJet,"dphi_MetJet/F");
   mytree->Branch("HLT_Mu50",&HLT_Mu50,"HLT_Mu50/I");

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(jentry%1000 == 0)
	std::cout << "Entry " << jentry << "/" << nent << std::endl;

      int ngoodak4bjet = 0;
      float deltarbfat = -999.;
      float deltarbmu = 999.;

      met.SetPtEtaPhiM(met_pt,0,met_phi,met_pt);

      if(l_id[0] == 13 && (l_relIso[0] < 0.1))
	mu.SetPtEtaPhiM(l_pt[0], l_eta[0], l_phi[0],l_mass[0]);

      if(j8_pt[0]<=200)
	continue;

      fatjet.SetPtEtaPhiM(j8_pt[0],j8_eta[0],j8_phi[0],j8_mass[0]);

      for(Int_t b = 0; b < nj; b++)
	{
	  if((j_deepcsv[b] > 0.4168) && (j_pt[b] > 30) && (fabs(j_eta[b])< 2.4))
	    {
	      bjet.SetPtEtaPhiM(j_pt[b],j_eta[b],j_phi[b],j_mass[b]);
	      deltarbfat = DeltaR(fatjet,bjet);
	      if(deltarbfat >= 2.0 || deltarbfat < 0.8)
		continue;
	      deltarbmu = DeltaR(mu,bjet);
	      if(deltarbmu < 0.3)
		continue;
	      ngoodak4bjet++;
	    }
	}

      float neutrinopz = 0.0;
      float met_px = met_pt * TMath::Cos(met_phi);
      float met_py = met_pt * TMath::Sin(met_phi);
      genmatchedAK8 = 0;

      neutrinopz = recoverNeutrinoPz(mu, met);
      nu.SetPxPyPzE(met_px,met_py,neutrinopz,TMath::Sqrt(met_px*met_px + met_py*met_py + neutrinopz*neutrinopz)); 
      wlep = mu+nu;

      if(wlep.Pt()<=200)
	continue;

      float rhoprime1 = TMath::Log(j8_mass[0] * j8_mass[0] / j8_pt[0]);
      float taut21ddt1 = ((j8_tau2[0] / j8_tau1[0])) - (-0.082 * rhoprime1);
      float deltarlepjet = DeltaR(mu,fatjet);
      dphi_MetJet = fatjet.DeltaPhi(nu);
      HLT_Mu50 = 1;
      SelectedJet_mass = j8_mass[0];
      SelectedJet_tau21_ddt = taut21ddt1;
      SelectedJet_pt = j8_pt[0];
      dr_LepJet = deltarlepjet;

      if(fabs(dr_LepJet) <= 1.570)
	continue;
      if(fabs(dphi_MetJet) <= 2.09)
	continue;
      
      for(Int_t gj = 0; gj < ng; gj++)
	{
	  genak8jet.SetPtEtaPhiM(g_pt[gj],g_eta[gj],g_phi[gj],g_m[gj]);
	  float drgen = DeltaR(fatjet,genak8jet);
	  if(drgen < 0.8) 
	    genmatchedAK8 = 1;
	}

      if(taut21ddt1 <= 0.75)
	h1->Fill(j8_mass[0]);
      else
	h2->Fill(j8_mass[0]);

      mytree->Fill();
   }
   h1->Draw("e");
   h2->Draw("histsame");

   fx->cd();
   mytree->Write();
   fx->Close();

   /*
   TF1 *fa1 = new TF1("fa1","gaus(0)+pol3(3)",40,130);
   fa1->SetParameter(0,100);
   fa1->SetParameter(1,80);
   fa1->SetParameter(2,15);
   fa1->SetParameter(3,5);
   fa1->SetParameter(4,-1);

   fa1->SetParLimits(0,10,10000);
   fa1->SetParLimits(1,60,90);
   fa1->SetParLimits(2,1,20);
   fa1->SetParLimits(3,-10,10000);
   fa1->SetParLimits(4,-500,500);
   
   h2->Fit(fa1,"L","",40,130);
   fa1->Draw("same");

   TF1 *fb1 = new TF1("fb1","pol3(0)",40,130);
   fb1->SetParameter(0,fa1->GetParameter(3));
   fb1->SetParameter(1,fa1->GetParameter(4));
   fb1->SetParameter(2,fa1->GetParameter(5));
   fb1->SetParameter(3,fa1->GetParameter(6));
   fb1->SetLineColor(4); fb1->SetLineStyle(2); fb1->Draw("same");

   TF1 *fc1 = new TF1("fc1","gaus(0)",40,130);
   fc1->SetParameter(0,fa1->GetParameter(0));
   fc1->SetParameter(1,fa1->GetParameter(1));
   fc1->SetParameter(2,fa1->GetParameter(2));
   fc1->SetLineColor(2); fc1->SetLineStyle(2); fc1->Draw("same");
   */

}

float Blah::recoverNeutrinoPz(TLorentzVector lep, TLorentzVector met)
{
  float pz = 0.;
  float a = 80.4*80.4 - lep.M()*lep.M() + 2.*lep.Px()*met.Px() + 2.*lep.Py()*met.Py();
  float A = 4.*( lep.E()*lep.E() - lep.Pz()*lep.Pz() );
  float B = -4.*a*lep.Pz();
  float C = 4*(lep.E()*lep.E()) * (met.Px()*met.Px()  + met.Py()*met.Py()) - a*a;
  float D = B*B - 4*A*C;
  // If there are real solutions, use the one with lowest pz                                            
  if (D >= 0.)
    {
      float s1 = (-B+TMath::Sqrt(D))/(2*A);
      float s2 = (-B-TMath::Sqrt(D))/(2*A);
      if(fabs(s1) < fabs(s2))
	  pz = s1;
      else
	s2;
    }
  // Otherwise, use real part                                                                           
  else
    pz = -B/(2*A);

  return pz;
}

float Blah::DeltaR(TLorentzVector p1,TLorentzVector p2)
{
  float dR = sqrt((p1.Eta()-p2.Eta())*(p1.Eta()-p2.Eta()) + (p1.Phi()-p2.Phi())*(p1.Phi()-p2.Phi()));
  return dR;
}

