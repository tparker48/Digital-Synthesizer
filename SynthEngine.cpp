// SynthEngine.cpp
// Thomas Parker
// 9/25/2018

#include "SynthEngine.h"

SynthEngine::SynthEngine():sampleRate(0), osc(0), lfo(0) {}

SynthEngine::SynthEngine(Oscillator &osc, Lfo &lfo, int sampleRate){
	this->osc = &osc;
	this->lfo = &lfo;
	this->sampleRate = sampleRate;
}

int const SynthEngine::generateSamples(double *buffer, unsigned int bufferSize){
	lfo->updateTarget(bufferSize, sampleRate);
	osc->fillSampleBuffer(buffer, bufferSize, sampleRate);
	return 0;
}