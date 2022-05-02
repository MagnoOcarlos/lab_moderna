//g++ MakePlot2D-Carlos.cc -o MakePlot2D-Carlos.exe `root-config --cflags --glibs`
//./MakePlot2D-Carlos.exe
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <unistd.h>
#include "TGraph.h"
#include <TRandom3.h>
#include "TRandom.h"
#include "TRint.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TF1.h"
#include "TLine.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TH2F.h"
#include "TLegend.h"

using namespace std;


//Function to find the number of rows of a file 
int count(ifstream& fin){
		
	int rows=0;	

	double val=0;
	    
	
	while( fin >> val )	
		++rows;
	
		
	return(rows);
}


	TH1D* fillingHist( ifstream& f){
	
	double E=0;
	int rows = count(f);
	TH1D *h = new TH1D("","Title", 50, 11,11.5);
	
	f.clear();
	f.seekg(0);
	
	for(int i=0; i <=rows;i++){
		
		f>>E;
		h->Fill(log10(E));
	}

	f.clear();
	f.seekg(0);
	
	return(h);
}


int main(){
	
	TH1D* hraio2cm;
	TH1D* hraio3cm;


	const char *filename="plot.txt";
	
	ifstream input(filename);

	hraio2cm=fillingHist(input);		
	
	auto *c = new TCanvas("c","Plot experimental",200,10,600,400);

	hraio2cm->SetLineColor(kRed);
//	hraio2cm>SetStats(0);
// 	hraio2cm->GetYaxis()->SetRangeUser(1e-5,1e0);
	hraio2cm->GetYaxis()->SetTitle("Count");
	hraio2cm->GetXaxis()->SetTitle("Log((q/m)kgC^{-1})");
	hraio2cm->Draw("HIST");

	c->SetCanvasSize(1200,600);
	c->SaveAs("plot.pdf");

	
}
