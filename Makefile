CXX = g++
# Debug and sanitizer flags suggested by ChatGPT
DEBUG_FLAGS = -g -O0
SANITIZER_FLAGS = -fno-omit-frame-pointer -fsanitize=address,undefined
CXXFLAGS = $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -Isrc -Isrc/attacks
SDL2_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SRC = $(wildcard src/*.cpp) $(wildcard src/attacks/*.cpp)
TARGET = main_exec

compile_and_run: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(SDL2_FLAGS) -o $(TARGET)
	./$(TARGET)
