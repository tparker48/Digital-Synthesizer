// Input.cpp
// Thomas Parker
// 10/2/2018

#include "Input.h"
#include <unordered_map>

Input::Input() {
	keyMap = (std::unordered_map<char, double>){
					{'a', 261.6256}, {'w', 277.1826},
					{'s', 293.6648}, {'e', 311.1270},
					{'d', 329.6276},
					{'f', 349.2282}, {'t', 369.9944},
					{'g', 391.9954}, {'y', 415.3047},
					{'h', 440.0000}, {'u', 466.1638},
					{'j', 493.8833},
					{'k', 523.2512}, {'o', 554.3652},
					{'l', 587.2296}, {'p', 622.254},
					{'0', 0.0000}
				};
	// Lower-case letters denote sharp notes: 'c' = C#
	// Other octaves are acheived via operations on these base frequencies.
}

double const Input::keyToHz(char key) {
	return keyMap[key];
}