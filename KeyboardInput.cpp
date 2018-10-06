// KeyboardInput.cpp
// Thomas Parker
// 10/6/2018

#include "KeyboardInput.h"
#include <SDL2/SDL.h>

const Uint8* KeyboardInput::keyboardState = SDL_GetKeyboardState(NULL);
const std::string KeyboardInput::keys = "qawsedrftgyhujikolp";
const SDL_Scancode KeyboardInput::codes[]  = {	
								SDL_SCANCODE_Q,
								SDL_SCANCODE_A,
								SDL_SCANCODE_W,
								SDL_SCANCODE_S,
								SDL_SCANCODE_E,
								SDL_SCANCODE_D,
								SDL_SCANCODE_R,
								SDL_SCANCODE_F,
								SDL_SCANCODE_T,
								SDL_SCANCODE_G,
								SDL_SCANCODE_Y,
								SDL_SCANCODE_H,
								SDL_SCANCODE_U,
								SDL_SCANCODE_J,
								SDL_SCANCODE_I,
								SDL_SCANCODE_K,
								SDL_SCANCODE_O,
								SDL_SCANCODE_L,
								SDL_SCANCODE_P,
								};

KeyboardInput::KeyboardInput(): Input() {
}

double const KeyboardInput::getNote() {
	double hz;
	char key = getKeyPressed();
	hz = keyToHz(key);
	return hz;
}

char const KeyboardInput::getKeyPressed() {
	SDL_PumpEvents();
	SDL_Scancode scanCode;
	char output = '0';
	for(int i = 0; i < 19; i++){	//Right-most keys are dominant
		scanCode = codes[i];
		if(keyboardState[scanCode]){
			output = keys[i];
		}
	}

	return output;
}