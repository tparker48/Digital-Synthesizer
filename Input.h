// Input.h
// Thomas Parker
// 10/2/2018

// Input monitors the user's keystrokes and converts them into notes

#ifndef TPARKER_INPUT_H
#define TPARKER_INPUT_H

#include <unordered_map>

class Input {
	public:
		Input();

		const virtual double getNote() = 0;

	protected:
		const virtual char getKeyPressed() = 0;	// returns '0' for no key pressed
		const double keyToHz(char key);

		// This map links notes to their respective frequencies (Hz).
		std::unordered_map<char, double> keyMap;
};

#endif