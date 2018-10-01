// Lfo.h
// Thomas Parker
// 9/30/2018

#include "Lfo.h"
#include <cmath>

Lfo::Lfo():  Oscillator(1,2,1.0), target(0) {
}

Lfo::Lfo(double* modulationTarget, int waveType, double frequency, double amplitude): Oscillator(waveType,frequency,amplitude) {
	frequency = 2;
	target = modulationTarget;
}

void Lfo::setModulationTarget(double* target) {
	this->target = target;
}

void Lfo::setAmplitude(double amplitude) {
	this->amplitude = amplitude;
}

double* Lfo::getModulationTarget() {
	return target;
}

void Lfo::updateTarget(int bufferSize, double samplingFrequency){
	// sample frequency * (1/frequency) 	= samples per period
	// 2PI / (samples per period) 			= radians per sample, or phase increment
	// phase increment tells us how many radians to progress between samples
	// the following code is based on the example code from cahpter 5 of BasicSynth by Daniel R. Mitchel
	double frequencyRad = (2 * 3.14159265359) / samplingFrequency;
	double phaseIncrement = frequency * frequencyRad;

	*target = (generateSample(phaseOffset));
	phaseOffset += (bufferSize * phaseIncrement);
}