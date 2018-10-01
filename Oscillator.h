// Oscillator.h
// Thomas Parker
// 9/25/2018

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

// This class models an oscillator, the component in every synth that is responsible for producing a signal

class Oscillator {
	public:
		Oscillator();
		Oscillator(int waveType = 1, double frequency = 261.625565, double amplitude = 1.0);	//frequency defaults to middle C

		void setWaveType(int waveType);	//1-sine   2-square   3-triangle   4-saw 
		void setFrequency(double frequency);
		void setAmplitude(double amplitude);

		int getWaveType();
		double getFrequency();
		double* getFrequencyPointer();	// Used for setting LFO target

		double getAmplitude();
		double* getAmplitudePointer();	// Used for setting LFO target

		void resetPhase();

		//called by SynthEngine when new samples are needed for output
		void fillSampleBuffer(double *buffer, int bufferSize, double samplingFrequency); 

	protected:
		double generateSample(double phase);	// helper function for sample calculation
		int waveType;
		double phaseOffset;	// used to maintain continuity between buffers
		double frequency;
		double freqMod;
		double amplitude;
		double ampMod;
};

#endif