// SynthEngine.cpp
// Thomas Parker
// 9/25/2018

#include "SynthEngine.h"

SynthEngine::SynthEngine() :outputOn(true), sampleRate(0), osc(0), lfo(0) {}

SynthEngine::SynthEngine(Oscillator &osc, Lfo &lfo, int sampleRate){
	this->osc = &osc;
	this->lfo = &lfo;
	this->sampleRate = sampleRate;
	outputOn = true;
}

int SynthEngine::generateSamples(double *buffer, unsigned int bufferSize){
	if(outputOn){
		osc->fillSampleBuffer(buffer, bufferSize, sampleRate);
		lfo->updateTarget(bufferSize, sampleRate);
	}
	else {
		for (int i = 0; i < bufferSize; i++){
			for (int j = 0; j < 2; j++){
				*buffer++ = 0;
			}
		}
		lfo->updateTarget(bufferSize, sampleRate);
	}

  return 0;
}

void SynthEngine::toggleOutput() {
	if(outputOn){
		outputOn = false;
	}
	else outputOn = true;
}