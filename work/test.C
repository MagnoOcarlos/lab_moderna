{
gROOT->Reset();
//gStyle->SetOptStat(kFALSE);
//gStyle->SetOptTitle(kFALSE);
	  double elongation,energy;
	  TH2F *h = new TH2F("","Angle 80#circ L_{B} =0.1 Mpc B=100 nG R=80 Mpc",80,-9,0,100,-5,5);
	  h->SetFillColorAlpha(kRed, 0.35); 
	  for(int i =80; i<=80;i+=20){	  
		  
		  string num_i(to_string(i));
		  
		 ifstream F1("../elongation_"+num_i+"Mpc.txt");
		 ifstream F2("../delta_"+num_i+"Mpc.txt");
//		 ifstream F2("../energy0_"+num_i+"Mpc.txt");
//		 ifstream F2("../energy_"+num_i+"Mpc.txt");
		  while(!F1.eof()){
		      
		  
		      F1 >> elongation;
		      F2 >> energy;
		      //h->Fill(energy,log10(elongation));
		      h->Fill(log10(energy),log10(elongation));
		      //h->Fill(log10(energy*pow(10,18)),log10(elongation));
		  }
		  
	  }
	
	
	  TCanvas MyCanvas("","",600,100,1200,800);   
//	     h->GetXaxis()->SetTitle("log(E_{0} /eV)");
//	     h->GetXaxis()->SetTitle("log(E /eV)");
	     h->GetXaxis()->SetTitle("log(#Delta E/E_{0})");	
	     h->GetYaxis()->SetTitle("log(l/Mpc)");
	     h->GetZaxis()->SetRangeUser(1e0,1e3);

	    //h->GetZaxis()->SetTitle("||H|| [m]");
	     //h->GetZaxis()->SetRangeUser(0,34);
//	  gStyle->SetOptStat(0);
	    
	    h->Draw("colz");
	    MyCanvas.SetLogz();
	    //MyCanvas.SaveAs("Temp.png");





}
