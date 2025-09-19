#include "sdl3_wrapper/iostream.h"

#include "util.h"

std::tuple<void*, size_t> sdl3_wrapper::load_file(std::string file) {
    void* data;
    size_t data_size;
    CHECK_ERROR(data = SDL_LoadFile(file.c_str(), &data_size), "SDL_LoadFile failed: {}");
    return {data, data_size};
}
