// Lfo.h
// Thomas Parker
// 9/30/2018

// A low frequency oscillator (LFO) is used to continuously modulate a value chosen by the user

#ifndef TPARKER_LFO_H
#define TPARKER_LFO_H

#include "Oscillator.h"

class Lfo: public Oscillator {
	public:
		Lfo();
		Lfo(double* modulationTarget, int waveType = 1, double frequency = 2, double amplitude = 1.0);

		void setModulationTarget(double* target);
		void setAmplitude(double amplitude);

		double* const getModulationTarget();
		void updateTarget(int bufferSize, double samplingFrequency);

	private:
		double* target;
};

#endif