// KeyboardInput.h
// Thomas Parker
// 10/6/2018

// KeyboardInput monitors the user's keyboard, mapping keystrokes to notes

#ifndef TPARKER_KEYBOARD_INPUT
#define TPARKER_KEYBOARD_INPUT

#include "Input.h"
#include <string>
#include <SDL2/SDL.h>

class KeyboardInput : public Input {
	public:
		KeyboardInput();
		virtual double const getNote();

	private:
		// Points to a value holding key on/off status for every key
		static const Uint8* keyboardState;

		virtual char const getKeyPressed();

		// These two map keys on the keyboard to their respective chars
		// TODO: Replace this representation with single data structure.
		static const std::string keys;
		static const SDL_Scancode codes[];
};

#endif