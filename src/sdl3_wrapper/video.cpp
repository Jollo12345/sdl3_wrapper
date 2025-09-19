#include "sdl3_wrapper/video.h"

#include "util.h"

SDL_Window* sdl3_wrapper::create_window(const std::string& title, int w, int h, SDL_WindowFlags flags) {
    SDL_Window* window;
    CHECK_ERROR(window = SDL_CreateWindow(title.c_str(), w, h, flags), "SDL_CreateWindow failed: {}");
    return window;
}

void sdl3_wrapper::show_window(SDL_Window* window) {
    CHECK_ERROR(SDL_ShowWindow(window), "SDL_ShowWindow failed: {}");
}

void sdl3_wrapper::hide_window(SDL_Window* window) {
    CHECK_ERROR(SDL_HideWindow(window), "SDL_HideWindow failed: {}");
}

void sdl3_wrapper::set_window_minimum_size(SDL_Window* window, int min_w, int min_h) {
    CHECK_ERROR(SDL_SetWindowMinimumSize(window, min_w, min_h), "SDL_SetWindowMinimumSize failed: {}");
}
