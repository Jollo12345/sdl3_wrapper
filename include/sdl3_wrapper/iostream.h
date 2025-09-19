#pragma once

#include <SDL3/SDL_iostream.h>
#include <string>
#include <tuple>

namespace sdl3_wrapper {

/* Functions */

SDL_IOStream* io_from_file(
    const char* file,
    const char* mode
); // SDL_IOFromFile

SDL_IOStream* io_from_mem(
    void* mem,
    size_t size
); // SDL_IOFromMem

SDL_IOStream* io_from_const_mem(
    const void* mem,
    size_t size
); // SDL_IOFromConstMem

SDL_IOStream* io_from_dynamic_mem(
    void
); // SDL_IOFromDynamicMem

SDL_IOStream* open_io(
    const SDL_IOStreamInterface* iface,
    void* userdata
); // SDL_OpenIO

bool close_io(
    SDL_IOStream* context
); // SDL_CloseIO

SDL_PropertiesID get_io_properties(
    SDL_IOStream* context
); // SDL_GetIOProperties

SDL_IOStatus get_io_status(
    SDL_IOStream* context
); // SDL_GetIOStatus

Sint64 get_io_size(
    SDL_IOStream* context
); // SDL_GetIOSize

Sint64 seek_io(
    SDL_IOStream* context,
    Sint64 offset,
    SDL_IOWhence whence
); // SDL_SeekIO

Sint64 tell_io(
    SDL_IOStream* context
); // SDL_TellIO

size_t read_io(
    SDL_IOStream* context,
    void* ptr,
    size_t size
); // SDL_ReadIO

size_t write_io(
    SDL_IOStream* context,
    const void* ptr,
    size_t size
); // SDL_WriteIO

size_t io_printf(
    SDL_IOStream* context,
    const char* fmt,
    ...
); // SDL_IOprintf

size_t io_vprintf(
    SDL_IOStream* context,
    const char* fmt,
    va_list ap
); // SDL_IOvprintf

bool flush_io(
    SDL_IOStream* context
); // SDL_FlushIO

void* load_file_io(
    SDL_IOStream* src,
    size_t* datasize,
    bool closeio
); // SDL_LoadFile_IO

std::tuple<void*, size_t> load_file(
    std::string file
); // SDL_LoadFile

bool save_file_io(
    SDL_IOStream* src,
    const void* data,
    size_t datasize,
    bool closeio
); // SDL_SaveFile_IO

bool save_file(
    const char* file,
    const void* data,
    size_t datasize
); // SDL_SaveFile

bool read_u8(
    SDL_IOStream* src,
    Uint8* value
); // SDL_ReadU8

bool read_s8(
    SDL_IOStream* src,
    Sint8* value
); // SDL_ReadS8

bool read_u16_le(
    SDL_IOStream* src,
    Uint16* value
); // SDL_ReadU16LE

bool read_s16_le(
    SDL_IOStream* src,
    Sint16* value
); // SDL_ReadS16LE

bool read_u16_be(
    SDL_IOStream* src,
    Uint16* value
); // SDL_ReadU16BE

bool read_s16_be(
    SDL_IOStream* src,
    Sint16* value
); // SDL_ReadS16BE

bool read_u32_le(
    SDL_IOStream* src,
    Uint32* value
); // SDL_ReadU32LE

bool read_s32_le(
    SDL_IOStream* src,
    Sint32* value
); // SDL_ReadS32LE

bool read_u32_be(
    SDL_IOStream* src,
    Uint32* value
); // SDL_ReadU32BE

bool read_s32_be(
    SDL_IOStream* src,
    Sint32* value
); // SDL_ReadS32BE

bool read_u64_le(
    SDL_IOStream* src,
    Uint64* value
); // SDL_ReadU64LE

bool read_s64_le(
    SDL_IOStream* src,
    Sint64* value
); // SDL_ReadS64LE

bool read_u64_be(
    SDL_IOStream* src,
    Uint64* value
); // SDL_ReadU64BE

bool read_s64_be(
    SDL_IOStream* src,
    Sint64* value
); // SDL_ReadS64BE

bool write_u8(
    SDL_IOStream* dst,
    Uint8 value
); // SDL_WriteU8

bool write_s8(
    SDL_IOStream* dst,
    Sint8 value
); // SDL_WriteS8

bool write_u16_le(
    SDL_IOStream* dst,
    Uint16 value
); // SDL_WriteU16LE

bool write_s16_le(
    SDL_IOStream* dst,
    Sint16 value
); // SDL_WriteS16LE

bool write_u16_be(
    SDL_IOStream* dst,
    Uint16 value
); // SDL_WriteU16BE

bool write_s16_be(
    SDL_IOStream* dst,
    Sint16 value
); // SDL_WriteS16BE

bool write_u32_le(
    SDL_IOStream* dst,
    Uint32 value
); // SDL_WriteU32LE

bool write_s32_le(
    SDL_IOStream* dst,
    Sint32 value
); // SDL_WriteS32LE

bool write_u32_be(
    SDL_IOStream* dst,
    Uint32 value
); // SDL_WriteU32BE

bool write_s32_be(
    SDL_IOStream* dst,
    Sint32 value
); // SDL_WriteS32BE

bool write_u64_le(
    SDL_IOStream* dst,
    Uint64 value
); // SDL_WriteU64LE

bool write_s64_le(
    SDL_IOStream* dst,
    Sint64 value
); // SDL_WriteS64LE

bool write_u64_be(
    SDL_IOStream* dst,
    Uint64 value
); // SDL_WriteU64BE

bool write_s64_be(
    SDL_IOStream* dst,
    Sint64 value
); // SDL_WriteS64BE

/* Datatypes */

// SDL_IOStream

/* Structs */

// SDL_IOStreamInterface

/* Enums */

// SDL_IOStatus
// SDL_IOWhence

/* Macros */

} // namespace sdl3_wrapper
