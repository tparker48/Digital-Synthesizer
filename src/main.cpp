// main.cpp for Digital Synthesizer
// Thomas Parker

#include <SDL2/SDL.h>
#include "RtAudio.h"

#include "SynthEngine.h"
#include "Oscillator.h"
#include "KeyboardInput.h"

using namespace std;


// This function is repeatedly called by the RtAudio stream to output audio
int callback(void *outputStreamBuffer, void *inputBuffer, unsigned int bufferSize, 
            	double streamTime, RtAudioStreamStatus status, void *userData );


int main() {
	int sampleRate = 44100;
	unsigned int bufferSize = 256;
	int cursorX, cursorY;

	// Set up a stream for audio output
	RtAudio outputStream;
	RtAudio::StreamParameters parameters;
	parameters.deviceId = outputStream.getDefaultOutputDevice();
	parameters.firstChannel = 0;
	parameters.nChannels = 2;

	// Initialize all the components of our synth
	KeyboardInput input;
	Oscillator osc(2);
	Lfo lfo1(osc.frequencyModifier(), 1, 10, 20);
	SynthEngine* engine = new SynthEngine(osc, lfo1, sampleRate);

	// Set up display window
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("C++ Synthesizer",50,50,500,500,0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event e;

	// Find audio devices, open and start audio stream
	if (outputStream.getDeviceCount() < 1 ) {
		cout << "\nNo audio devices found!\n";
		exit(0);
	}
	try {
  		outputStream.openStream(&parameters, NULL, RTAUDIO_FLOAT64, sampleRate, &bufferSize, &(*callback), engine);
		outputStream.startStream();
	}
	catch ( RtAudioError& e ) {
		e.printMessage();
		exit(0);
	}

	while(e.type != SDL_QUIT) {
		SDL_PollEvent(&e);

		if(e.type == SDL_KEYDOWN){
			if(e.key.keysym.sym == SDLK_z) input.shiftOctaveDown();
			else if(e.key.keysym.sym == SDLK_x) input.shiftOctaveUp();
		}

		SDL_GetMouseState(&cursorX, &cursorY);
		osc.setFrequency(input.getHz());
		lfo1.setFrequency(cursorX/10);
	}

	try{
		outputStream.closeStream();
	}
	catch (RtAudioError& e ) { 
		e.printMessage();
	}
	

	SDL_DestroyWindow(window);
	SDL_Quit();
	delete engine;

	return 0;
}


int callback(void *outputStreamBuffer, void *inputBuffer, unsigned int bufferSize, 
            	double streamTime, RtAudioStreamStatus status, void *userData ) {

	double *buffer = (double *) outputStreamBuffer;
	SynthEngine *engine = (SynthEngine *) userData;
	engine->generateSamples(buffer, bufferSize);

    return 0;
}