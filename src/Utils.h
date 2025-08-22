#include "GameObject.h"
#include "Globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include <stdio.h>
#include <string>
#include <vector>

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

GameObject *find_object_by_name(std::string obj_name);