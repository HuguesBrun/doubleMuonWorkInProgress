#include <iostream>
#include "TKey.h"
#include "TFile.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TGraphAsymmErrors.h"
typedef  unsigned long size_t;

using namespace std;

//////////////////// file name -- global factor/////////////
TFile *theFile1;
//QTFile *theFile2;
/*
    //////////////////// replace the name  ////////////////////
bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
*/

////////////////////draw the plots of TH2F ///////////////////////

void drawPlotsA(TString name, TString nameD, TString outputDir){


    //TH1F *histo1 = (TH1F*) theFile1->Get(name);
//Q    TH1F *histo2 = (TH1F*) theFile2->Get(name);
    TH2F *histo1 = (TH2F*) theFile1->Get(name);
    //Double_t xbins[9] = {8, 12, 17, 20, 22, 30, 50, 80, 120};
    //histo1->Rebin(8, name, xbins);
    
    
    TCanvas *c0 = new TCanvas("c0","coucou",600,600);
    cout << __LINE__ << endl;
    cout << histo1 << endl;
    histo1->Draw("E1");
//Q    histo2->SetFillColor(kGreen);
//Q    histo2->Draw("E3:sames");
    TString outname;
   // If(name.Index("IsoMu20")>=0) outname="IsoMu20";
   // If(name.Index("IsoTkMu20")>=0) outname="IsoTkMu20";
   // If(name.Index("hltL2fL1sMu10lqL1f0L2Filtered10")>=0) outname="hltL2fL1sMu10";
   // If(name.Index("hltL3fL1sMu10lqL1f0L2f10L3Filtered17")>=0) outname="hltL3fL1sMu10";

    std::string from = "_&_";
    std::string NAME = std::string(name);
    size_t start_pos = NAME.find(from);
    NAME.replace(start_pos, from.length(), "_");
    size_t start_pos2 = NAME.find("_PLOT_");
    NAME.replace(start_pos2, 6, "_");
    //start_pos = NAME.find(from);
    //NAME.replace(start_pos, from.length(), "_");
    //c0->Print(outputDir+"/"+NAME+".png");

}

void drawPlotsB(TString name, TString nameD, TString outputDir){


    //TH1F *histo1 = (TH1F*) theFile1->Get(name);
    TGraphAsymmErrors *histo1 = (TGraphAsymmErrors*) theFile1->Get(name);
//Q    TH1F *histo2 = (TH1F*) theFile2->Get(name);
    histo1->GetXaxis()->SetRangeUser(8.,120.); 
 
    TCanvas *c0 = new TCanvas("c0","coucou",600,600);
    histo1->Draw("APE");
    //histo1->Draw("E1");
//Q    histo2->SetFillColor(kGreen);
//Q    histo2->Draw("E3:sames");
   

    std::string from = "_&_";
    std::string NAME = std::string(name);
    size_t start_pos = NAME.find(from);
    NAME.replace(start_pos, from.length(), "_");
    //start_pos = NAME.find("_pass_tag_IsoMu20_");
    //NAME.replace(start_pos, from.length(), "_");
    size_t start_pos2 = NAME.find("_PLOT_");
    NAME.replace(start_pos2, 6, "_");

    c0->Print(outputDir+"/early_"+NAME+".png");
    //c0->Print(outputDir+"/late_"+NAME+".png");
    //c0->Print(outputDir+"/"+nameD+".png");
    
}



//void drawPlots(TString file1, TString file2, TString outputDir){
void drawPlots(TString file1,  TString outputDir){
    theFile1 = new TFile(file1);
    cout << "Filename: " << file1 << endl;
//Q    theFile2 = new TFile(file2);
    theFile1->ls();
    TIter listPlotsFile1(theFile1->GetListOfKeys());
    TKey *keyFile1;
    while ((keyFile1 = (TKey*)listPlotsFile1())) {
        TString typeDirectory = keyFile1->GetClassName();
        TString nomDirectory = keyFile1->GetTitle();
	TString nameD_test = keyFile1->GetName();
        bool trunOnH = (typeDirectory=="TH2F");
        bool trunOnG = (typeDirectory=="TGraphAsymmErrors");
	cout << "typeDirectory: " << keyFile1->GetClassName() << endl;
	cout << "nomDirectory: " << keyFile1->GetTitle() << endl;
	cout << "nameD_test: " << nameD_test << endl;
//        if(trunOnH) drawPlotsA(nameD_test, nomDirectory, outputDir);
	
        if(trunOnG && nameD_test.Contains("pt_eta_pt")) drawPlotsB(nameD_test, nomDirectory, outputDir);
        //if(trunOnH) drawPlotsA(nomDirectory, outputDir);
        //if(trunOnG) drawPlotsB(nomDirectory, outputDir);

        
    }
    
    
}
