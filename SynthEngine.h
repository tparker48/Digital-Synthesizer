// SynthEngine.h
// Thomas Parker
// 9/25/2018

#ifndef SYNTH_ENGINE_H
#define SYNTH_ENGINE_H

#include "Oscillator.h"
#include "RtAudio.h"

class SynthEngine {
	public:
		SynthEngine();
		SynthEngine(Oscillator osc, int sampleRate);
		~SynthEngine();

		int generateSamples(double *buffer, unsigned int bufferSize);
		void toggleOutput();

	private:
		bool outputOn; // output sound if true, silence if false
		int sampleRate;
		Oscillator* osc;
};

#endif