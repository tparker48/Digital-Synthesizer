// Oscillator.cpp
// Thomas Parkers

#include <cmath>
#include "Oscillator.h"
#include <iostream>

Oscillator::Oscillator() : waveType(1), phaseOffset(0), frequency(261.6), amplitude(1.0), freqMod(0), ampMod(1) {}

Oscillator::Oscillator(int waveType, double frequency, double amplitude) {
	this->waveType = waveType;
	phaseOffset = 0;
	this->frequency = frequency;
	this->amplitude = amplitude;
	freqMod = 0;
	ampMod = 1;
}

void Oscillator::setWaveType(int waveType) {
	if(waveType > 0 && waveType < 5){
		this->waveType = waveType;
	}
}
void Oscillator::setFrequency(double frequency) {
	this->frequency = frequency;
}

void Oscillator::setAmplitude(double amplitude) {
	if(amplitude < 0) {
		this->amplitude = 0;
	}

	else if(amplitude > 1.0) {
		this->amplitude = 1.0;
	}

	else this->amplitude = amplitude;
}


int const Oscillator::getWaveType() {
	return waveType;
}

double const Oscillator::getFrequency() {
	return frequency;
}

double* const Oscillator::frequencyModifier() {
	return &freqMod;
}

double const Oscillator::getAmplitude() {
	return amplitude;
}

double* const Oscillator::amplitudeModifier() {
	return &ampMod;
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
	double phaseIncrement = (frequency + freqMod) * frequencyRad;

	bool zeroCheck = (frequency != 0);	//handles behavior when freq = 0
	double sample;

	for(int i = 0; i < bufferSize; i++){
		for(int j = 0; j < 2; j++){
			sample = generateSample((phaseIncrement * i) + phaseOffset);
			*buffer++ = sample * zeroCheck;
		}
	}
	phaseOffset += bufferSize * phaseIncrement;
	freqMod = 0;	// reset mod ammounts
	ampMod = 1;
}

double const Oscillator::generateSample(double phase) {
	double ampUsed = amplitude * ampMod;

	switch (Oscillator::waveType) {
		case 1:	// sine wave
			return (ampUsed * sin(phase));
			break;
		case 2:	// square wave
			if(sin(phase) <= 0){
				return -(ampUsed * abs(ampMod));
			}
			else {
				return (ampUsed * abs(ampMod));
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