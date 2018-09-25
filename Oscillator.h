// Oscillator.h
// Thomas Parker
// 9/25/2018

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

// This class models an oscillator, the component in every synth that is responsible for producing a signal

class Oscillator {
	public:
		Oscillator();
		Oscillator(int waveType, double frequency = 261.625565);	//frequency defaults to middle C

		void setWaveType(int waveType);	//1-sine   2-square   3-triangle   4-saw 
		void setFrequency(double frequency);
		void resetPhase();

		//called by SynthEngine when new samples are needed for output
		void fillSampleBuffer(double *buffer, int bufferSize, double samplingFrequency); 

	private:
		double generateSample(double phase);	// helper function for sample calculation
		int waveType;
		double phaseOffset;	// used to maintain continuity between buffers
		double frequency;
};

#endif