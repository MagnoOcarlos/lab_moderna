#!/bin/bash


	cat raio2cm.txt | awk '{ratio=(3.29*(10^6)*$1)/((0.02^2)*($2*$2)); printf"%0.3f\n", ratio}'>>plot.txt

	
	cat raio3cm.txt | awk '{ratio=(3.29*(10^6)*$1)/((0.03^2)*($2*$2)); printf"%0.3f\n", ratio}'>>plot.txt

	cat raio4cm.txt | awk '{ratio=(3.29*(10^6)*$1)/((0.04^2)*($2*$2)); printf"%0.3f\n", ratio}'>>plot.txt

	cat raio5cm.txt | awk '{ratio=(3.29*(10^6)*$1)/((0.05^2)*($2*$2)); printf"%0.3f\n", ratio}'>>plot.txt

	g++ plot_exp_modern.cc -o run.exe `root-config --cflags --glibs`
	
	./run.exe
