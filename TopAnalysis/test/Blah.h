//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 29 09:17:19 2021 by ROOT version 6.14/09
// from TChain analysis/data/
//////////////////////////////////////////////////////////

#ifndef Blah_h
#define Blah_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Blah {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Bool_t          isData;
   UInt_t          run;
   ULong64_t       event;
   UInt_t          lumi;
   Float_t         beamXangle;
   Float_t         instLumi;
   Int_t           scan_mass;
   Float_t         scan_rho;
   Int_t           scan_coup;
   Int_t           g_pu;
   Int_t           g_putrue;
   Int_t           g_id1;
   Int_t           g_id2;
   Float_t         g_x1;
   Float_t         g_x2;
   Float_t         g_qscale;
   Int_t           g_nw;
   Float_t         g_w[1];   //[g_nw]
   Int_t           ng;
   Int_t           g_id[1];   //[ng]
   Int_t           g_bid[1];   //[ng]
   Int_t           g_tagCtrs[1];   //[ng]
   Bool_t          g_isSemiLepBhad[1];   //[ng]
   Float_t         g_xb[1];   //[ng]
   Float_t         g_xbp[1];   //[ng]
   Float_t         g_pt[1];   //[ng]
   Float_t         g_eta[1];   //[ng]
   Float_t         g_phi[1];   //[ng]
   Float_t         g_m[1];   //[ng]
   Int_t           g_nchPV;
   Float_t         g_sumPVChPt;
   Float_t         g_sumPVChPz;
   Float_t         g_sumPVChHt;
   Int_t           ngtop;
   Int_t           gtop_id[1];   //[ngtop]
   Float_t         gtop_pt[1];   //[ngtop]
   Float_t         gtop_eta[1];   //[ngtop]
   Float_t         gtop_phi[1];   //[ngtop]
   Float_t         gtop_m[1];   //[ngtop]
   Int_t           nvtx;
   Float_t         rho;
   Int_t           triggerBits;
   Int_t           addTriggerBits;
   Int_t           zeroBiasPS;
   Int_t           nl;
   Bool_t          l_isPromptFinalState[5];   //[nl]
   Bool_t          l_isDirectPromptTauDecayProductFinalState[5];   //[nl]
   Int_t           l_id[5];   //[nl]
   Int_t           l_pid[5];   //[nl]
   Int_t           l_g[5];   //[nl]
   Int_t           l_charge[5];   //[nl]
   Float_t         l_mva[5];   //[nl]
   Float_t         l_mvaCats[5];   //[nl]
   Float_t         l_highpt[5];   //[nl]
   Float_t         l_pt[5];   //[nl]
   Float_t         l_eta[5];   //[nl]
   Float_t         l_phi[5];   //[nl]
   Float_t         l_mass[5];   //[nl]
   Float_t         l_scaleUnc1[5];   //[nl]
   Float_t         l_scaleUnc2[5];   //[nl]
   Float_t         l_scaleUnc3[5];   //[nl]
   Float_t         l_scaleUnc4[5];   //[nl]
   Float_t         l_scaleUnc5[5];   //[nl]
   Float_t         l_scaleUnc6[5];   //[nl]
   Float_t         l_scaleUnc7[5];   //[nl]
   Float_t         l_chargedHadronIso[5];   //[nl]
   Float_t         l_miniIso[5];   //[nl]
   Float_t         l_relIso[5];   //[nl]
   Float_t         l_ip3d[5];   //[nl]
   Float_t         l_ip3dsig[5];   //[nl]
   Int_t           ngamma;
   Bool_t          gamma_isPromptFinalState[5];   //[ngamma]
   Int_t           gamma_pid[5];   //[ngamma]
   Int_t           gamma_idFlags[5];   //[ngamma]
   Int_t           gamma_g[5];   //[ngamma]
   Float_t         gamma_mva[5];   //[ngamma]
   Float_t         gamma_mvaCats[5];   //[ngamma]
   Float_t         gamma_pt[5];   //[ngamma]
   Float_t         gamma_eta[5];   //[ngamma]
   Float_t         gamma_phi[5];   //[ngamma]
   Float_t         gamma_scaleUnc1[5];   //[ngamma]
   Float_t         gamma_scaleUnc2[5];   //[ngamma]
   Float_t         gamma_scaleUnc3[5];   //[ngamma]
   Float_t         gamma_scaleUnc4[5];   //[ngamma]
   Float_t         gamma_scaleUnc5[5];   //[ngamma]
   Float_t         gamma_scaleUnc6[5];   //[ngamma]
   Float_t         gamma_scaleUnc7[5];   //[ngamma]
   Float_t         gamma_chargedHadronIso[5];   //[ngamma]
   Float_t         gamma_neutralHadronIso[5];   //[ngamma]
   Float_t         gamma_photonIso[5];   //[ngamma]
   Float_t         gamma_hoe[5];   //[ngamma]
   Float_t         gamma_r9[5];   //[ngamma]
   Float_t         gamma_sieie[5];   //[ngamma]
   Int_t           nj;
   Int_t           j_g[19];   //[nj]
   Float_t         j_area[19];   //[nj]
   Float_t         j_jerUp[19];   //[nj]
   Float_t         j_jerDn[19];   //[nj]
   Float_t         j_jecUp0[19];   //[nj]
   Float_t         j_jecDn0[19];   //[nj]
   Float_t         j_jecUp1[19];   //[nj]
   Float_t         j_jecDn1[19];   //[nj]
   Float_t         j_jecUp2[19];   //[nj]
   Float_t         j_jecDn2[19];   //[nj]
   Float_t         j_jecUp3[19];   //[nj]
   Float_t         j_jecDn3[19];   //[nj]
   Float_t         j_jecUp4[19];   //[nj]
   Float_t         j_jecDn4[19];   //[nj]
   Float_t         j_jecUp5[19];   //[nj]
   Float_t         j_jecDn5[19];   //[nj]
   Float_t         j_jecUp6[19];   //[nj]
   Float_t         j_jecDn6[19];   //[nj]
   Float_t         j_jecUp7[19];   //[nj]
   Float_t         j_jecDn7[19];   //[nj]
   Float_t         j_jecUp8[19];   //[nj]
   Float_t         j_jecDn8[19];   //[nj]
   Float_t         j_jecUp9[19];   //[nj]
   Float_t         j_jecDn9[19];   //[nj]
   Float_t         j_jecUp10[19];   //[nj]
   Float_t         j_jecDn10[19];   //[nj]
   Float_t         j_jecUp11[19];   //[nj]
   Float_t         j_jecDn11[19];   //[nj]
   Float_t         j_jecUp12[19];   //[nj]
   Float_t         j_jecDn12[19];   //[nj]
   Float_t         j_jecUp13[19];   //[nj]
   Float_t         j_jecDn13[19];   //[nj]
   Float_t         j_jecUp14[19];   //[nj]
   Float_t         j_jecDn14[19];   //[nj]
   Float_t         j_jecUp15[19];   //[nj]
   Float_t         j_jecDn15[19];   //[nj]
   Float_t         j_jecUp16[19];   //[nj]
   Float_t         j_jecDn16[19];   //[nj]
   Float_t         j_jecUp17[19];   //[nj]
   Float_t         j_jecDn17[19];   //[nj]
   Float_t         j_jecUp18[19];   //[nj]
   Float_t         j_jecDn18[19];   //[nj]
   Float_t         j_jecUp19[19];   //[nj]
   Float_t         j_jecDn19[19];   //[nj]
   Float_t         j_jecUp20[19];   //[nj]
   Float_t         j_jecDn20[19];   //[nj]
   Float_t         j_jecUp21[19];   //[nj]
   Float_t         j_jecDn21[19];   //[nj]
   Float_t         j_jecUp22[19];   //[nj]
   Float_t         j_jecDn22[19];   //[nj]
   Float_t         j_jecUp23[19];   //[nj]
   Float_t         j_jecDn23[19];   //[nj]
   Float_t         j_jecUp24[19];   //[nj]
   Float_t         j_jecDn24[19];   //[nj]
   Float_t         j_jecUp25[19];   //[nj]
   Float_t         j_jecDn25[19];   //[nj]
   Float_t         j_jecUp26[19];   //[nj]
   Float_t         j_jecDn26[19];   //[nj]
   Float_t         j_jecUp27[19];   //[nj]
   Float_t         j_jecDn27[19];   //[nj]
   Float_t         j_jecUp28[19];   //[nj]
   Float_t         j_jecDn28[19];   //[nj]
   Float_t         j_rawsf[19];   //[nj]
   Float_t         j_pt[19];   //[nj]
   Float_t         j_eta[19];   //[nj]
   Float_t         j_phi[19];   //[nj]
   Float_t         j_mass[19];   //[nj]
   Float_t         j_pumva[19];   //[nj]
   Int_t           j_id[19];   //[nj]
   Float_t         j_csv[19];   //[nj]
   Bool_t          j_btag[19];   //[nj]
   Float_t         j_emf[19];   //[nj]
   Float_t         j_qg[19];   //[nj]
   Float_t         j_c2_00[19];   //[nj]
   Float_t         j_c2_02[19];   //[nj]
   Float_t         j_c2_05[19];   //[nj]
   Float_t         j_c2_10[19];   //[nj]
   Float_t         j_c2_20[19];   //[nj]
   Float_t         j_zg[19];   //[nj]
   Float_t         j_mult[19];   //[nj]
   Float_t         j_gaptd[19];   //[nj]
   Float_t         j_gawidth[19];   //[nj]
   Float_t         j_gathrust[19];   //[nj]
   Float_t         j_tau32[19];   //[nj]
   Float_t         j_tau21[19];   //[nj]
   Float_t         j_deepcsv[19];   //[nj]
   Float_t         j_probc[19];   //[nj]
   Float_t         j_probudsg[19];   //[nj]
   Float_t         j_probb[19];   //[nj]
   Float_t         j_probbb[19];   //[nj]
   Float_t         j_CvsL[19];   //[nj]
   Float_t         j_CvsB[19];   //[nj]
   Float_t         j_vtxpx[19];   //[nj]
   Float_t         j_vtxpy[19];   //[nj]
   Float_t         j_vtxpz[19];   //[nj]
   Float_t         j_vtxmass[19];   //[nj]
   Int_t           j_vtxNtracks[19];   //[nj]
   Float_t         j_vtx3DVal[19];   //[nj]
   Float_t         j_vtx3DSig[19];   //[nj]
   Int_t           j_flav[19];   //[nj]
   Int_t           j_hadflav[19];   //[nj]
   Int_t           j_pid[19];   //[nj]
   Int_t           nj8;
   Float_t         j8_pt[5];   //[nj8]
   Float_t         j8_eta[5];   //[nj8]
   Float_t         j8_phi[5];   //[nj8]
   Float_t         j8_mass[5];   //[nj8]
   Float_t         j8_tau1[5];   //[nj8]
   Float_t         j8_tau2[5];   //[nj8]
   Int_t           nchPV;
   Float_t         sumPVChPt;
   Float_t         sumPVChPz;
   Float_t         sumPVChHt;
   Int_t           nPFCands[8];
   Float_t         sumPFEn[8];
   Float_t         sumPFPz[8];
   Float_t         sumPFHt[8];
   Int_t           nPFChCands[8];
   Float_t         sumPFChEn[8];
   Float_t         sumPFChPz[8];
   Float_t         sumPFChHt[8];
   Float_t         met_pt;
   Float_t         met_phi;
   Float_t         met_sig;
   Float_t         met_ptShifted[14];
   Float_t         met_phiShifted[14];
   Int_t           met_filterBits;
   Short_t         nppstrk;
   Short_t         ppstrk_pot[20];   //[nppstrk]
   Float_t         ppstrk_x[20];   //[nppstrk]
   Float_t         ppstrk_y[20];   //[nppstrk]
   Float_t         ppstrk_xUnc[20];   //[nppstrk]
   Float_t         ppstrk_yUnc[20];   //[nppstrk]
   Float_t         ppstrk_tx[20];   //[nppstrk]
   Float_t         ppstrk_ty[20];   //[nppstrk]
   Float_t         ppstrk_txUnc[20];   //[nppstrk]
   Float_t         ppstrk_tyUnc[20];   //[nppstrk]
   Short_t         ppstrk_recoInfo[20];   //[nppstrk]
   Float_t         ppstrk_chisqnorm[20];   //[nppstrk]
   Float_t         ppstrk_t[20];   //[nppstrk]
   Float_t         ppstrk_tUnc[20];   //[nppstrk]
   Short_t         nfwdtrk;
   Short_t         fwdtrk_pot[1];   //[nfwdtrk]
   Short_t         fwdtrk_method[1];   //[nfwdtrk]
   Short_t         fwdtrk_recoInfo[1];   //[nfwdtrk]
   Float_t         fwdtrk_thetax[1];   //[nfwdtrk]
   Float_t         fwdtrk_thetay[1];   //[nfwdtrk]
   Float_t         fwdtrk_x[1];   //[nfwdtrk]
   Float_t         fwdtrk_y[1];   //[nfwdtrk]
   Float_t         fwdtrk_tx[1];   //[nfwdtrk]
   Float_t         fwdtrk_ty[1];   //[nfwdtrk]
   Float_t         fwdtrk_vx[1];   //[nfwdtrk]
   Float_t         fwdtrk_vy[1];   //[nfwdtrk]
   Float_t         fwdtrk_vz[1];   //[nfwdtrk]
   Float_t         fwdtrk_time[1];   //[nfwdtrk]
   Float_t         fwdtrk_timeError[1];   //[nfwdtrk]
   Float_t         fwdtrk_chisqnorm[1];   //[nfwdtrk]
   Float_t         fwdtrk_xi[1];   //[nfwdtrk]
   Float_t         fwdtrk_xiError[1];   //[nfwdtrk]
   Float_t         fwdtrk_t[1];   //[nfwdtrk]
   Int_t           nrawmu;
   Short_t         rawmu_pt[20];   //[nrawmu]
   Short_t         rawmu_eta[20];   //[nrawmu]
   Short_t         rawmu_phi[20];   //[nrawmu]
   Int_t           rawmu_pid[20];   //[nrawmu]

   // List of branches
   TBranch        *b_isData;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_beamXangle;   //!
   TBranch        *b_instLumi;   //!
   TBranch        *b_scan_mass;   //!
   TBranch        *b_scan_rho;   //!
   TBranch        *b_scan_coup;   //!
   TBranch        *b_g_pu;   //!
   TBranch        *b_g_putrue;   //!
   TBranch        *b_g_id1;   //!
   TBranch        *b_g_id2;   //!
   TBranch        *b_g_x1;   //!
   TBranch        *b_g_x2;   //!
   TBranch        *b_g_qscale;   //!
   TBranch        *b_g_nw;   //!
   TBranch        *b_g_w;   //!
   TBranch        *b_ng;   //!
   TBranch        *b_g_id;   //!
   TBranch        *b_g_bid;   //!
   TBranch        *b_g_tagCtrs;   //!
   TBranch        *b_g_isSemiLepBhad;   //!
   TBranch        *b_g_xb;   //!
   TBranch        *b_g_xbp;   //!
   TBranch        *b_g_pt;   //!
   TBranch        *b_g_eta;   //!
   TBranch        *b_g_phi;   //!
   TBranch        *b_g_m;   //!
   TBranch        *b_g_nchPV;   //!
   TBranch        *b_g_sumPVChPt;   //!
   TBranch        *b_g_sumPVChPz;   //!
   TBranch        *b_g_sumPVChHt;   //!
   TBranch        *b_ngtop;   //!
   TBranch        *b_gtop_id;   //!
   TBranch        *b_gtop_pt;   //!
   TBranch        *b_gtop_eta;   //!
   TBranch        *b_gtop_phi;   //!
   TBranch        *b_gtop_m;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_triggerBits;   //!
   TBranch        *b_addTriggerBits;   //!
   TBranch        *b_zeroBiasPS;   //!
   TBranch        *b_nl;   //!
   TBranch        *b_l_isPromptFinalState;   //!
   TBranch        *b_l_isDirectPromptTauDecayProductFinalState;   //!
   TBranch        *b_l_id;   //!
   TBranch        *b_l_pid;   //!
   TBranch        *b_l_g;   //!
   TBranch        *b_l_charge;   //!
   TBranch        *b_l_mva;   //!
   TBranch        *b_l_mvaCats;   //!
   TBranch        *b_l_highpt;   //!
   TBranch        *b_l_pt;   //!
   TBranch        *b_l_eta;   //!
   TBranch        *b_l_phi;   //!
   TBranch        *b_l_mass;   //!
   TBranch        *b_l_scaleUnc1;   //!
   TBranch        *b_l_scaleUnc2;   //!
   TBranch        *b_l_scaleUnc3;   //!
   TBranch        *b_l_scaleUnc4;   //!
   TBranch        *b_l_scaleUnc5;   //!
   TBranch        *b_l_scaleUnc6;   //!
   TBranch        *b_l_scaleUnc7;   //!
   TBranch        *b_l_chargedHadronIso;   //!
   TBranch        *b_l_miniIso;   //!
   TBranch        *b_l_relIso;   //!
   TBranch        *b_l_ip3d;   //!
   TBranch        *b_l_ip3dsig;   //!
   TBranch        *b_ngamma;   //!
   TBranch        *b_gamma_isPromptFinalState;   //!
   TBranch        *b_gamma_pid;   //!
   TBranch        *b_gamma_idFlags;   //!
   TBranch        *b_gamma_g;   //!
   TBranch        *b_gamma_mva;   //!
   TBranch        *b_gamma_mvaCats;   //!
   TBranch        *b_gamma_pt;   //!
   TBranch        *b_gamma_eta;   //!
   TBranch        *b_gamma_phi;   //!
   TBranch        *b_gamma_scaleUnc1;   //!
   TBranch        *b_gamma_scaleUnc2;   //!
   TBranch        *b_gamma_scaleUnc3;   //!
   TBranch        *b_gamma_scaleUnc4;   //!
   TBranch        *b_gamma_scaleUnc5;   //!
   TBranch        *b_gamma_scaleUnc6;   //!
   TBranch        *b_gamma_scaleUnc7;   //!
   TBranch        *b_gamma_chargedHadronIso;   //!
   TBranch        *b_gamma_neutralHadronIso;   //!
   TBranch        *b_gamma_photonIso;   //!
   TBranch        *b_gamma_hoe;   //!
   TBranch        *b_gamma_r9;   //!
   TBranch        *b_gamma_sieie;   //!
   TBranch        *b_nj;   //!
   TBranch        *b_j_g;   //!
   TBranch        *b_j_area;   //!
   TBranch        *b_j_jerUp;   //!
   TBranch        *b_j_jerDn;   //!
   TBranch        *b_j_jecUp0;   //!
   TBranch        *b_j_jecDn0;   //!
   TBranch        *b_j_jecUp1;   //!
   TBranch        *b_j_jecDn1;   //!
   TBranch        *b_j_jecUp2;   //!
   TBranch        *b_j_jecDn2;   //!
   TBranch        *b_j_jecUp3;   //!
   TBranch        *b_j_jecDn3;   //!
   TBranch        *b_j_jecUp4;   //!
   TBranch        *b_j_jecDn4;   //!
   TBranch        *b_j_jecUp5;   //!
   TBranch        *b_j_jecDn5;   //!
   TBranch        *b_j_jecUp6;   //!
   TBranch        *b_j_jecDn6;   //!
   TBranch        *b_j_jecUp7;   //!
   TBranch        *b_j_jecDn7;   //!
   TBranch        *b_j_jecUp8;   //!
   TBranch        *b_j_jecDn8;   //!
   TBranch        *b_j_jecUp9;   //!
   TBranch        *b_j_jecDn9;   //!
   TBranch        *b_j_jecUp10;   //!
   TBranch        *b_j_jecDn10;   //!
   TBranch        *b_j_jecUp11;   //!
   TBranch        *b_j_jecDn11;   //!
   TBranch        *b_j_jecUp12;   //!
   TBranch        *b_j_jecDn12;   //!
   TBranch        *b_j_jecUp13;   //!
   TBranch        *b_j_jecDn13;   //!
   TBranch        *b_j_jecUp14;   //!
   TBranch        *b_j_jecDn14;   //!
   TBranch        *b_j_jecUp15;   //!
   TBranch        *b_j_jecDn15;   //!
   TBranch        *b_j_jecUp16;   //!
   TBranch        *b_j_jecDn16;   //!
   TBranch        *b_j_jecUp17;   //!
   TBranch        *b_j_jecDn17;   //!
   TBranch        *b_j_jecUp18;   //!
   TBranch        *b_j_jecDn18;   //!
   TBranch        *b_j_jecUp19;   //!
   TBranch        *b_j_jecDn19;   //!
   TBranch        *b_j_jecUp20;   //!
   TBranch        *b_j_jecDn20;   //!
   TBranch        *b_j_jecUp21;   //!
   TBranch        *b_j_jecDn21;   //!
   TBranch        *b_j_jecUp22;   //!
   TBranch        *b_j_jecDn22;   //!
   TBranch        *b_j_jecUp23;   //!
   TBranch        *b_j_jecDn23;   //!
   TBranch        *b_j_jecUp24;   //!
   TBranch        *b_j_jecDn24;   //!
   TBranch        *b_j_jecUp25;   //!
   TBranch        *b_j_jecDn25;   //!
   TBranch        *b_j_jecUp26;   //!
   TBranch        *b_j_jecDn26;   //!
   TBranch        *b_j_jecUp27;   //!
   TBranch        *b_j_jecDn27;   //!
   TBranch        *b_j_jecUp28;   //!
   TBranch        *b_j_jecDn28;   //!
   TBranch        *b_j_rawsf;   //!
   TBranch        *b_j_pt;   //!
   TBranch        *b_j_eta;   //!
   TBranch        *b_j_phi;   //!
   TBranch        *b_j_mass;   //!
   TBranch        *b_j_pumva;   //!
   TBranch        *b_j_id;   //!
   TBranch        *b_j_csv;   //!
   TBranch        *b_j_btag;   //!
   TBranch        *b_j_emf;   //!
   TBranch        *b_j_qg;   //!
   TBranch        *b_j_c2_00;   //!
   TBranch        *b_j_c2_02;   //!
   TBranch        *b_j_c2_05;   //!
   TBranch        *b_j_c2_10;   //!
   TBranch        *b_j_c2_20;   //!
   TBranch        *b_j_zg;   //!
   TBranch        *b_j_mult;   //!
   TBranch        *b_j_gaptd;   //!
   TBranch        *b_j_gawidth;   //!
   TBranch        *b_j_gathrust;   //!
   TBranch        *b_j_tau32;   //!
   TBranch        *b_j_tau21;   //!
   TBranch        *b_j_deepcsv;   //!
   TBranch        *b_j_probc;   //!
   TBranch        *b_j_probudsg;   //!
   TBranch        *b_j_probb;   //!
   TBranch        *b_j_probbb;   //!
   TBranch        *b_j_CvsL;   //!
   TBranch        *b_j_CvsB;   //!
   TBranch        *b_j_vtxpx;   //!
   TBranch        *b_j_vtxpy;   //!
   TBranch        *b_j_vtxpz;   //!
   TBranch        *b_j_vtxmass;   //!
   TBranch        *b_j_vtxNtracks;   //!
   TBranch        *b_j_vtx3DVal;   //!
   TBranch        *b_j_vtx3DSig;   //!
   TBranch        *b_j_flav;   //!
   TBranch        *b_j_hadflav;   //!
   TBranch        *b_j_pid;   //!
   TBranch        *b_nj8;   //!
   TBranch        *b_j8_pt;   //!
   TBranch        *b_j8_eta;   //!
   TBranch        *b_j8_phi;   //!
   TBranch        *b_j8_mass;   //!
   TBranch        *b_j8_tau1;   //!
   TBranch        *b_j8_tau2;   //!
   TBranch        *b_nchPV;   //!
   TBranch        *b_sumPVChPt;   //!
   TBranch        *b_sumPVChPz;   //!
   TBranch        *b_sumPVChHt;   //!
   TBranch        *b_nPFCands;   //!
   TBranch        *b_sumPFEn;   //!
   TBranch        *b_sumPFPz;   //!
   TBranch        *b_sumPFHt;   //!
   TBranch        *b_nPFChCands;   //!
   TBranch        *b_sumPFChEn;   //!
   TBranch        *b_sumPFChPz;   //!
   TBranch        *b_sumPFChHt;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_sig;   //!
   TBranch        *b_met_ptShifted;   //!
   TBranch        *b_met_phiShifted;   //!
   TBranch        *b_met_filterBits;   //!
   TBranch        *b_nppstrk;   //!
   TBranch        *b_ppstrk_pot;   //!
   TBranch        *b_ppstrk_x;   //!
   TBranch        *b_ppstrk_y;   //!
   TBranch        *b_ppstrk_xUnc;   //!
   TBranch        *b_ppstrk_yUnc;   //!
   TBranch        *b_ppstrk_tx;   //!
   TBranch        *b_ppstrk_ty;   //!
   TBranch        *b_ppstrk_txUnc;   //!
   TBranch        *b_ppstrk_tyUnc;   //!
   TBranch        *b_ppstrk_recoInfo;   //!
   TBranch        *b_ppstrk_chisqnorm;   //!
   TBranch        *b_ppstrk_t;   //!
   TBranch        *b_ppstrk_tUnc;   //!
   TBranch        *b_nfwdtrk;   //!
   TBranch        *b_fwdtrk_pot;   //!
   TBranch        *b_fwdtrk_method;   //!
   TBranch        *b_fwdtrk_recoInfo;   //!
   TBranch        *b_fwdtrk_thetax;   //!
   TBranch        *b_fwdtrk_thetay;   //!
   TBranch        *b_fwdtrk_x;   //!
   TBranch        *b_fwdtrk_y;   //!
   TBranch        *b_fwdtrk_tx;   //!
   TBranch        *b_fwdtrk_ty;   //!
   TBranch        *b_fwdtrk_vx;   //!
   TBranch        *b_fwdtrk_vy;   //!
   TBranch        *b_fwdtrk_vz;   //!
   TBranch        *b_fwdtrk_time;   //!
   TBranch        *b_fwdtrk_timeError;   //!
   TBranch        *b_fwdtrk_chisqnorm;   //!
   TBranch        *b_fwdtrk_xi;   //!
   TBranch        *b_fwdtrk_xiError;   //!
   TBranch        *b_fwdtrk_t;   //!
   TBranch        *b_nrawmu;   //!
   TBranch        *b_rawmu_pt;   //!
   TBranch        *b_rawmu_eta;   //!
   TBranch        *b_rawmu_phi;   //!
   TBranch        *b_rawmu_pid;   //!

   Blah(TTree *tree=0);
   virtual ~Blah();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual float    recoverNeutrinoPz(TLorentzVector lep, TLorentzVector met);
   virtual float    DeltaR(TLorentzVector p1,TLorentzVector p2);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Blah_cxx
Blah::Blah(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("analysis/data",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("analysis/data","");
      chain->Add("/eos/cms/store/user/jjhollar/WTaggingScaleFactors_SingleMu2018/SingleMuon/WTaggingScaleFactors_SingleMu2018A/WTaggingScaleFactors_SingleMu2018A_merge.root/analysis/data");
      chain->Add("/eos/cms/store/user/jjhollar/WTaggingScaleFactors_SingleMu2018/SingleMuon/WTaggingScaleFactors_SingleMu2018B/WTaggingScaleFactors_SingleMu2018B_merge.root/analysis/data");
      chain->Add("/eos/cms/store/user/jjhollar/WTaggingScaleFactors_SingleMu2018/SingleMuon/WTaggingScaleFactors_SingleMu2018C/WTaggingScaleFactors_SingleMu2018C_merge.root/analysis/data");
      chain->Add("/eos/cms/store/user/jjhollar/WTaggingScaleFactors_SingleMu2018/SingleMuon/WTaggingScaleFactors_SingleMu2018/WTaggingScaleFactors_SingleMu2018D_merge.root/analysis/data");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

Blah::~Blah()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Blah::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Blah::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Blah::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("beamXangle", &beamXangle, &b_beamXangle);
   fChain->SetBranchAddress("instLumi", &instLumi, &b_instLumi);
   fChain->SetBranchAddress("scan_mass", &scan_mass, &b_scan_mass);
   fChain->SetBranchAddress("scan_rho", &scan_rho, &b_scan_rho);
   fChain->SetBranchAddress("scan_coup", &scan_coup, &b_scan_coup);
   fChain->SetBranchAddress("g_pu", &g_pu, &b_g_pu);
   fChain->SetBranchAddress("g_putrue", &g_putrue, &b_g_putrue);
   fChain->SetBranchAddress("g_id1", &g_id1, &b_g_id1);
   fChain->SetBranchAddress("g_id2", &g_id2, &b_g_id2);
   fChain->SetBranchAddress("g_x1", &g_x1, &b_g_x1);
   fChain->SetBranchAddress("g_x2", &g_x2, &b_g_x2);
   fChain->SetBranchAddress("g_qscale", &g_qscale, &b_g_qscale);
   fChain->SetBranchAddress("g_nw", &g_nw, &b_g_nw);
   fChain->SetBranchAddress("g_w", &g_w, &b_g_w);
   fChain->SetBranchAddress("ng", &ng, &b_ng);
   fChain->SetBranchAddress("g_id", &g_id, &b_g_id);
   fChain->SetBranchAddress("g_bid", &g_bid, &b_g_bid);
   fChain->SetBranchAddress("g_tagCtrs", &g_tagCtrs, &b_g_tagCtrs);
   fChain->SetBranchAddress("g_isSemiLepBhad", &g_isSemiLepBhad, &b_g_isSemiLepBhad);
   fChain->SetBranchAddress("g_xb", &g_xb, &b_g_xb);
   fChain->SetBranchAddress("g_xbp", &g_xbp, &b_g_xbp);
   fChain->SetBranchAddress("g_pt", &g_pt, &b_g_pt);
   fChain->SetBranchAddress("g_eta", &g_eta, &b_g_eta);
   fChain->SetBranchAddress("g_phi", &g_phi, &b_g_phi);
   fChain->SetBranchAddress("g_m", &g_m, &b_g_m);
   fChain->SetBranchAddress("g_nchPV", &g_nchPV, &b_g_nchPV);
   fChain->SetBranchAddress("g_sumPVChPt", &g_sumPVChPt, &b_g_sumPVChPt);
   fChain->SetBranchAddress("g_sumPVChPz", &g_sumPVChPz, &b_g_sumPVChPz);
   fChain->SetBranchAddress("g_sumPVChHt", &g_sumPVChHt, &b_g_sumPVChHt);
   fChain->SetBranchAddress("ngtop", &ngtop, &b_ngtop);
   fChain->SetBranchAddress("gtop_id", &gtop_id, &b_gtop_id);
   fChain->SetBranchAddress("gtop_pt", &gtop_pt, &b_gtop_pt);
   fChain->SetBranchAddress("gtop_eta", &gtop_eta, &b_gtop_eta);
   fChain->SetBranchAddress("gtop_phi", &gtop_phi, &b_gtop_phi);
   fChain->SetBranchAddress("gtop_m", &gtop_m, &b_gtop_m);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("triggerBits", &triggerBits, &b_triggerBits);
   fChain->SetBranchAddress("addTriggerBits", &addTriggerBits, &b_addTriggerBits);
   fChain->SetBranchAddress("zeroBiasPS", &zeroBiasPS, &b_zeroBiasPS);
   fChain->SetBranchAddress("nl", &nl, &b_nl);
   fChain->SetBranchAddress("l_isPromptFinalState", l_isPromptFinalState, &b_l_isPromptFinalState);
   fChain->SetBranchAddress("l_isDirectPromptTauDecayProductFinalState", l_isDirectPromptTauDecayProductFinalState, &b_l_isDirectPromptTauDecayProductFinalState);
   fChain->SetBranchAddress("l_id", l_id, &b_l_id);
   fChain->SetBranchAddress("l_pid", l_pid, &b_l_pid);
   fChain->SetBranchAddress("l_g", l_g, &b_l_g);
   fChain->SetBranchAddress("l_charge", l_charge, &b_l_charge);
   fChain->SetBranchAddress("l_mva", l_mva, &b_l_mva);
   fChain->SetBranchAddress("l_mvaCats", l_mvaCats, &b_l_mvaCats);
   fChain->SetBranchAddress("l_highpt", l_highpt, &b_l_highpt);
   fChain->SetBranchAddress("l_pt", l_pt, &b_l_pt);
   fChain->SetBranchAddress("l_eta", l_eta, &b_l_eta);
   fChain->SetBranchAddress("l_phi", l_phi, &b_l_phi);
   fChain->SetBranchAddress("l_mass", l_mass, &b_l_mass);
   fChain->SetBranchAddress("l_scaleUnc1", l_scaleUnc1, &b_l_scaleUnc1);
   fChain->SetBranchAddress("l_scaleUnc2", l_scaleUnc2, &b_l_scaleUnc2);
   fChain->SetBranchAddress("l_scaleUnc3", l_scaleUnc3, &b_l_scaleUnc3);
   fChain->SetBranchAddress("l_scaleUnc4", l_scaleUnc4, &b_l_scaleUnc4);
   fChain->SetBranchAddress("l_scaleUnc5", l_scaleUnc5, &b_l_scaleUnc5);
   fChain->SetBranchAddress("l_scaleUnc6", l_scaleUnc6, &b_l_scaleUnc6);
   fChain->SetBranchAddress("l_scaleUnc7", l_scaleUnc7, &b_l_scaleUnc7);
   fChain->SetBranchAddress("l_chargedHadronIso", l_chargedHadronIso, &b_l_chargedHadronIso);
   fChain->SetBranchAddress("l_miniIso", l_miniIso, &b_l_miniIso);
   fChain->SetBranchAddress("l_relIso", l_relIso, &b_l_relIso);
   fChain->SetBranchAddress("l_ip3d", l_ip3d, &b_l_ip3d);
   fChain->SetBranchAddress("l_ip3dsig", l_ip3dsig, &b_l_ip3dsig);
   fChain->SetBranchAddress("ngamma", &ngamma, &b_ngamma);
   fChain->SetBranchAddress("gamma_isPromptFinalState", gamma_isPromptFinalState, &b_gamma_isPromptFinalState);
   fChain->SetBranchAddress("gamma_pid", gamma_pid, &b_gamma_pid);
   fChain->SetBranchAddress("gamma_idFlags", gamma_idFlags, &b_gamma_idFlags);
   fChain->SetBranchAddress("gamma_g", gamma_g, &b_gamma_g);
   fChain->SetBranchAddress("gamma_mva", gamma_mva, &b_gamma_mva);
   fChain->SetBranchAddress("gamma_mvaCats", gamma_mvaCats, &b_gamma_mvaCats);
   fChain->SetBranchAddress("gamma_pt", gamma_pt, &b_gamma_pt);
   fChain->SetBranchAddress("gamma_eta", gamma_eta, &b_gamma_eta);
   fChain->SetBranchAddress("gamma_phi", gamma_phi, &b_gamma_phi);
   fChain->SetBranchAddress("gamma_scaleUnc1", gamma_scaleUnc1, &b_gamma_scaleUnc1);
   fChain->SetBranchAddress("gamma_scaleUnc2", gamma_scaleUnc2, &b_gamma_scaleUnc2);
   fChain->SetBranchAddress("gamma_scaleUnc3", gamma_scaleUnc3, &b_gamma_scaleUnc3);
   fChain->SetBranchAddress("gamma_scaleUnc4", gamma_scaleUnc4, &b_gamma_scaleUnc4);
   fChain->SetBranchAddress("gamma_scaleUnc5", gamma_scaleUnc5, &b_gamma_scaleUnc5);
   fChain->SetBranchAddress("gamma_scaleUnc6", gamma_scaleUnc6, &b_gamma_scaleUnc6);
   fChain->SetBranchAddress("gamma_scaleUnc7", gamma_scaleUnc7, &b_gamma_scaleUnc7);
   fChain->SetBranchAddress("gamma_chargedHadronIso", gamma_chargedHadronIso, &b_gamma_chargedHadronIso);
   fChain->SetBranchAddress("gamma_neutralHadronIso", gamma_neutralHadronIso, &b_gamma_neutralHadronIso);
   fChain->SetBranchAddress("gamma_photonIso", gamma_photonIso, &b_gamma_photonIso);
   fChain->SetBranchAddress("gamma_hoe", gamma_hoe, &b_gamma_hoe);
   fChain->SetBranchAddress("gamma_r9", gamma_r9, &b_gamma_r9);
   fChain->SetBranchAddress("gamma_sieie", gamma_sieie, &b_gamma_sieie);
   fChain->SetBranchAddress("nj", &nj, &b_nj);
   fChain->SetBranchAddress("j_g", j_g, &b_j_g);
   fChain->SetBranchAddress("j_area", j_area, &b_j_area);
   fChain->SetBranchAddress("j_jerUp", j_jerUp, &b_j_jerUp);
   fChain->SetBranchAddress("j_jerDn", j_jerDn, &b_j_jerDn);
   fChain->SetBranchAddress("j_jecUp0", j_jecUp0, &b_j_jecUp0);
   fChain->SetBranchAddress("j_jecDn0", j_jecDn0, &b_j_jecDn0);
   fChain->SetBranchAddress("j_jecUp1", j_jecUp1, &b_j_jecUp1);
   fChain->SetBranchAddress("j_jecDn1", j_jecDn1, &b_j_jecDn1);
   fChain->SetBranchAddress("j_jecUp2", j_jecUp2, &b_j_jecUp2);
   fChain->SetBranchAddress("j_jecDn2", j_jecDn2, &b_j_jecDn2);
   fChain->SetBranchAddress("j_jecUp3", j_jecUp3, &b_j_jecUp3);
   fChain->SetBranchAddress("j_jecDn3", j_jecDn3, &b_j_jecDn3);
   fChain->SetBranchAddress("j_jecUp4", j_jecUp4, &b_j_jecUp4);
   fChain->SetBranchAddress("j_jecDn4", j_jecDn4, &b_j_jecDn4);
   fChain->SetBranchAddress("j_jecUp5", j_jecUp5, &b_j_jecUp5);
   fChain->SetBranchAddress("j_jecDn5", j_jecDn5, &b_j_jecDn5);
   fChain->SetBranchAddress("j_jecUp6", j_jecUp6, &b_j_jecUp6);
   fChain->SetBranchAddress("j_jecDn6", j_jecDn6, &b_j_jecDn6);
   fChain->SetBranchAddress("j_jecUp7", j_jecUp7, &b_j_jecUp7);
   fChain->SetBranchAddress("j_jecDn7", j_jecDn7, &b_j_jecDn7);
   fChain->SetBranchAddress("j_jecUp8", j_jecUp8, &b_j_jecUp8);
   fChain->SetBranchAddress("j_jecDn8", j_jecDn8, &b_j_jecDn8);
   fChain->SetBranchAddress("j_jecUp9", j_jecUp9, &b_j_jecUp9);
   fChain->SetBranchAddress("j_jecDn9", j_jecDn9, &b_j_jecDn9);
   fChain->SetBranchAddress("j_jecUp10", j_jecUp10, &b_j_jecUp10);
   fChain->SetBranchAddress("j_jecDn10", j_jecDn10, &b_j_jecDn10);
   fChain->SetBranchAddress("j_jecUp11", j_jecUp11, &b_j_jecUp11);
   fChain->SetBranchAddress("j_jecDn11", j_jecDn11, &b_j_jecDn11);
   fChain->SetBranchAddress("j_jecUp12", j_jecUp12, &b_j_jecUp12);
   fChain->SetBranchAddress("j_jecDn12", j_jecDn12, &b_j_jecDn12);
   fChain->SetBranchAddress("j_jecUp13", j_jecUp13, &b_j_jecUp13);
   fChain->SetBranchAddress("j_jecDn13", j_jecDn13, &b_j_jecDn13);
   fChain->SetBranchAddress("j_jecUp14", j_jecUp14, &b_j_jecUp14);
   fChain->SetBranchAddress("j_jecDn14", j_jecDn14, &b_j_jecDn14);
   fChain->SetBranchAddress("j_jecUp15", j_jecUp15, &b_j_jecUp15);
   fChain->SetBranchAddress("j_jecDn15", j_jecDn15, &b_j_jecDn15);
   fChain->SetBranchAddress("j_jecUp16", j_jecUp16, &b_j_jecUp16);
   fChain->SetBranchAddress("j_jecDn16", j_jecDn16, &b_j_jecDn16);
   fChain->SetBranchAddress("j_jecUp17", j_jecUp17, &b_j_jecUp17);
   fChain->SetBranchAddress("j_jecDn17", j_jecDn17, &b_j_jecDn17);
   fChain->SetBranchAddress("j_jecUp18", j_jecUp18, &b_j_jecUp18);
   fChain->SetBranchAddress("j_jecDn18", j_jecDn18, &b_j_jecDn18);
   fChain->SetBranchAddress("j_jecUp19", j_jecUp19, &b_j_jecUp19);
   fChain->SetBranchAddress("j_jecDn19", j_jecDn19, &b_j_jecDn19);
   fChain->SetBranchAddress("j_jecUp20", j_jecUp20, &b_j_jecUp20);
   fChain->SetBranchAddress("j_jecDn20", j_jecDn20, &b_j_jecDn20);
   fChain->SetBranchAddress("j_jecUp21", j_jecUp21, &b_j_jecUp21);
   fChain->SetBranchAddress("j_jecDn21", j_jecDn21, &b_j_jecDn21);
   fChain->SetBranchAddress("j_jecUp22", j_jecUp22, &b_j_jecUp22);
   fChain->SetBranchAddress("j_jecDn22", j_jecDn22, &b_j_jecDn22);
   fChain->SetBranchAddress("j_jecUp23", j_jecUp23, &b_j_jecUp23);
   fChain->SetBranchAddress("j_jecDn23", j_jecDn23, &b_j_jecDn23);
   fChain->SetBranchAddress("j_jecUp24", j_jecUp24, &b_j_jecUp24);
   fChain->SetBranchAddress("j_jecDn24", j_jecDn24, &b_j_jecDn24);
   fChain->SetBranchAddress("j_jecUp25", j_jecUp25, &b_j_jecUp25);
   fChain->SetBranchAddress("j_jecDn25", j_jecDn25, &b_j_jecDn25);
   fChain->SetBranchAddress("j_jecUp26", j_jecUp26, &b_j_jecUp26);
   fChain->SetBranchAddress("j_jecDn26", j_jecDn26, &b_j_jecDn26);
   fChain->SetBranchAddress("j_jecUp27", j_jecUp27, &b_j_jecUp27);
   fChain->SetBranchAddress("j_jecDn27", j_jecDn27, &b_j_jecDn27);
   fChain->SetBranchAddress("j_jecUp28", j_jecUp28, &b_j_jecUp28);
   fChain->SetBranchAddress("j_jecDn28", j_jecDn28, &b_j_jecDn28);
   fChain->SetBranchAddress("j_rawsf", j_rawsf, &b_j_rawsf);
   fChain->SetBranchAddress("j_pt", j_pt, &b_j_pt);
   fChain->SetBranchAddress("j_eta", j_eta, &b_j_eta);
   fChain->SetBranchAddress("j_phi", j_phi, &b_j_phi);
   fChain->SetBranchAddress("j_mass", j_mass, &b_j_mass);
   fChain->SetBranchAddress("j_pumva", j_pumva, &b_j_pumva);
   fChain->SetBranchAddress("j_id", j_id, &b_j_id);
   fChain->SetBranchAddress("j_csv", j_csv, &b_j_csv);
   fChain->SetBranchAddress("j_btag", j_btag, &b_j_btag);
   fChain->SetBranchAddress("j_emf", j_emf, &b_j_emf);
   fChain->SetBranchAddress("j_qg", j_qg, &b_j_qg);
   fChain->SetBranchAddress("j_c2_00", j_c2_00, &b_j_c2_00);
   fChain->SetBranchAddress("j_c2_02", j_c2_02, &b_j_c2_02);
   fChain->SetBranchAddress("j_c2_05", j_c2_05, &b_j_c2_05);
   fChain->SetBranchAddress("j_c2_10", j_c2_10, &b_j_c2_10);
   fChain->SetBranchAddress("j_c2_20", j_c2_20, &b_j_c2_20);
   fChain->SetBranchAddress("j_zg", j_zg, &b_j_zg);
   fChain->SetBranchAddress("j_mult", j_mult, &b_j_mult);
   fChain->SetBranchAddress("j_gaptd", j_gaptd, &b_j_gaptd);
   fChain->SetBranchAddress("j_gawidth", j_gawidth, &b_j_gawidth);
   fChain->SetBranchAddress("j_gathrust", j_gathrust, &b_j_gathrust);
   fChain->SetBranchAddress("j_tau32", j_tau32, &b_j_tau32);
   fChain->SetBranchAddress("j_tau21", j_tau21, &b_j_tau21);
   fChain->SetBranchAddress("j_deepcsv", j_deepcsv, &b_j_deepcsv);
   fChain->SetBranchAddress("j_probc", j_probc, &b_j_probc);
   fChain->SetBranchAddress("j_probudsg", j_probudsg, &b_j_probudsg);
   fChain->SetBranchAddress("j_probb", j_probb, &b_j_probb);
   fChain->SetBranchAddress("j_probbb", j_probbb, &b_j_probbb);
   fChain->SetBranchAddress("j_CvsL", j_CvsL, &b_j_CvsL);
   fChain->SetBranchAddress("j_CvsB", j_CvsB, &b_j_CvsB);
   fChain->SetBranchAddress("j_vtxpx", j_vtxpx, &b_j_vtxpx);
   fChain->SetBranchAddress("j_vtxpy", j_vtxpy, &b_j_vtxpy);
   fChain->SetBranchAddress("j_vtxpz", j_vtxpz, &b_j_vtxpz);
   fChain->SetBranchAddress("j_vtxmass", j_vtxmass, &b_j_vtxmass);
   fChain->SetBranchAddress("j_vtxNtracks", j_vtxNtracks, &b_j_vtxNtracks);
   fChain->SetBranchAddress("j_vtx3DVal", j_vtx3DVal, &b_j_vtx3DVal);
   fChain->SetBranchAddress("j_vtx3DSig", j_vtx3DSig, &b_j_vtx3DSig);
   fChain->SetBranchAddress("j_flav", j_flav, &b_j_flav);
   fChain->SetBranchAddress("j_hadflav", j_hadflav, &b_j_hadflav);
   fChain->SetBranchAddress("j_pid", j_pid, &b_j_pid);
   fChain->SetBranchAddress("nj8", &nj8, &b_nj8);
   fChain->SetBranchAddress("j8_pt", j8_pt, &b_j8_pt);
   fChain->SetBranchAddress("j8_eta", j8_eta, &b_j8_eta);
   fChain->SetBranchAddress("j8_phi", j8_phi, &b_j8_phi);
   fChain->SetBranchAddress("j8_mass", j8_mass, &b_j8_mass);
   fChain->SetBranchAddress("j8_tau1", j8_tau1, &b_j8_tau1);
   fChain->SetBranchAddress("j8_tau2", j8_tau2, &b_j8_tau2);
   fChain->SetBranchAddress("nchPV", &nchPV, &b_nchPV);
   fChain->SetBranchAddress("sumPVChPt", &sumPVChPt, &b_sumPVChPt);
   fChain->SetBranchAddress("sumPVChPz", &sumPVChPz, &b_sumPVChPz);
   fChain->SetBranchAddress("sumPVChHt", &sumPVChHt, &b_sumPVChHt);
   fChain->SetBranchAddress("nPFCands", nPFCands, &b_nPFCands);
   fChain->SetBranchAddress("sumPFEn", sumPFEn, &b_sumPFEn);
   fChain->SetBranchAddress("sumPFPz", sumPFPz, &b_sumPFPz);
   fChain->SetBranchAddress("sumPFHt", sumPFHt, &b_sumPFHt);
   fChain->SetBranchAddress("nPFChCands", nPFChCands, &b_nPFChCands);
   fChain->SetBranchAddress("sumPFChEn", sumPFChEn, &b_sumPFChEn);
   fChain->SetBranchAddress("sumPFChPz", sumPFChPz, &b_sumPFChPz);
   fChain->SetBranchAddress("sumPFChHt", sumPFChHt, &b_sumPFChHt);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_sig", &met_sig, &b_met_sig);
   fChain->SetBranchAddress("met_ptShifted", met_ptShifted, &b_met_ptShifted);
   fChain->SetBranchAddress("met_phiShifted", met_phiShifted, &b_met_phiShifted);
   fChain->SetBranchAddress("met_filterBits", &met_filterBits, &b_met_filterBits);
   fChain->SetBranchAddress("nppstrk", &nppstrk, &b_nppstrk);
   fChain->SetBranchAddress("ppstrk_pot", ppstrk_pot, &b_ppstrk_pot);
   fChain->SetBranchAddress("ppstrk_x", ppstrk_x, &b_ppstrk_x);
   fChain->SetBranchAddress("ppstrk_y", ppstrk_y, &b_ppstrk_y);
   fChain->SetBranchAddress("ppstrk_xUnc", ppstrk_xUnc, &b_ppstrk_xUnc);
   fChain->SetBranchAddress("ppstrk_yUnc", ppstrk_yUnc, &b_ppstrk_yUnc);
   fChain->SetBranchAddress("ppstrk_tx", ppstrk_tx, &b_ppstrk_tx);
   fChain->SetBranchAddress("ppstrk_ty", ppstrk_ty, &b_ppstrk_ty);
   fChain->SetBranchAddress("ppstrk_txUnc", ppstrk_txUnc, &b_ppstrk_txUnc);
   fChain->SetBranchAddress("ppstrk_tyUnc", ppstrk_tyUnc, &b_ppstrk_tyUnc);
   fChain->SetBranchAddress("ppstrk_recoInfo", ppstrk_recoInfo, &b_ppstrk_recoInfo);
   fChain->SetBranchAddress("ppstrk_chisqnorm", ppstrk_chisqnorm, &b_ppstrk_chisqnorm);
   fChain->SetBranchAddress("ppstrk_t", ppstrk_t, &b_ppstrk_t);
   fChain->SetBranchAddress("ppstrk_tUnc", ppstrk_tUnc, &b_ppstrk_tUnc);
   fChain->SetBranchAddress("nfwdtrk", &nfwdtrk, &b_nfwdtrk);
   fChain->SetBranchAddress("fwdtrk_pot", &fwdtrk_pot, &b_fwdtrk_pot);
   fChain->SetBranchAddress("fwdtrk_method", &fwdtrk_method, &b_fwdtrk_method);
   fChain->SetBranchAddress("fwdtrk_recoInfo", &fwdtrk_recoInfo, &b_fwdtrk_recoInfo);
   fChain->SetBranchAddress("fwdtrk_thetax", &fwdtrk_thetax, &b_fwdtrk_thetax);
   fChain->SetBranchAddress("fwdtrk_thetay", &fwdtrk_thetay, &b_fwdtrk_thetay);
   fChain->SetBranchAddress("fwdtrk_x", &fwdtrk_x, &b_fwdtrk_x);
   fChain->SetBranchAddress("fwdtrk_y", &fwdtrk_y, &b_fwdtrk_y);
   fChain->SetBranchAddress("fwdtrk_tx", &fwdtrk_tx, &b_fwdtrk_tx);
   fChain->SetBranchAddress("fwdtrk_ty", &fwdtrk_ty, &b_fwdtrk_ty);
   fChain->SetBranchAddress("fwdtrk_vx", &fwdtrk_vx, &b_fwdtrk_vx);
   fChain->SetBranchAddress("fwdtrk_vy", &fwdtrk_vy, &b_fwdtrk_vy);
   fChain->SetBranchAddress("fwdtrk_vz", &fwdtrk_vz, &b_fwdtrk_vz);
   fChain->SetBranchAddress("fwdtrk_time", &fwdtrk_time, &b_fwdtrk_time);
   fChain->SetBranchAddress("fwdtrk_timeError", &fwdtrk_timeError, &b_fwdtrk_timeError);
   fChain->SetBranchAddress("fwdtrk_chisqnorm", &fwdtrk_chisqnorm, &b_fwdtrk_chisqnorm);
   fChain->SetBranchAddress("fwdtrk_xi", &fwdtrk_xi, &b_fwdtrk_xi);
   fChain->SetBranchAddress("fwdtrk_xiError", &fwdtrk_xiError, &b_fwdtrk_xiError);
   fChain->SetBranchAddress("fwdtrk_t", &fwdtrk_t, &b_fwdtrk_t);
   fChain->SetBranchAddress("nrawmu", &nrawmu, &b_nrawmu);
   fChain->SetBranchAddress("rawmu_pt", rawmu_pt, &b_rawmu_pt);
   fChain->SetBranchAddress("rawmu_eta", rawmu_eta, &b_rawmu_eta);
   fChain->SetBranchAddress("rawmu_phi", rawmu_phi, &b_rawmu_phi);
   fChain->SetBranchAddress("rawmu_pid", rawmu_pid, &b_rawmu_pid);
   Notify();
}

Bool_t Blah::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Blah::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Blah::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Blah_cxx
