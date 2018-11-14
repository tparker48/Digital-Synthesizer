// KeyboardInput.h
// Thomas Parker

// KeyboardInput monitors the user's keyboard, mapping keystrokes to notes

#ifndef TPARKER_KEYBOARD_INPUT
#define TPARKER_KEYBOARD_INPUT

#include "Input.h"
#include <string>
#include <SDL2/SDL.h>
#include <map>

class KeyboardInput : public Input {
	public:
		KeyboardInput();
		virtual double const getHz();

	private:
		// Points to a value holding key on/off status for every key
		static const Uint8* keyboardState;

		virtual std::string const getNotePressed();

		// These two map keys on the keyboard to their respective chars
		// TODO: Replace this representation with single data structure.
		static const std::map<SDL_Scancode, std::string> keysToNotes;
		static const SDL_Scancode codes[];
};

#endif