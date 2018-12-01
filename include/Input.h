// Input.h
// Thomas Parker

// Input monitors the user's actions and converts them into notes

#ifndef TPARKER_INPUT_H
#define TPARKER_INPUT_H

#include <map>

class Input {
	public:
		Input();
		virtual double const getHz() = 0;

	protected:
		virtual std::string const getNotePressed() = 0;
		double const noteToHz(std::string note);
		double hzCalculator(double halfSteps); // used to calculate Hz values for map
		double octaveShift;

		// This map links notes to their respective frequencies (Hz).
		std::map<std::string, double> noteMap;
};

#endif