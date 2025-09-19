#pragma once

#include <SDL3/SDL_gpu.h>
#include <spdlog/spdlog.h>

namespace sdl3_wrapper {
/* Functions */

int get_num_video_drivers(); // SDL_GetNumVideoDrivers

const char* get_video_driver(
    int index
); // SDL_GetVideoDriver

const char* get_current_video_driver(); // SDL_GetCurrentVideoDriver

SDL_SystemTheme get_system_theme(); // SDL_GetSystemTheme

SDL_DisplayID* get_displays(
    int* count
); // SDL_GetDisplays

SDL_DisplayID get_primary_display(); // SDL_GetPrimaryDisplay
SDL_PropertiesID get_display_properties(
    SDL_DisplayID displayID
); // SDL_GetDisplayProperties

const char* get_display_name(
    SDL_DisplayID displayID
); // SDL_GetDisplayName

bool get_display_bounds(
    SDL_DisplayID displayID,
    SDL_Rect* rect
); // SDL_GetDisplayBounds

bool get_display_usable_bounds(
    SDL_DisplayID displayID,
    SDL_Rect* rect
); // SDL_GetDisplayUsableBounds

SDL_DisplayOrientation get_natural_display_orientation(
    SDL_DisplayID displayID
); // SDL_GetNaturalDisplayOrientation

SDL_DisplayOrientation get_current_display_orientation(
    SDL_DisplayID displayID
); // SDL_GetCurrentDisplayOrientation

float get_display_content_scale(
    SDL_DisplayID displayID
); // SDL_GetDisplayContentScale

SDL_DisplayMode** get_fullscreen_display_modes(
    SDL_DisplayID displayID,
    int* count
); // SDL_GetFullscreenDisplayModes

bool get_closest_fullscreen_display_mode(
    SDL_DisplayID displayID,
    int w,
    int h,
    float refresh_rate,
    bool include_high_density_modes,
    SDL_DisplayMode* closest
); // SDL_GetClosestFullscreenDisplayMode

const SDL_DisplayMode* get_desktop_display_mode(
    SDL_DisplayID displayID
); // SDL_GetDesktopDisplayMode

const SDL_DisplayMode* get_current_display_mode(
    SDL_DisplayID displayID
); // SDL_GetCurrentDisplayMode

SDL_DisplayID get_display_for_point(
    const SDL_Point* point
); // SDL_GetDisplayForPoint

SDL_DisplayID get_display_for_rect(
    const SDL_Rect* rect
); // SDL_GetDisplayForRect

SDL_DisplayID get_display_for_window(
    SDL_Window* window
); // SDL_GetDisplayForWindow

float get_window_pixel_density(
    SDL_Window* window
); // SDL_GetWindowPixelDensity

float get_window_display_scale(
    SDL_Window* window
); // SDL_GetWindowDisplayScale

bool set_window_fullscreen_mode(
    SDL_Window* window,
    const SDL_DisplayMode* mode
); // SDL_SetWindowFullscreenMode

const SDL_DisplayMode* get_window_fullscreen_mode(
    SDL_Window* window
); // SDL_GetWindowFullscreenMode

void* get_window_icc_profile(
    SDL_Window* window,
    size_t* size
); // SDL_GetWindowICCProfile

SDL_PixelFormat get_window_pixel_format(
    SDL_Window* window
); // SDL_GetWindowPixelFormat

SDL_Window** get_windows(
    int* count
); // SDL_GetWindows

SDL_Window* create_window(
    const std::string& title,
    int w,
    int h,
    SDL_WindowFlags flags
); // SDL_CreateWindow

SDL_Window* create_popup_window(
    SDL_Window* parent,
    int offset_x,
    int offset_y,
    int w,
    int h,
    SDL_WindowFlags flags
); // SDL_CreatePopupWindow

SDL_Window* create_window_with_properties(
    SDL_PropertiesID props
); // SDL_CreateWindowWithProperties

SDL_WindowID get_window_id(
    SDL_Window* window
); // SDL_GetWindowID

SDL_Window* get_window_from_id(
    SDL_WindowID id
); // SDL_GetWindowFromID

SDL_Window* get_window_parent(
    SDL_Window* window
); // SDL_GetWindowParent

SDL_PropertiesID get_window_properties(
    SDL_Window* window
); // SDL_GetWindowProperties

SDL_WindowFlags get_window_flags(
    SDL_Window* window
); // SDL_GetWindowFlags

bool set_window_title(
    SDL_Window* window,
    const char* title
); // SDL_SetWindowTitle

const char* get_window_title(
    SDL_Window* window
); // SDL_GetWindowTitle

bool set_window_icon(
    SDL_Window* window,
    SDL_Surface* icon
); // SDL_SetWindowIcon

bool set_window_position(
    SDL_Window* window,
    int x,
    int y
); // SDL_SetWindowPosition

bool get_window_position(
    SDL_Window* window,
    int* x,
    int* y
); // SDL_GetWindowPosition

bool set_window_size(
    SDL_Window* window,
    int w,
    int h
); // SDL_SetWindowSize

bool get_window_size(
    SDL_Window* window,
    int* w,
    int* h
); // SDL_GetWindowSize

bool get_window_safe_area(
    SDL_Window* window,
    SDL_Rect* rect
); // SDL_GetWindowSafeArea

bool set_window_aspect_ratio(
    SDL_Window* window,
    float min_aspect,
    float max_aspect
); // SDL_SetWindowAspectRatio

bool get_window_aspect_ratio(
    SDL_Window* window,
    float* min_aspect,
    float* max_aspect
); // SDL_GetWindowAspectRatio

bool get_window_borders_size(
    SDL_Window* window,
    int* top,
    int* left,
    int* bottom,
    int* right
); // SDL_GetWindowBordersSize

bool get_window_size_in_pixels(
    SDL_Window* window,
    int* w,
    int* h
); // SDL_GetWindowSizeInPixels

void set_window_minimum_size(
    SDL_Window* window,
    int min_w,
    int min_h
); // SDL_SetWindowMinimumSize

bool get_window_minimum_size(
    SDL_Window* window,
    int* w,
    int* h
); // SDL_GetWindowMinimumSize

bool set_window_maximum_size(
    SDL_Window* window,
    int max_w,
    int max_h
); // SDL_SetWindowMaximumSize

bool get_window_maximum_size(
    SDL_Window* window,
    int* w,
    int* h
); // SDL_GetWindowMaximumSize

bool set_window_bordered(
    SDL_Window* window,
    bool bordered
); // SDL_SetWindowBordered

bool set_window_resizable(
    SDL_Window* window,
    bool resizable
); // SDL_SetWindowResizable

bool set_window_always_on_top(
    SDL_Window* window,
    bool on_top
); // SDL_SetWindowAlwaysOnTop

void show_window(
    SDL_Window* window
); // SDL_ShowWindow

void hide_window(
    SDL_Window* window
); // SDL_HideWindow

bool raise_window(
    SDL_Window* window
); // SDL_RaiseWindow

bool maximize_window(
    SDL_Window* window
); // SDL_MaximizeWindow

bool minimize_window(
    SDL_Window* window
); // SDL_MinimizeWindow

bool restore_window(
    SDL_Window* window
); // SDL_RestoreWindow

bool set_window_fullscreen(
    SDL_Window* window,
    bool fullscreen
); // SDL_SetWindowFullscreen

bool sync_window(
    SDL_Window* window
); // SDL_SyncWindow

bool window_has_surface(
    SDL_Window* window
); // SDL_WindowHasSurface

SDL_Surface* get_window_surface(
    SDL_Window* window
); // SDL_GetWindowSurface

bool set_window_surface_v_sync(
    SDL_Window* window,
    int vsync
); // SDL_SetWindowSurfaceVSync

bool get_window_surface_v_sync(
    SDL_Window* window,
    int* vsync
); // SDL_GetWindowSurfaceVSync

bool update_window_surface(
    SDL_Window* window
); // SDL_UpdateWindowSurface

bool update_window_surface_rects(
    SDL_Window* window,
    const SDL_Rect* rects,
    int numrects
); // SDL_UpdateWindowSurfaceRects

bool destroy_window_surface(
    SDL_Window* window
); // SDL_DestroyWindowSurface

bool set_window_keyboard_grab(
    SDL_Window* window,
    bool grabbed
); // SDL_SetWindowKeyboardGrab

bool set_window_mouse_grab(
    SDL_Window* window,
    bool grabbed
); // SDL_SetWindowMouseGrab

bool get_window_keyboard_grab(
    SDL_Window* window
); // SDL_GetWindowKeyboardGrab

bool get_window_mouse_grab(
    SDL_Window* window
); // SDL_GetWindowMouseGrab

SDL_Window* get_grabbed_window(
    void
); // SDL_GetGrabbedWindow

bool set_window_mouse_rect(
    SDL_Window* window,
    const SDL_Rect* rect
); // SDL_SetWindowMouseRect

const SDL_Rect* get_window_mouse_rect(
    SDL_Window* window
); // SDL_GetWindowMouseRect

bool set_window_opacity(
    SDL_Window* window,
    float opacity
); // SDL_SetWindowOpacity

float get_window_opacity(
    SDL_Window* window
); // SDL_GetWindowOpacity

bool set_window_parent(
    SDL_Window* window,
    SDL_Window* parent
); // SDL_SetWindowParent

bool set_window_modal(
    SDL_Window* window,
    bool modal
); // SDL_SetWindowModal

bool set_window_focusable(
    SDL_Window* window,
    bool focusable
); // SDL_SetWindowFocusable

bool show_window_system_menu(
    SDL_Window* window,
    int x,
    int y
); // SDL_ShowWindowSystemMenu

bool set_window_hit_test(
    SDL_Window* window,
    SDL_HitTest callback,
    void* callback_data
); // SDL_SetWindowHitTest

bool set_window_shape(
    SDL_Window* window,
    SDL_Surface* shape
); // SDL_SetWindowShape

bool flash_window(
    SDL_Window* window,
    SDL_FlashOperation operation
); // SDL_FlashWindow

bool set_window_progress_value(
    SDL_Window* window,
    float value
); // SDL_SetWindowProgressValue

float get_window_progress_value(
    SDL_Window* window
); // SDL_GetWindowProgressValue

constexpr auto& destroy_window = SDL_DestroyWindow; // SDL_DestroyWindow

bool screen_saver_enabled(
    void
); // SDL_ScreenSaverEnabled

bool enable_screen_saver(
    void
); // SDL_EnableScreenSaver

bool disable_screen_saver(
    void
); // SDL_DisableScreenSaver

bool gl_load_library(
    const char* path
); // SDL_GL_LoadLibrary

SDL_FunctionPointer gl_get_proc_address(
    const char* proc
); // SDL_GL_GetProcAddress

SDL_FunctionPointer egl_get_proc_address(
    const char* proc
); // SDL_EGL_GetProcAddress

void gl_unload_library(); // SDL_GL_UnloadLibrary

bool gl_extension_supported(
    const char* extension
); // SDL_GL_ExtensionSupported

void gl_reset_attributes(); // SDL_GL_ResetAttributes

bool gl_set_attribute(
    SDL_GLAttr attr,
    int value
); // SDL_GL_SetAttribute

bool gl_get_attribute(
    SDL_GLAttr attr,
    int* value
); // SDL_GL_GetAttribute

SDL_GLContext gl_create_context(
    SDL_Window* window
); // SDL_GL_CreateContext

bool gl_make_current(
    SDL_Window* window,
    SDL_GLContext context
); // SDL_GL_MakeCurrent

SDL_Window* gl_get_current_window(); // SDL_GL_GetCurrentWindow

SDL_GLContext gl_get_current_context(); // SDL_GL_GetCurrentContext

SDL_EGLDisplay egl_get_current_display(); // SDL_EGL_GetCurrentDisplay

SDL_EGLConfig egl_get_current_config(); // SDL_EGL_GetCurrentConfig

SDL_EGLSurface egl_get_window_surface(
    SDL_Window* window
); // SDL_EGL_GetWindowSurface

void egl_set_attribute_callbacks(
    SDL_EGLAttribArrayCallback platformAttribCallback,
    SDL_EGLIntArrayCallback surfaceAttribCallback,
    SDL_EGLIntArrayCallback contextAttribCallback,
    void* userdata
); // SDL_EGL_SetAttributeCallbacks

bool gl_set_swap_interval(
    int interval
); // SDL_GL_SetSwapInterval

bool gl_get_swap_interval(
    int* interval
); // SDL_GL_GetSwapInterval

bool gl_swap_window(
    SDL_Window* window
); // SDL_GL_SwapWindow

bool gl_destroy_context(
    SDL_GLContext context
); // SDL_GL_DestroyContext

/* Datatypes */

using display_id = SDL_DisplayID; // SDL_DisplayID
using display_mode_data = SDL_DisplayModeData; // SDL_DisplayModeData
using egl_attrib = SDL_EGLAttrib; // SDL_EGLAttrib
using egl_attrib_array_callback = SDL_EGLAttribArrayCallback; // SDL_EGLAttribArrayCallback
using egl_config = SDL_EGLConfig; // SDL_EGLConfig
using egl_display = SDL_EGLDisplay; // SDL_EGLDisplay
using eg_lint = SDL_EGLint; // SDL_EGLint
using egl_int_array_callback = SDL_EGLIntArrayCallback; // SDL_EGLIntArrayCallback
using egl_surface = SDL_EGLSurface; // SDL_EGLSurface
using gl_context = SDL_GLContext; // SDL_GLContext
using gl_context_flag = SDL_GLContextFlag; // SDL_GLContextFlag
using gl_context_release_flag = SDL_GLContextReleaseFlag; // SDL_GLContextReleaseFlag
using gl_context_reset_notification = SDL_GLContextResetNotification; // SDL_GLContextResetNotification
using gl_profile = SDL_GLProfile; // SDL_GLProfile
using hit_test = SDL_HitTest; // SDL_HitTest
using window = SDL_Window; // SDL_Window

enum window_flags : SDL_WindowFlags {
    WINDOW_FULLSCREEN = SDL_WINDOW_FULLSCREEN, /**< window is in fullscreen mode */
    WINDOW_OPENGL = SDL_WINDOW_OPENGL, /**< window usable with OpenGL context */
    WINDOW_OCCLUDED = SDL_WINDOW_OCCLUDED, /**< window is occluded */
    WINDOW_HIDDEN = SDL_WINDOW_HIDDEN, /**< window is neither mapped onto the desktop nor shown in the taskbar/dock/window list; SDL_ShowWindow() is required for it to become visible */
    WINDOW_BORDERLESS = SDL_WINDOW_BORDERLESS, /**< no window decoration */
    WINDOW_RESIZABLE = SDL_WINDOW_RESIZABLE, /**< window can be resized */
    WINDOW_MINIMIZED = SDL_WINDOW_MINIMIZED, /**< window is minimized */
    WINDOW_MAXIMIZED = SDL_WINDOW_MAXIMIZED, /**< window is maximized */
    WINDOW_MOUSE_GRABBED = SDL_WINDOW_MOUSE_GRABBED, /**< window has grabbed mouse input */
    WINDOW_INPUT_FOCUS = SDL_WINDOW_INPUT_FOCUS, /**< window has input focus */
    WINDOW_MOUSE_FOCUS = SDL_WINDOW_MOUSE_FOCUS, /**< window has mouse focus */
    WINDOW_EXTERNAL = SDL_WINDOW_EXTERNAL, /**< window not created by SDL */
    WINDOW_MODAL = SDL_WINDOW_MODAL, /**< window is modal */
    WINDOW_HIGH_PIXEL_DENSITY = SDL_WINDOW_HIGH_PIXEL_DENSITY, /**< window uses high pixel density back buffer if possible */
    WINDOW_MOUSE_CAPTURE = SDL_WINDOW_MOUSE_CAPTURE, /**< window has mouse captured (unrelated to MOUSE_GRABBED) */
    WINDOW_MOUSE_RELATIVE_MODE = SDL_WINDOW_MOUSE_RELATIVE_MODE, /**< window has relative mode enabled */
    WINDOW_ALWAYS_ON_TOP = SDL_WINDOW_ALWAYS_ON_TOP, /**< window should always be above others */
    WINDOW_UTILITY = SDL_WINDOW_UTILITY, /**< window should be treated as a utility window, not showing in the task bar and window list */
    WINDOW_TOOLTIP = SDL_WINDOW_TOOLTIP, /**< window should be treated as a tooltip and does not get mouse or keyboard focus, requires a parent window */
    WINDOW_POPUP_MENU = SDL_WINDOW_POPUP_MENU, /**< window should be treated as a popup menu, requires a parent window */
    WINDOW_KEYBOARD_GRABBED = SDL_WINDOW_KEYBOARD_GRABBED, /**< window has grabbed keyboard input */
    WINDOW_VULKAN = SDL_WINDOW_VULKAN, /**< window usable for Vulkan surface */
    WINDOW_METAL = SDL_WINDOW_METAL, /**< window usable for Metal view */
    WINDOW_TRANSPARENT = SDL_WINDOW_TRANSPARENT, /**< window with transparent buffer */
    WINDOW_NOT_FOCUSABLE = SDL_WINDOW_NOT_FOCUSABLE, /**< window should not be focusable */
}; // SDL_WindowFlags

using window_id = SDL_WindowID; // SDL_WindowID

/* Structs */

using display_mode = SDL_DisplayMode; // SDL_DisplayMode

/* Enums */

namespace {
constexpr SDL_DisplayOrientation ORIENTATION_UNKNOWN = SDL_ORIENTATION_UNKNOWN; /**< The display orientation can't be determined */
constexpr SDL_DisplayOrientation ORIENTATION_LANDSCAPE = SDL_ORIENTATION_LANDSCAPE; /**< The display is in landscape mode, with the right side up, relative to portrait mode */
constexpr SDL_DisplayOrientation ORIENTATION_LANDSCAPE_FLIPPED = SDL_ORIENTATION_LANDSCAPE_FLIPPED; /**< The display is in landscape mode, with the left side up, relative to portrait mode */
constexpr SDL_DisplayOrientation ORIENTATION_PORTRAIT = SDL_ORIENTATION_PORTRAIT; /**< The display is in portrait mode */
constexpr SDL_DisplayOrientation ORIENTATION_PORTRAIT_FLIPPED = SDL_ORIENTATION_PORTRAIT_FLIPPED; /**< The display is in portrait mode, upside down */
using display_orientation = SDL_DisplayOrientation;
} // SDL_DisplayOrientation

// SDL_FlashOperation

// SDL_GLAttr

// SDL_HitTestResult
// SDL_ProgressState
// SDL_SystemTheme

/* Macros */

// SDL_PROP_GLOBAL_VIDEO_WAYLAND_WL_DISPLAY_POINTER

// SDL_WINDOWPOS_CENTERED
// SDL_WINDOWPOS_CENTERED_DISPLAY
// SDL_WINDOWPOS_CENTERED_MASK
// SDL_WINDOWPOS_ISCENTERED
// SDL_WINDOWPOS_ISUNDEFINED
// SDL_WINDOWPOS_UNDEFINED
// SDL_WINDOWPOS_UNDEFINED_DISPLAY
// SDL_WINDOWPOS_UNDEFINED_MASK

} // namespace sdl3_wrapper
