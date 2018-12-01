CXX=g++
RM=rm -f
CXXFLAGS=-std=c++11 -I include
LINKERFLAGS=-lrtAudio -lSDL2
SRC=$(wildcard src/*)
EXEC=build/exec
BUILD=build/
all: synth

synth: $(BUILD) $(SRC)
	$(CXX) $(CXXFLAGS) $(LINKERFLAGS) $(SRC) -o $(EXEC)

run: $(BUILD) $(EXEC)
	./$(EXEC)

clean: $(BUILD)
	$(RM) $(EXEC)

$(BUILD):
	mkdir build