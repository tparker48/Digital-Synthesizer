// KeyboardInput.cpp
// Thomas Parker

#include "KeyboardInput.h"
#include <SDL2/SDL.h>

const Uint8* KeyboardInput::keyboardState = SDL_GetKeyboardState(NULL);
const std::map<SDL_Scancode, std::string> KeyboardInput::keysToNotes = {	
								{SDL_SCANCODE_A, "c"},
								{SDL_SCANCODE_W, "c#"},
								{SDL_SCANCODE_S, "d"},
								{SDL_SCANCODE_E, "d#"},
								{SDL_SCANCODE_D, "e"},
								{SDL_SCANCODE_F, "f"},
								{SDL_SCANCODE_T, "f#"},
								{SDL_SCANCODE_G, "g"},
								{SDL_SCANCODE_Y, "g#"},
								{SDL_SCANCODE_H, "a"},
								{SDL_SCANCODE_U, "a#"},
								{SDL_SCANCODE_J, "b"},
								{SDL_SCANCODE_K, "c1"},
								{SDL_SCANCODE_O, "c1#"},
								{SDL_SCANCODE_L, "d1"},
								{SDL_SCANCODE_P, "d1#"}
								};

KeyboardInput::KeyboardInput(): Input() {
}

double const KeyboardInput::getHz() {
	double hz;
	std::string key = getNotePressed();
	hz = noteToHz(key);
	return hz;
}

std::string const KeyboardInput::getNotePressed() {
	SDL_PumpEvents();
	SDL_Scancode scanCode;
	std::string output = "0";
	for(auto x: keysToNotes){	//Right-most keys are dominant
		if(keyboardState[x.first]){
			output = x.second;
		}
	}

	return output;
}