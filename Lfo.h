// Lfo.h
// Thomas Parker
// 9/30/2018

#ifndef LFO_H
#define LFO_H

#include "Oscillator.h"

// A low frequency oscillator (LFO) is used to modulate some paramter of the synth chosen by the user

class Lfo: public Oscillator {
	public:
		Lfo();
		Lfo(double* modulationTarget, int waveType = 1, double frequency = 2, double amplitude = 1.0);

		void setModulationTarget(double* target);
		void setAmplitude(double amplitude);
		double* getModulationTarget();
		void updateTarget(int bufferSize, double samplingFrequency);

	private:
		double* target;
};

#endif