CXX=g++
RM=rm -f
CXXFLAGS=-std=c++11
LINKERFLAGS=-lrtAudio -lSDL2
OBJS=Oscillator.o SynthEngine.o Lfo.o Input.o KeyboardInput.o main.o

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LINKERFLAGS) $(OBJS) -o test

clean:
	$(RM) $(OBJS) test


SynthEngine.o: SynthEngine.cpp
	$(CXX) $(CXXFLAGS) -c -o SynthEngine.o SynthEngine.cpp
Oscillator.o: Oscillator.cpp
	$(CXX) $(CXXFLAGS) -c -o Oscillator.o Oscillator.cpp
Lfo.o: Lfo.cpp
	$(CXX) $(CXXFLAGS) -c -o Lfo.o Lfo.cpp
Input.o: Input.cpp
	$(CXX) $(CXXFLAGS) -c -o Input.o Input.cpp
KeyboardInput.o: KeyboardInput.cpp
	$(CXX) $(CXXFLAGS) -c -o KeyboardInput.o KeyboardInput.cpp
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp