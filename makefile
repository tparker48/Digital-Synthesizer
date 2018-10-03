CXX=g++
RM=rm -f
FLAGS=-lrtAudio -o test
STD=-std=c++11
OBJS=main.o SynthEngine.o Oscillator.o Lfo.o Input.o

all: test

test: $(OBJS)
	$(CXX) $(STD) $(FLAGS) $(OBJS)
	clear
	./test

clean:
	$(RM) $(OBJS) test
	clear