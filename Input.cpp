// Input.cpp
// Thomas Parker
// 10/2/2018

#include "Input.h"
#include <unordered_map>

Input::Input() {
	keyMap = (std::unordered_map<char, double>){
					{'C', 261.6256}, {'c', 277.1826},
					{'D', 293.6648}, {'d', 311.1270},
					{'E', 329.6276},
					{'F', 349.2282}, {'f', 369.9944},
					{'G', 391.9954}, {'g', 415.3047},
					{'A', 440.0000}, {'a', 466.1638},
					{'B', 493.8833},
					{'0', 0.0000}
				};
	// Lower-case letters denote sharp notes: 'c' = C#
	// Other octaves are acheived via operations on these base frequencies.
}

const double Input::keyToHz(char key) {
	return keyMap[key];
}