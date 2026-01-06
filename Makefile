APP_NAME = game
SOURCE_FILES = $(wildcard src/*.cpp) $(wildcard src/attacks/*.cpp) $(wildcard src/core/*.cpp)

BUILD_DIRECTORY = build
DESKTOP_OUTPUT_DIRECTORY = $(BUILD_DIRECTORY)/native
WEB_OUTPUT_DIRECTORY = $(BUILD_DIRECTORY)/web

DESKTOP_COMPILER = clang++
DEBUG_FLAGS = -g -O0
SANITIZER_FLAGS = -fno-omit-frame-pointer -fsanitize=address,undefined,integer
WARNING_FLAGS = -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wnon-virtual-dtor -Woverloaded-virtual -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wundef -Wcast-align
VERSION_FLAG = -std=c++17

# Include paths (where to look for header files)
INCLUDE_FLAGS = -Isrc -Isrc/attacks
LIBRARY_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Combine all flags for the Desktop build
DESKTOP_COMPILE_FLAGS = $(VERSION_FLAG) $(WARNING_FLAGS) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) $(INCLUDE_FLAGS)

# The final executable file path
DESKTOP_EXECUTABLE = $(DESKTOP_OUTPUT_DIRECTORY)/$(APP_NAME)

WEB_COMPILER = emcc

# ASYNCIFY Allows standard infinite loops (while(true)) to run in browser
WEB_FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s USE_SDL_TTF=2 -s INITIAL_MEMORY=134217728 --use-preload-plugins -s ASYNCIFY --shell-file web_templates/shell.html

# Asset preloading (maps your local folders to the web browser's virtual file system)
ASSET_FLAGS = --preload-file sprites --preload-file audio --preload-file fonts

# The final web file path
WEB_EXECUTABLE = $(WEB_OUTPUT_DIRECTORY)/index.html

# TASK: Build and Run Desktop Version
# This depends on $(SOURCE_FILES) existing.
desktop: $(SOURCE_FILES)
	echo "Building Desktop Version..."
	mkdir -p $(DESKTOP_OUTPUT_DIRECTORY)
	$(DESKTOP_COMPILER) $(DESKTOP_COMPILE_FLAGS) $(SOURCE_FILES) $(LIBRARY_FLAGS) -o $(DESKTOP_EXECUTABLE)

# TASK: Build Web Version
web: $(SOURCE_FILES)
	echo "Building Web Version..."
	mkdir -p $(WEB_OUTPUT_DIRECTORY)
	$(WEB_COMPILER) $(SOURCE_FILES) $(INCLUDE_FLAGS) $(WEB_FLAGS) $(ASSET_FLAGS) -o $(WEB_EXECUTABLE)
	echo "Web build successful: $(WEB_EXECUTABLE)"

# TASK: Run a local web server to test the game
serve:
	echo "Opening server at http://0.0.0.0:8000"
	python3 -m http.server 8000 --bind 0.0.0.0 -d $(WEB_OUTPUT_DIRECTORY)

# TASK: Delete all build files to start fresh
clean:
	echo "Deleting build directory..."
	rm -rf $(BUILD_DIRECTORY)

# Expose the local web server to the internet using ngrok
# Note: Must run 'make serve' in a separate terminal first
share-web-publicly:
	echo "Starting public tunnel to port 8000..."
	ngrok http 8000
