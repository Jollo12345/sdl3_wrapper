#pragma once

#include <SDL3/SDL_error.h>
#include <format>
#include <stdexcept>

#define CHECK_ERROR(condition, message) \
    [[unlikely]] \
    if(!(condition)) { \
        throw std::runtime_error{std::format(message, SDL_GetError())}; \
    }
