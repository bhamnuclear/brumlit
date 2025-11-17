void fudge() {
	double pi =4*atan(1.);
	double Einitial=1.89;//MeV
	double Eth=1.8804 ;//Threshold energy
	const int nsteps=1000;
	double En[nsteps]={0.};
	double XS1[nsteps]={0.};
	double XS2[nsteps]={0.};
	for(int n=0;n<nsteps;n++) {
		double energy =Eth + (1.*n/nsteps)*(Einitial-Eth);
 
		En[n] = energy;
	        double C0=6;//From Lee and Zhou
	        double A=164.913;//mb MeV/sr
	        double x=C0*sqrt(1-Eth/energy);
	        double XS=4.*pi*(A*x)/(energy*(1+x)*(1+x));
		cout<<energy<<"\t"<<A<<"\t"<<energy<<endl;

		XS1[n] = XS;
	        double softness = 0.0001;
	        XS*=TMath::TanH((energy-Eth)/softness);//FUDGE!
		XS2[n] = XS;
	}
	TGraph *g1 = new TGraph(nsteps,En,XS1);
	TGraph *g2 = new TGraph(nsteps,En,XS2);
	g1->Draw();
	g2->Draw("SAME");
	g1->SetLineColor(kRed);
}
