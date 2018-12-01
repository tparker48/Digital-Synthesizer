CXX=g++
RM=rm -f
CXXFLAGS=-std=c++11 -I include
LINKERFLAGS=-lrtAudio -lSDL2
SRC=$(wildcard src/*)
EXEC=build/exec

all: synth

synth: $(SRC)
	$(CXX) $(CXXFLAGS) $(LINKERFLAGS) $(SRC) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	$(RM) exec