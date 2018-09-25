// Oscillator.cpp
// Thomas Parker
// 9/25/2018

#include <cmath>
#include "Oscillator.h"

Oscillator::Oscillator() : waveType(1), phaseOffset(0), frequency(261.6) {}

Oscillator::Oscillator(int waveType, double frequency) : waveType(waveType), phaseOffset(0), frequency(frequency) {}

void Oscillator::setWaveType(int waveType) {
	if(waveType > 0 && waveType < 5){
		this->waveType = waveType;
	}
}
void Oscillator::setFrequency(double frequency) {
	this->frequency = frequency;
}

void Oscillator::resetPhase(){
	phaseOffset = 0;
}

void Oscillator::fillSampleBuffer(double *buffer, int bufferSize, double samplingFrequency){
	// sample frequency * (1/frequency) 	= samples per period
	// 2PI / (samples per period) 			= radians per sample, or phase increment
	// phase increment tells us how many radians to progress between samples
	// the following code is based on the example code from cahpter 5 of BasicSynth by Daniel R. Mitchel
	double frequencyRad = (2 * 3.14159265359) / samplingFrequency;
	double phaseIncrement = frequency * frequencyRad;
	for(int i = 0; i < bufferSize; i++){
		for(int j = 0; j < 2; j++){
			*buffer++ = generateSample((phaseIncrement * i) + phaseOffset);
		}
	}
	phaseOffset += bufferSize * phaseIncrement;
}

double Oscillator::generateSample(double phase) {
	switch (Oscillator::waveType) {
		case 1:	// sine wave
			return sin(phase);
			break;
		case 2:	// square wave
			if(sin(phase) <= 0){
				return -1;
			}
			else {
				return 1;
			}
			break;
		case 3:	// triangle wave
			return 0;
			break;
		case 4:	// saw wave
			return 0;
			break;
	}
	return 0;
}