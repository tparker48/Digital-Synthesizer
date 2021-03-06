// SynthEngine.h
// Thomas Parker

// This class oversees all the relevant components of the synth in order to generate output data.
// The output data is written to a buffer used by the RtAudio Stream.

#ifndef TPARKER_SYNTH_ENGINE_H
#define TPARKER_SYNTH_ENGINE_H

#include "Oscillator.h"
#include "Lfo.h"
#include "Input.h"
#include "RtAudio.h"

class SynthEngine {
	public:
		SynthEngine();
		SynthEngine(Oscillator &osc, Lfo &lfo1,int sampleRate);

		int const generateSamples(double *buffer, unsigned int bufferSize);

	private:
		int sampleRate;
		Oscillator* osc;
		Lfo* lfo1;

};

#endif