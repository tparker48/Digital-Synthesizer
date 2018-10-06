// Input.h
// Thomas Parker
// 10/2/2018

// Input monitors the user's actions and converts them into notes

#ifndef TPARKER_INPUT_H
#define TPARKER_INPUT_H

#include <unordered_map>

class Input {
	public:
		Input();
		virtual double const getNote() = 0;

	protected:
		virtual char const getKeyPressed() = 0;	// returns '0' for no key pressed
		double const keyToHz(char key);

		// This map links notes to their respective frequencies (Hz).
		std::unordered_map<char, double> keyMap;
};

#endif