CXX = g++
CXXFLAGS = -g -Isrc -Isrc/attacks
SDL2_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SRC = $(wildcard src/*.cpp) $(wildcard src/attacks/*.cpp)
TARGET = main_exec

compile_and_run: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(SDL2_FLAGS) -o $(TARGET)
	./$(TARGET)
