// SynthEngine.h
// Thomas Parker
// 9/25/2018

// This class talks to the relevant components of the synth in order to generate output data.
// The output data is written to a buffer used by the RtAudio Stream.

#ifndef TPARKER_SYNTH_ENGINE_H
#define TPARKER_SYNTH_ENGINE_H

#include "Oscillator.h"
#include "Lfo.h"
#include "RtAudio.h"

class SynthEngine {
	public:
		SynthEngine();
		SynthEngine(Oscillator &osc, Lfo &lfo, int sampleRate);

		int const generateSamples(double *buffer, unsigned int bufferSize);
		//void toggleOutput();

	private:
		//bool outputOn; // output sound if true, silence if false
		int sampleRate;
		Oscillator* osc;
		Lfo* lfo;
};

#endif