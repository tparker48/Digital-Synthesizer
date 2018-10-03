// Oscillator.h
// Thomas Parker
// 9/25/2018

// This class models an oscillator, the component in every synth that is responsible for producing a signal

#ifndef TPARKER_OSCILLATOR_H
#define TPARKER_OSCILLATOR_H


class Oscillator {
	public:
		Oscillator();
		Oscillator(int waveType = 1, double frequency = 261.625565, double amplitude = 1.0);	//frequency defaults to middle C

		void setWaveType(int waveType);			//1-sine   2-square   3-triangle   4-saw 
		void setFrequency(double frequency);
		void setAmplitude(double amplitude);

		int 	const getWaveType();
		double  const getFrequency();
		double  const getAmplitude();
		double* const FrequencyModifier();		// Used for setting LFO target
		double* const amplitudeModifier();

		void resetPhase();

		//called by SynthEngine when new samples are needed for output
		void fillSampleBuffer(double *buffer, int bufferSize, double samplingFrequency); 

	protected:
		double const generateSample(double phase);	// helper function for sample calculation
		int waveType;
		double phaseOffset;	// used to maintain continuity between buffers
		double frequency;
		double freqMod;
		double amplitude;
		double ampMod;
};

#endif