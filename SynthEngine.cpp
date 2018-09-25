// SynthEngine.cpp
// Thomas Parker
// 9/25/2018

#include "SynthEngine.h"

SynthEngine::SynthEngine() :outputOn(true), sampleRate(0), osc(NULL) {}

SynthEngine::SynthEngine(Oscillator osc, int sampleRate){
	this->osc = new Oscillator(osc);
	this->sampleRate = sampleRate;
	outputOn = true;
}

SynthEngine::~SynthEngine() {
	delete osc;
}

int SynthEngine::generateSamples(double *buffer, unsigned int bufferSize){
	if(outputOn){
		osc->fillSampleBuffer(buffer, bufferSize, sampleRate);
	}
	else {
		for (int i = 0; i < bufferSize; i++){
			for (int j = 0; j < 2; j++){
				*buffer++ = 0;
			}
		}
	}

  return 0;
}

void SynthEngine::toggleOutput() {
	if(outputOn){
		outputOn = false;
	}
	else outputOn = true;
}