// Digital Synthesizer
// Thomas Parker
// 10/2/2018

#include <string>
#include <cstdlib>
#include "RtAudio.h"
#include "SynthEngine.h"
#include "Oscillator.h"

using namespace std;



// This function is repeatedly called by the RtAudio stream to output audio
int callback(void *outputStreamBuffer, void *inputBuffer, unsigned int bufferSize, 
                double streamTime, RtAudioStreamStatus status, void *userData ) {

	double *buffer = (double *) outputStreamBuffer;
	SynthEngine *engine = (SynthEngine *) userData;
	engine->generateSamples(buffer, bufferSize);

    return 0;
}



int main() {

	char input ;
	int sampleRate = 44100;
	unsigned int bufferSize = 256;

	RtAudio outputStream;
	RtAudio::StreamParameters parameters;

	parameters.deviceId = outputStream.getDefaultOutputDevice();
	parameters.firstChannel = 0;
	parameters.nChannels = 2;

	Lfo lfo;
	Oscillator osc;
	SynthEngine* engine = new SynthEngine(osc,lfo, sampleRate);



	if ( outputStream.getDeviceCount() < 1 ) {
		cout << "\nNo audio devices found!\n";
		exit(0);
	}
	try {
  		outputStream.openStream(&parameters, NULL, RTAUDIO_FLOAT64, sampleRate, &bufferSize, &(*callback), engine);
		outputStream.startStream();
	}
	catch ( RtAudioError& e ) {
		e.printMessage();
		exit( 0 );
	}



	lfo.setModulationTarget(osc.frequencyModifier());
	lfo.setAmplitude(5);
	lfo.setFrequency(5);

	while(input != 'q') {
		osc.setFrequency(440);
		cin.get(input);		
		osc.setFrequency(392);
		cin.get(input);		
		osc.setFrequency(329.63);
		cin.get(input);
		osc.setFrequency(392);
		cout << "NOW!\n";
		cin.get(input);		
	}



	try{
		outputStream.closeStream();
	}
	catch (RtAudioError& e ) { 
		e.printMessage();
	}

	delete engine;
	return 0;
}