#pragma once

#include <SDL3/SDL_init.h>
#include <optional>
#include <string>

namespace sdl3_wrapper {

/* Functions */

void init(
    SDL_InitFlags flags
); // SDL_Init

void init_sub_system(
    SDL_InitFlags flags
); // SDL_InitSubSystem

constexpr auto& quit_sub_system = SDL_QuitSubSystem; // SDL_QuitSubSystem
constexpr auto& was_init = SDL_WasInit; // SDL_WasInit
constexpr auto& quit = SDL_Quit; // SDL_Quit
constexpr auto& is_main_thread = SDL_IsMainThread; // SDL_IsMainThread

void run_on_main_thread(
    SDL_MainThreadCallback callback,
    void* userdata,
    bool wait_complete
); // SDL_RunOnMainThread

void set_app_metadata(
    const std::string& appname,
    const std::string& appversion,
    const std::string& appidentifier
); // SDL_SetAppMetadata

void set_app_metadata_property(
    const std::string& name,
    const std::string& value
); // SDL_SetAppMetadataProperty

std::optional<std::string> get_app_metadata_property(
    const std::string& name
); // SDL_GetAppMetadataProperty

/* Datatypes */

using app_event_func = SDL_AppEvent_func; // SDL_AppEvent_func
using app_init_func = SDL_AppInit_func; // SDL_AppInit_func
using app_iterate_func = SDL_AppIterate_func; // SDL_AppIterate_func
using app_quit_func = SDL_AppQuit_func; // SDL_AppQuit_func

enum init_flags : SDL_InitFlags {
    INIT_AUDIO = SDL_INIT_AUDIO, /**< `SDL_INIT_AUDIO` implies `SDL_INIT_EVENTS` */
    INIT_VIDEO = SDL_INIT_VIDEO, /**< `SDL_INIT_VIDEO` implies `SDL_INIT_EVENTS`, should be initialized on the main thread */
    INIT_JOYSTICK = SDL_INIT_JOYSTICK, /**< `SDL_INIT_JOYSTICK` implies `SDL_INIT_EVENTS` */
    INIT_HAPTIC = SDL_INIT_HAPTIC,
    INIT_GAMEPAD = SDL_INIT_GAMEPAD, /**< `SDL_INIT_GAMEPAD` implies `SDL_INIT_JOYSTICK` */
    INIT_EVENTS = SDL_INIT_EVENTS,
    INIT_SENSOR = SDL_INIT_SENSOR, /**< `SDL_INIT_SENSOR` implies `SDL_INIT_EVENTS` */
    INIT_CAMERA = SDL_INIT_CAMERA /**< `SDL_INIT_CAMERA` implies `SDL_INIT_EVENTS` */
}; // SDL_InitFlags

using main_thread_callback = SDL_MainThreadCallback; // SDL_MainThreadCallback

/* Structs */

/* Enums */

constexpr SDL_AppResult APP_CONTINUE = SDL_APP_CONTINUE; /**< Value that requests that the app continue from the main callbacks. */
constexpr SDL_AppResult APP_SUCCESS = SDL_APP_SUCCESS; /**< Value that requests termination with success from the main callbacks. */
constexpr SDL_AppResult APP_FAILURE = SDL_APP_FAILURE; /**< Value that requests termination with error from the main callbacks. */
using app_result = SDL_AppResult; // SDL_AppResult

/* Macros */

} // namespace sdl3_wrapper
