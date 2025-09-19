#include "sdl3_wrapper/init.h"

#include <util.h>

void sdl3_wrapper::init(SDL_InitFlags flags) {
    CHECK_ERROR(SDL_Init(flags), "SDL_Init failed: {}");
}

void sdl3_wrapper::init_sub_system(SDL_InitFlags flags) {
    CHECK_ERROR(SDL_InitSubSystem(flags), "SDL_InitSubSystem failed: {}");
}

void sdl3_wrapper::run_on_main_thread(SDL_MainThreadCallback callback, void* userdata, bool wait_complete) {
    CHECK_ERROR(SDL_RunOnMainThread(callback, userdata, wait_complete), "SDL_RunOnMainThread failed: {}");
}

void sdl3_wrapper::set_app_metadata(const std::string& appname, const std::string& appversion, const std::string& appidentifier) {
    CHECK_ERROR(SDL_SetAppMetadata(appname.c_str(), appversion.c_str(), appidentifier.c_str()), "SDL_SetAppMetadata failed: {}");
}

void sdl3_wrapper::set_app_metadata_property(const std::string& name, const std::string& value) {
    CHECK_ERROR(SDL_SetAppMetadataProperty(name.c_str(), value.c_str()), "SDL_SetAppMetadataProperty failed: {}");
}

std::optional<std::string> sdl3_wrapper::get_app_metadata_property(const std::string& name) {
    const char* property = SDL_GetAppMetadataProperty(name.c_str());
    if(property == NULL) {
        return {};
    }
    return {property};
}
