#include "HelpText.h"
#include "Globals.h"
#include <string>

HelpText::HelpText() {
    obj_name = "HelpText";
    z_index = 1000;

    int font_size = SCREEN_HEIGHT * 0.05;
    font.reset(TTF_OpenFont("fonts/ui_font.ttf", font_size));

    SDL_Color text_color = {255, 255, 255};
    const int ALPHA_TRANSPARENCY = 128; // 0-255, where 128 is ~50% transparent
    const int PADDING_LEFT = 10;
    const int PADDING_TOP = 10;

    std::string text_content = "Keyboard: Arrow keys, Enter key\nTouchscreen: Buttons on screen";
    Uint32 wrap_limit_pixels = SCREEN_WIDTH * 0.33;

    // TTF_RenderText_Blended_Wrapped can handle multiline and width wrapping
    SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(font.get(), text_content.c_str(), text_color, wrap_limit_pixels);

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureAlphaMod(texture, ALPHA_TRANSPARENCY);

    dest_rect = {PADDING_LEFT, PADDING_TOP, surface->w, surface->h};

    SDL_FreeSurface(surface);
}

void HelpText::update() {}

void HelpText::render() {
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}
