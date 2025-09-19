#pragma once

#include <SDL3/SDL_events.h>

namespace sdl3_wrapper {

/* Functions */

void pump_events(); // SDL_PumpEvents

int peep_events(
    SDL_Event* events,
    int numevents,
    SDL_EventAction action,
    Uint32 minType,
    Uint32 maxType
); // SDL_PeepEvents

bool has_event(
    Uint32 type
); // SDL_HasEvent

bool has_events(
    Uint32 minType,
    Uint32 maxType
); // SDL_HasEvents

void flush_event(
    Uint32 type
); // SDL_FlushEvent

void flush_events(
    Uint32 minType,
    Uint32 maxType
); // SDL_FlushEvents

bool poll_event(
    SDL_Event* event
); // SDL_PollEvent

bool wait_event(
    SDL_Event* event
); // SDL_WaitEvent

bool wait_event_timeout(
    SDL_Event* event,
    Sint32 timeoutMS
); // SDL_WaitEventTimeout

bool push_event(
    SDL_Event* event
); // SDL_PushEvent

void set_event_filter(
    SDL_EventFilter filter,
    void* userdata
); // SDL_SetEventFilter

bool get_event_filter(
    SDL_EventFilter* filter,
    void** userdata
); // SDL_GetEventFilter

bool add_event_watch(
    SDL_EventFilter filter,
    void* userdata
); // SDL_AddEventWatch

void remove_event_watch(
    SDL_EventFilter filter,
    void* userdata
); // SDL_RemoveEventWatch

void filter_events(
    SDL_EventFilter filter,
    void* userdata
); // SDL_FilterEvents

void set_event_enabled(
    Uint32 type,
    bool enabled
); // SDL_SetEventEnabled

bool event_enabled(
    Uint32 type
); // SDL_EventEnabled

Uint32 register_events(
    int numevents
); // SDL_RegisterEvents

SDL_Window* get_window_from_event(
    const SDL_Event* event
); // SDL_GetWindowFromEvent

int get_event_description(
    const SDL_Event* event,
    char* buf,
    int buflen
); // SDL_GetEventDescription

/* Datatypes */

using event_filter = SDL_EventFilter; // SDL_EventFilter

/* Structs */

using audio_device_event = SDL_AudioDeviceEvent; // SDL_AudioDeviceEvent
using camera_device_event = SDL_CameraDeviceEvent; // SDL_CameraDeviceEvent
using clipboard_event = SDL_ClipboardEvent; // SDL_ClipboardEvent
using common_event = SDL_CommonEvent; // SDL_CommonEvent
using display_event = SDL_DisplayEvent; // SDL_DisplayEvent
using drop_event = SDL_DropEvent; // SDL_DropEvent
using event = SDL_Event; // SDL_Event
using gamepad_axis_event = SDL_GamepadAxisEvent; // SDL_GamepadAxisEvent
using gamepad_button_event = SDL_GamepadButtonEvent; // SDL_GamepadButtonEvent
using gamepad_device_event = SDL_GamepadDeviceEvent; // SDL_GamepadDeviceEvent
using gamepad_sensor_event = SDL_GamepadSensorEvent; // SDL_GamepadSensorEvent
using gamepad_touchpad_event = SDL_GamepadTouchpadEvent; // SDL_GamepadTouchpadEvent
using joy_axis_event = SDL_JoyAxisEvent; // SDL_JoyAxisEvent
using joy_ball_event = SDL_JoyBallEvent; // SDL_JoyBallEvent
using joy_battery_event = SDL_JoyBatteryEvent; // SDL_JoyBatteryEvent
using joy_button_event = SDL_JoyButtonEvent; // SDL_JoyButtonEvent
using joy_device_event = SDL_JoyDeviceEvent; // SDL_JoyDeviceEvent
using joy_hat_event = SDL_JoyHatEvent; // SDL_JoyHatEvent
using keyboard_device_event = SDL_KeyboardDeviceEvent; // SDL_KeyboardDeviceEvent
using keyboard_event = SDL_KeyboardEvent; // SDL_KeyboardEvent
using mouse_button_event = SDL_MouseButtonEvent; // SDL_MouseButtonEvent
using mouse_device_event = SDL_MouseDeviceEvent; // SDL_MouseDeviceEvent
using mouse_motion_event = SDL_MouseMotionEvent; // SDL_MouseMotionEvent
using mouse_wheel_event = SDL_MouseWheelEvent; // SDL_MouseWheelEvent
using pen_axis_event = SDL_PenAxisEvent; // SDL_PenAxisEvent
using pen_button_event = SDL_PenButtonEvent; // SDL_PenButtonEvent
using pen_motion_event = SDL_PenMotionEvent; // SDL_PenMotionEvent
using pen_proximity_event = SDL_PenProximityEvent; // SDL_PenProximityEvent
using pen_touch_event = SDL_PenTouchEvent; // SDL_PenTouchEvent
using quit_event = SDL_QuitEvent; // SDL_QuitEvent
using render_event = SDL_RenderEvent; // SDL_RenderEvent
using sensor_event = SDL_SensorEvent; // SDL_SensorEvent
using text_editing_candidates_event = SDL_TextEditingCandidatesEvent; // SDL_TextEditingCandidatesEvent
using text_editing_event = SDL_TextEditingEvent; // SDL_TextEditingEvent
using text_input_event = SDL_TextInputEvent; // SDL_TextInputEvent
using touch_finger_event = SDL_TouchFingerEvent; // SDL_TouchFingerEvent
using user_event = SDL_UserEvent; // SDL_UserEvent
using window_event = SDL_WindowEvent; // SDL_WindowEvent

/* Enums */

constexpr SDL_EventAction ADDEVENT = SDL_ADDEVENT; /**< Add events to the back of the queue. */
constexpr SDL_EventAction PEEKEVENT = SDL_PEEKEVENT; /**< Check but don't remove events from the queue front. */
constexpr SDL_EventAction GETEVENT = SDL_GETEVENT; /**< Retrieve/remove events from the front of the queue. */
using event_action = SDL_EventAction; // SDL_EventAction

constexpr SDL_EventType EVENT_FIRST = SDL_EVENT_FIRST; /**< Unused (do not remove) */
/* Application events */
constexpr SDL_EventType EVENT_QUIT = SDL_EVENT_QUIT; /**< User-requested quit */
/* These application events have special meaning on iOS and Android, see README-ios.md and README-android.md for details */
constexpr SDL_EventType EVENT_TERMINATING = SDL_EVENT_TERMINATING; /**< The application is being terminated by the OS. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationWillTerminate()
Called on Android in onDestroy()
*/
constexpr SDL_EventType EVENT_LOW_MEMORY = SDL_EVENT_LOW_MEMORY; /**< The application is low on memory, free memory if possible. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationDidReceiveMemoryWarning()
Called on Android in onTrimMemory()
*/
constexpr SDL_EventType EVENT_WILL_ENTER_BACKGROUND = SDL_EVENT_WILL_ENTER_BACKGROUND; /**< The application is about to enter the background. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationWillResignActive()
Called on Android in onPause()
*/
constexpr SDL_EventType EVENT_DID_ENTER_BACKGROUND = SDL_EVENT_DID_ENTER_BACKGROUND; /**< The application did enter the background and may not get CPU for some time. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationDidEnterBackground()
Called on Android in onPause()
*/
constexpr SDL_EventType EVENT_WILL_ENTER_FOREGROUND = SDL_EVENT_WILL_ENTER_FOREGROUND; /**< The application is about to enter the foreground. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationWillEnterForeground()
Called on Android in onResume()
*/
constexpr SDL_EventType EVENT_DID_ENTER_FOREGROUND = SDL_EVENT_DID_ENTER_FOREGROUND; /**< The application is now interactive. This event must be handled in a callback set with SDL_AddEventWatch().
Called on iOS in applicationDidBecomeActive()
Called on Android in onResume()
*/
constexpr SDL_EventType EVENT_LOCALE_CHANGED = SDL_EVENT_LOCALE_CHANGED; /**< The user's locale preferences have changed. */
constexpr SDL_EventType EVENT_SYSTEM_THEME_CHANGED = SDL_EVENT_SYSTEM_THEME_CHANGED; /**< The system theme changed */
/* Display events */
/* 0x150 was constexpr SDL_EventType DISPLAYEVENT = SDL_DISPLAYEVENT; reserve the number for sdl2-compat */
constexpr SDL_EventType EVENT_DISPLAY_ORIENTATION = SDL_EVENT_DISPLAY_ORIENTATION; /**< Display orientation has changed to data1 */
constexpr SDL_EventType EVENT_DISPLAY_ADDED = SDL_EVENT_DISPLAY_ADDED; /**< Display has been added to the system */
constexpr SDL_EventType EVENT_DISPLAY_REMOVED = SDL_EVENT_DISPLAY_REMOVED; /**< Display has been removed from the system */
constexpr SDL_EventType EVENT_DISPLAY_MOVED = SDL_EVENT_DISPLAY_MOVED; /**< Display has changed position */
constexpr SDL_EventType EVENT_DISPLAY_DESKTOP_MODE_CHANGED = SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED; /**< Display has changed desktop mode */
constexpr SDL_EventType EVENT_DISPLAY_CURRENT_MODE_CHANGED = SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED; /**< Display has changed current mode */
constexpr SDL_EventType EVENT_DISPLAY_CONTENT_SCALE_CHANGED = SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED; /**< Display has changed content scale */
constexpr SDL_EventType EVENT_DISPLAY_FIRST = SDL_EVENT_DISPLAY_FIRST;
constexpr SDL_EventType EVENT_DISPLAY_LAST = SDL_EVENT_DISPLAY_LAST;
/* Window events */
/* 0x200 was constexpr SDL_EventType WINDOWEVENT = SDL_WINDOWEVENT; reserve the number for sdl2-compat */
/* 0x201 was constexpr SDL_EventType SYSWMEVENT = SDL_SYSWMEVENT; reserve the number for sdl2-compat */
constexpr SDL_EventType EVENT_WINDOW_SHOWN = SDL_EVENT_WINDOW_SHOWN; /**< Window has been shown */
constexpr SDL_EventType EVENT_WINDOW_HIDDEN = SDL_EVENT_WINDOW_HIDDEN; /**< Window has been hidden */
constexpr SDL_EventType EVENT_WINDOW_EXPOSED = SDL_EVENT_WINDOW_EXPOSED; /**< Window has been exposed and should be redrawn, and can be redrawn directly from event watchers for this event. data1 is 1 for live-resize expose events, 0 otherwise. */
constexpr SDL_EventType EVENT_WINDOW_MOVED = SDL_EVENT_WINDOW_MOVED; /**< Window has been moved to data1, data2 */
constexpr SDL_EventType EVENT_WINDOW_RESIZED = SDL_EVENT_WINDOW_RESIZED; /**< Window has been resized to data1xdata2 */
constexpr SDL_EventType EVENT_WINDOW_PIXEL_SIZE_CHANGED = SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED; /**< The pixel size of the window has changed to data1xdata2 */
constexpr SDL_EventType EVENT_WINDOW_METAL_VIEW_RESIZED = SDL_EVENT_WINDOW_METAL_VIEW_RESIZED; /**< The pixel size of a Metal view associated with the window has changed */
constexpr SDL_EventType EVENT_WINDOW_MINIMIZED = SDL_EVENT_WINDOW_MINIMIZED; /**< Window has been minimized */
constexpr SDL_EventType EVENT_WINDOW_MAXIMIZED = SDL_EVENT_WINDOW_MAXIMIZED; /**< Window has been maximized */
constexpr SDL_EventType EVENT_WINDOW_RESTORED = SDL_EVENT_WINDOW_RESTORED; /**< Window has been restored to normal size and position */
constexpr SDL_EventType EVENT_WINDOW_MOUSE_ENTER = SDL_EVENT_WINDOW_MOUSE_ENTER; /**< Window has gained mouse focus */
constexpr SDL_EventType EVENT_WINDOW_MOUSE_LEAVE = SDL_EVENT_WINDOW_MOUSE_LEAVE; /**< Window has lost mouse focus */
constexpr SDL_EventType EVENT_WINDOW_FOCUS_GAINED = SDL_EVENT_WINDOW_FOCUS_GAINED; /**< Window has gained keyboard focus */
constexpr SDL_EventType EVENT_WINDOW_FOCUS_LOST = SDL_EVENT_WINDOW_FOCUS_LOST; /**< Window has lost keyboard focus */
constexpr SDL_EventType EVENT_WINDOW_CLOSE_REQUESTED = SDL_EVENT_WINDOW_CLOSE_REQUESTED; /**< The window manager requests that the window be closed */
constexpr SDL_EventType EVENT_WINDOW_HIT_TEST = SDL_EVENT_WINDOW_HIT_TEST; /**< Window had a hit test that wasn't SDL_HITTEST_NORMAL */
constexpr SDL_EventType EVENT_WINDOW_ICCPROF_CHANGED = SDL_EVENT_WINDOW_ICCPROF_CHANGED; /**< The ICC profile of the window's display has changed */
constexpr SDL_EventType EVENT_WINDOW_DISPLAY_CHANGED = SDL_EVENT_WINDOW_DISPLAY_CHANGED; /**< Window has been moved to display data1 */
constexpr SDL_EventType EVENT_WINDOW_DISPLAY_SCALE_CHANGED = SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED; /**< Window display scale has been changed */
constexpr SDL_EventType EVENT_WINDOW_SAFE_AREA_CHANGED = SDL_EVENT_WINDOW_SAFE_AREA_CHANGED; /**< The window safe area has been changed */
constexpr SDL_EventType EVENT_WINDOW_OCCLUDED = SDL_EVENT_WINDOW_OCCLUDED; /**< The window has been occluded */
constexpr SDL_EventType EVENT_WINDOW_ENTER_FULLSCREEN = SDL_EVENT_WINDOW_ENTER_FULLSCREEN; /**< The window has entered fullscreen mode */
constexpr SDL_EventType EVENT_WINDOW_LEAVE_FULLSCREEN = SDL_EVENT_WINDOW_LEAVE_FULLSCREEN; /**< The window has left fullscreen mode */
constexpr SDL_EventType EVENT_WINDOW_DESTROYED = SDL_EVENT_WINDOW_DESTROYED; /**< The window with the associated ID is being or has been destroyed. If this message is being handled in an event watcher, the window handle is still valid and can still be used to retrieve any properties associated with the window. Otherwise, the handle has already been destroyed and all resources associated with it are invalid */
constexpr SDL_EventType EVENT_WINDOW_HDR_STATE_CHANGED = SDL_EVENT_WINDOW_HDR_STATE_CHANGED; /**< Window HDR properties have changed */
constexpr SDL_EventType EVENT_WINDOW_FIRST = SDL_EVENT_WINDOW_FIRST;
constexpr SDL_EventType EVENT_WINDOW_LAST = SDL_EVENT_WINDOW_LAST;
/* Keyboard events */
constexpr SDL_EventType EVENT_KEY_DOWN = SDL_EVENT_KEY_DOWN; /**< Key pressed */
constexpr SDL_EventType EVENT_KEY_UP = SDL_EVENT_KEY_UP; /**< Key released */
constexpr SDL_EventType EVENT_TEXT_EDITING = SDL_EVENT_TEXT_EDITING; /**< Keyboard text editing (composition) */
constexpr SDL_EventType EVENT_TEXT_INPUT = SDL_EVENT_TEXT_INPUT; /**< Keyboard text input */
constexpr SDL_EventType EVENT_KEYMAP_CHANGED = SDL_EVENT_KEYMAP_CHANGED; /**< Keymap changed due to a system event such as an input language or keyboard layout change. */
constexpr SDL_EventType EVENT_KEYBOARD_ADDED = SDL_EVENT_KEYBOARD_ADDED; /**< A new keyboard has been inserted into the system */
constexpr SDL_EventType EVENT_KEYBOARD_REMOVED = SDL_EVENT_KEYBOARD_REMOVED; /**< A keyboard has been removed */
constexpr SDL_EventType EVENT_TEXT_EDITING_CANDIDATES = SDL_EVENT_TEXT_EDITING_CANDIDATES; /**< Keyboard text editing candidates */
/* Mouse events */
constexpr SDL_EventType EVENT_MOUSE_MOTION = SDL_EVENT_MOUSE_MOTION; /**< Mouse moved */
constexpr SDL_EventType EVENT_MOUSE_BUTTON_DOWN = SDL_EVENT_MOUSE_BUTTON_DOWN; /**< Mouse button pressed */
constexpr SDL_EventType EVENT_MOUSE_BUTTON_UP = SDL_EVENT_MOUSE_BUTTON_UP; /**< Mouse button released */
constexpr SDL_EventType EVENT_MOUSE_WHEEL = SDL_EVENT_MOUSE_WHEEL; /**< Mouse wheel motion */
constexpr SDL_EventType EVENT_MOUSE_ADDED = SDL_EVENT_MOUSE_ADDED; /**< A new mouse has been inserted into the system */
constexpr SDL_EventType EVENT_MOUSE_REMOVED = SDL_EVENT_MOUSE_REMOVED; /**< A mouse has been removed */
/* Joystick events */
constexpr SDL_EventType EVENT_JOYSTICK_AXIS_MOTION = SDL_EVENT_JOYSTICK_AXIS_MOTION; /**< Joystick axis motion */
constexpr SDL_EventType EVENT_JOYSTICK_BALL_MOTION = SDL_EVENT_JOYSTICK_BALL_MOTION; /**< Joystick trackball motion */
constexpr SDL_EventType EVENT_JOYSTICK_HAT_MOTION = SDL_EVENT_JOYSTICK_HAT_MOTION; /**< Joystick hat position change */
constexpr SDL_EventType EVENT_JOYSTICK_BUTTON_DOWN = SDL_EVENT_JOYSTICK_BUTTON_DOWN; /**< Joystick button pressed */
constexpr SDL_EventType EVENT_JOYSTICK_BUTTON_UP = SDL_EVENT_JOYSTICK_BUTTON_UP; /**< Joystick button released */
constexpr SDL_EventType EVENT_JOYSTICK_ADDED = SDL_EVENT_JOYSTICK_ADDED; /**< A new joystick has been inserted into the system */
constexpr SDL_EventType EVENT_JOYSTICK_REMOVED = SDL_EVENT_JOYSTICK_REMOVED; /**< An opened joystick has been removed */
constexpr SDL_EventType EVENT_JOYSTICK_BATTERY_UPDATED = SDL_EVENT_JOYSTICK_BATTERY_UPDATED; /**< Joystick battery level change */
constexpr SDL_EventType EVENT_JOYSTICK_UPDATE_COMPLETE = SDL_EVENT_JOYSTICK_UPDATE_COMPLETE; /**< Joystick update is complete */
/* Gamepad events */
constexpr SDL_EventType EVENT_GAMEPAD_AXIS_MOTION = SDL_EVENT_GAMEPAD_AXIS_MOTION; /**< Gamepad axis motion */
constexpr SDL_EventType EVENT_GAMEPAD_BUTTON_DOWN = SDL_EVENT_GAMEPAD_BUTTON_DOWN; /**< Gamepad button pressed */
constexpr SDL_EventType EVENT_GAMEPAD_BUTTON_UP = SDL_EVENT_GAMEPAD_BUTTON_UP; /**< Gamepad button released */
constexpr SDL_EventType EVENT_GAMEPAD_ADDED = SDL_EVENT_GAMEPAD_ADDED; /**< A new gamepad has been inserted into the system */
constexpr SDL_EventType EVENT_GAMEPAD_REMOVED = SDL_EVENT_GAMEPAD_REMOVED; /**< A gamepad has been removed */
constexpr SDL_EventType EVENT_GAMEPAD_REMAPPED = SDL_EVENT_GAMEPAD_REMAPPED; /**< The gamepad mapping was updated */
constexpr SDL_EventType EVENT_GAMEPAD_TOUCHPAD_DOWN = SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN; /**< Gamepad touchpad was touched */
constexpr SDL_EventType EVENT_GAMEPAD_TOUCHPAD_MOTION = SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION; /**< Gamepad touchpad finger was moved */
constexpr SDL_EventType EVENT_GAMEPAD_TOUCHPAD_UP = SDL_EVENT_GAMEPAD_TOUCHPAD_UP; /**< Gamepad touchpad finger was lifted */
constexpr SDL_EventType EVENT_GAMEPAD_SENSOR_UPDATE = SDL_EVENT_GAMEPAD_SENSOR_UPDATE; /**< Gamepad sensor was updated */
constexpr SDL_EventType EVENT_GAMEPAD_UPDATE_COMPLETE = SDL_EVENT_GAMEPAD_UPDATE_COMPLETE; /**< Gamepad update is complete */
constexpr SDL_EventType EVENT_GAMEPAD_STEAM_HANDLE_UPDATED = SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED; /**< Gamepad Steam handle has changed */
/* Touch events */
constexpr SDL_EventType EVENT_FINGER_DOWN = SDL_EVENT_FINGER_DOWN;
constexpr SDL_EventType EVENT_FINGER_UP = SDL_EVENT_FINGER_UP;
constexpr SDL_EventType EVENT_FINGER_MOTION = SDL_EVENT_FINGER_MOTION;
constexpr SDL_EventType EVENT_FINGER_CANCELED = SDL_EVENT_FINGER_CANCELED;
/* 0x800, 0x801, and 0x802 were the Gesture events from SDL2. Do not reuse these values! sdl2-compat needs them! */
/* Clipboard events */
constexpr SDL_EventType EVENT_CLIPBOARD_UPDATE = SDL_EVENT_CLIPBOARD_UPDATE; /**< The clipboard or primary selection changed */
/* Drag and drop events */
constexpr SDL_EventType EVENT_DROP_FILE = SDL_EVENT_DROP_FILE; /**< The system requests a file open */
constexpr SDL_EventType EVENT_DROP_TEXT = SDL_EVENT_DROP_TEXT; /**< text/plain drag-and-drop event */
constexpr SDL_EventType EVENT_DROP_BEGIN = SDL_EVENT_DROP_BEGIN; /**< A new set of drops is beginning (NULL filename) */
constexpr SDL_EventType EVENT_DROP_COMPLETE = SDL_EVENT_DROP_COMPLETE; /**< Current set of drops is now complete (NULL filename) */
constexpr SDL_EventType EVENT_DROP_POSITION = SDL_EVENT_DROP_POSITION; /**< Position while moving over the window */
/* Audio hotplug events */
constexpr SDL_EventType EVENT_AUDIO_DEVICE_ADDED = SDL_EVENT_AUDIO_DEVICE_ADDED; /**< A new audio device is available */
constexpr SDL_EventType EVENT_AUDIO_DEVICE_REMOVED = SDL_EVENT_AUDIO_DEVICE_REMOVED; /**< An audio device has been removed. */
constexpr SDL_EventType EVENT_AUDIO_DEVICE_FORMAT_CHANGED = SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED; /**< An audio device's format has been changed by the system. */
/* Sensor events */
constexpr SDL_EventType EVENT_SENSOR_UPDATE = SDL_EVENT_SENSOR_UPDATE; /**< A sensor was updated */
/* Pressure-sensitive pen events */
constexpr SDL_EventType EVENT_PEN_PROXIMITY_IN = SDL_EVENT_PEN_PROXIMITY_IN; /**< Pressure-sensitive pen has become available */
constexpr SDL_EventType EVENT_PEN_PROXIMITY_OUT = SDL_EVENT_PEN_PROXIMITY_OUT; /**< Pressure-sensitive pen has become unavailable */
constexpr SDL_EventType EVENT_PEN_DOWN = SDL_EVENT_PEN_DOWN; /**< Pressure-sensitive pen touched drawing surface */
constexpr SDL_EventType EVENT_PEN_UP = SDL_EVENT_PEN_UP; /**< Pressure-sensitive pen stopped touching drawing surface */
constexpr SDL_EventType EVENT_PEN_BUTTON_DOWN = SDL_EVENT_PEN_BUTTON_DOWN; /**< Pressure-sensitive pen button pressed */
constexpr SDL_EventType EVENT_PEN_BUTTON_UP = SDL_EVENT_PEN_BUTTON_UP; /**< Pressure-sensitive pen button released */
constexpr SDL_EventType EVENT_PEN_MOTION = SDL_EVENT_PEN_MOTION; /**< Pressure-sensitive pen is moving on the tablet */
constexpr SDL_EventType EVENT_PEN_AXIS = SDL_EVENT_PEN_AXIS; /**< Pressure-sensitive pen angle/pressure/etc changed */
/* Camera hotplug events */
constexpr SDL_EventType EVENT_CAMERA_DEVICE_ADDED = SDL_EVENT_CAMERA_DEVICE_ADDED; /**< A new camera device is available */
constexpr SDL_EventType EVENT_CAMERA_DEVICE_REMOVED = SDL_EVENT_CAMERA_DEVICE_REMOVED; /**< A camera device has been removed. */
constexpr SDL_EventType EVENT_CAMERA_DEVICE_APPROVED = SDL_EVENT_CAMERA_DEVICE_APPROVED; /**< A camera device has been approved for use by the user. */
constexpr SDL_EventType EVENT_CAMERA_DEVICE_DENIED = SDL_EVENT_CAMERA_DEVICE_DENIED; /**< A camera device has been denied for use by the user. */
/* Render events */
constexpr SDL_EventType EVENT_RENDER_TARGETS_RESET = SDL_EVENT_RENDER_TARGETS_RESET; /**< The render targets have been reset and their contents need to be updated */
constexpr SDL_EventType EVENT_RENDER_DEVICE_RESET = SDL_EVENT_RENDER_DEVICE_RESET; /**< The device has been reset and all textures need to be recreated */
constexpr SDL_EventType EVENT_RENDER_DEVICE_LOST = SDL_EVENT_RENDER_DEVICE_LOST; /**< The device has been lost and can't be recovered. */
/* Reserved events for private platforms */
constexpr SDL_EventType EVENT_PRIVATE0 = SDL_EVENT_PRIVATE0;
constexpr SDL_EventType EVENT_PRIVATE1 = SDL_EVENT_PRIVATE1;
constexpr SDL_EventType EVENT_PRIVATE2 = SDL_EVENT_PRIVATE2;
constexpr SDL_EventType EVENT_PRIVATE3 = SDL_EVENT_PRIVATE3;
/* Internal events */
constexpr SDL_EventType EVENT_POLL_SENTINEL = SDL_EVENT_POLL_SENTINEL; /**< Signals the end of an event poll cycle */
/** Events SDL_EVENT_USER through SDL_EVENT_LAST are for your use,
 *  and should be allocated with SDL_RegisterEvents()
 */
constexpr SDL_EventType EVENT_USER = SDL_EVENT_USER;
/**
 *  This last event is only for bounding internal arrays
 */
constexpr SDL_EventType EVENT_LAST = SDL_EVENT_LAST;
/* This just makes sure the enum is the size of Uint32 */
constexpr SDL_EventType EVENT_ENUM_PADDING = SDL_EVENT_ENUM_PADDING;
using event_type = SDL_EventType; // SDL_EventType

/* Macros */

} // namespace sdl3_wrapper
