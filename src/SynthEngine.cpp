// SynthEngine.cpp
// Thomas Parker

#include "SynthEngine.h"

SynthEngine::SynthEngine():sampleRate(0), osc(0), lfo1(0) {}

SynthEngine::SynthEngine(Oscillator &osc, Lfo &lfo1, int sampleRate){
	this->osc = &osc;
	this->lfo1 = &lfo1;
	this->sampleRate = sampleRate;
}

int const SynthEngine::generateSamples(double *buffer, unsigned int bufferSize){
	lfo1->updateTarget(bufferSize, sampleRate);
	osc->fillSampleBuffer(buffer, bufferSize, sampleRate);
	return 0;
}