#include "RtAudio.h"
#include "SynthEngine.h"
#include "Oscillator.h"
#include <cstdlib>

using namespace std;

// This function is repeatedly called by the RtAudio stream
// It uses a SynthEngine object to generate the sound and then passes it to the stream via a buffer
int callback(void *outputBuffer, void *inputBuffer, unsigned int bufferSize, 
                double streamTime, RtAudioStreamStatus status, void *userData ){

    double *buffer = (double *) outputBuffer;
    SynthEngine *engine = (SynthEngine *) userData;
    engine->generateSamples(buffer, bufferSize);

    return 0;
 }

int main() {
  char input;
  int sampleRate = 44100;
  unsigned int bufferSize = 256;
  RtAudio output;
  Oscillator osc(1);  // Initiallize a sine wave oscillator
  SynthEngine* engine = new SynthEngine(osc, sampleRate);


  if ( output.getDeviceCount() < 1 ) {
    cout << "\nNo audio devices found!\n";
    exit(0);
  }

  RtAudio::StreamParameters parameters;
  parameters.deviceId = output.getDefaultOutputDevice();
  parameters.nChannels = 2;
  parameters.firstChannel = 0;

  try {
    output.openStream(&parameters, NULL, RTAUDIO_FLOAT64, sampleRate, &bufferSize, &(*callback), engine);
    output.startStream();
  }
  catch ( RtAudioError& e ) {
    e.printMessage();
    exit( 0 );
  }

  cout << "\nWave Type: Sin\n"
       << "Frequency: 261.625565 Hz  (mid C)\n" 
       << "\nPress Enter to Stop";
  cin.get(input);

  try{
    output.closeStream();
  }
  catch (RtAudioError& e ) { 
    e.printMessage();
  }

  delete engine;
	return 0;
}


