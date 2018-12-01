// Input.cpp
// Thomas Parker

#include "Input.h"
#include <map>
#include <cmath>
#include <string>
#include <iostream>

Input::Input() {
	octaveShift = 1;
	// starts with the notes and # of halfsteps from A
	noteMap = (std::map<std::string, double>){
					{"c", -9}, {"c#", -8},
					{"d", -7}, {"d#", -6},
					{"e", -5},
					{"f", -4}, {"f#", -3},
					{"g", -2}, {"g#", -1},
					{"a", 0}, {"a#", 1},
					{"b", 2},
					{"c1",3}, {"c#1",4},
					{"d1",5}, {"d#1",6},
				};
	// convert each halfstep value into a frequency
	for(auto x: noteMap){
		noteMap.at(x.first) = hzCalculator(x.second);
	}
}

double const Input::noteToHz(std::string note) {
	if(note == "0") return 0;
	else return noteMap[note];
}

// this formula and an explanation for it can be found here: https://pages.mtu.edu/~suits/NoteFreqCalcs.html
double Input::hzCalculator(double halfSteps){
	double a = 1.05946309435;
	double hz;
	hz = pow(a, halfSteps);
	return (440.0 * hz);
}