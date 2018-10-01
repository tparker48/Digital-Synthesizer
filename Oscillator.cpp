// Oscillator.cpp
// Thomas Parker
// 9/25/2018

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


int Oscillator::getWaveType() {
	return waveType;
}

double Oscillator::getFrequency() {
	return frequency;
}

double* Oscillator::getFrequencyPointer() {
	return &freqMod;
}

double Oscillator::getAmplitude() {
	return amplitude;
}

double* Oscillator::getAmplitudePointer() {
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
	for(int i = 0; i < bufferSize; i++){
		for(int j = 0; j < 2; j++){
			*buffer++ = generateSample((phaseIncrement * i) + phaseOffset);
		}
	}
	phaseOffset += bufferSize * phaseIncrement;
	freqMod = 0;	// reset mod ammounts
	ampMod = 1;
}

double Oscillator::generateSample(double phase) {
	switch (Oscillator::waveType) {
		case 1:	// sine wave
			return ((amplitude * ampMod) * sin(phase));
			break;
		case 2:	// square wave
			if(sin(phase) <= 0){
				return -(amplitude * ampMod);
			}
			else {
				return (amplitude * ampMod);
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