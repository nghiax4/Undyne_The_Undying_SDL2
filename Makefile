CXX = g++
CXXFLAGS = -g
SDL2_FLAGS = -lSDL2 -lSDL2_image

SRC = src/main.cpp src/MenuButton.cpp src/Player.cpp src/Utils.cpp src/GameObject.cpp src/SelectedMenuButtonContainer.cpp
TARGET = main_exec

compile_and_run: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(SDL2_FLAGS) -o $(TARGET)
	./$(TARGET)
