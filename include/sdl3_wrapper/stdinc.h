#pragma once

#include <SDL3/SDL_iostream.h>

namespace sdl3_wrapper {

/* Functions */

void* malloc(
    size_t size
); // SDL_malloc

void* calloc(
    size_t nmemb,
    size_t size
); // SDL_calloc

void* realloc(
    void* mem,
    size_t size
); // SDL_realloc

constexpr auto& free = SDL_free; // SDL_free

void get_original_memory_functions(
    SDL_malloc_func* malloc_func,
    SDL_calloc_func* calloc_func,
    SDL_realloc_func* realloc_func,
    SDL_free_func* free_func
); // SDL_GetOriginalMemoryFunctions

void get_memory_functions(
    SDL_malloc_func* malloc_func,
    SDL_calloc_func* calloc_func,
    SDL_realloc_func* realloc_func,
    SDL_free_func* free_func
); // SDL_GetMemoryFunctions

bool set_memory_functions(
    SDL_malloc_func malloc_func,
    SDL_calloc_func calloc_func,
    SDL_realloc_func realloc_func,
    SDL_free_func free_func
); // SDL_SetMemoryFunctions

void* aligned_alloc(
    size_t alignment,
    size_t size
); // SDL_aligned_alloc

void aligned_free(
    void* mem
); // SDL_aligned_free

int get_num_allocations(
    void
); // SDL_GetNumAllocations

SDL_Environment* get_environment(
    void
); // SDL_GetEnvironment

SDL_Environment* create_environment(
    bool populated
); // SDL_CreateEnvironment

const char* get_environment_variable(
    SDL_Environment* env,
    const char* name
); // SDL_GetEnvironmentVariable

char** get_environment_variables(
    SDL_Environment* env
); // SDL_GetEnvironmentVariables

bool set_environment_variable(
    SDL_Environment* env,
    const char* name,
    const char* value,
    bool overwrite
); // SDL_SetEnvironmentVariable

bool unset_environment_variable(
    SDL_Environment* env,
    const char* name
); // SDL_UnsetEnvironmentVariable

void destroy_environment(
    SDL_Environment* env
); // SDL_DestroyEnvironment

const char* getenv(
    const char* name
); // SDL_getenv

const char* getenv_unsafe(
    const char* name
); // SDL_getenv_unsafe

int setenv_unsafe(
    const char* name,
    const char* value,
    int overwrite
); // SDL_setenv_unsafe

int unsetenv_unsafe(
    const char* name
); // SDL_unsetenv_unsafe

void qsort(
    void* base,
    size_t nmemb,
    size_t size,
    SDL_CompareCallback compare
); // SDL_qsort

void* bsearch(
    const void* key,
    const void* base,
    size_t nmemb,
    size_t size,
    SDL_CompareCallback compare
); // SDL_bsearch

void qsort_r(
    void* base,
    size_t nmemb,
    size_t size,
    SDL_CompareCallback_r compare,
    void* userdata
); // SDL_qsort_r

void* bsearch_r(
    const void* key,
    const void* base,
    size_t nmemb,
    size_t size,
    SDL_CompareCallback_r compare,
    void* userdata
); // SDL_bsearch_r

int abs(
    int x
); // SDL_abs

int isalpha(
    int x
); // SDL_isalpha

int isalnum(
    int x
); // SDL_isalnum

int isblank(
    int x
); // SDL_isblank

int iscntrl(
    int x
); // SDL_iscntrl

int isdigit(
    int x
); // SDL_isdigit

int isxdigit(
    int x
); // SDL_isxdigit

int ispunct(
    int x
); // SDL_ispunct

int isspace(
    int x
); // SDL_isspace

int isupper(
    int x
); // SDL_isupper

int islower(
    int x
); // SDL_islower

int isprint(
    int x
); // SDL_isprint

int isgraph(
    int x
); // SDL_isgraph

int toupper(
    int x
); // SDL_toupper

int tolower(
    int x
); // SDL_tolower

Uint16 crc16(
    Uint16 crc,
    const void* data,
    size_t len
); // SDL_crc16

Uint32 crc32(
    Uint32 crc,
    const void* data,
    size_t len
); // SDL_crc32

Uint32 murmur3_32(
    const void* data,
    size_t len,
    Uint32 seed
); // SDL_murmur3_32

void* memcpy(
    void* dst,
    const void* src,
    size_t len
); // SDL_memcpy

void* memmove(
    void* dst,
    const void* src,
    size_t len
); // SDL_memmove

void* memset(
    void* dst,
    int c,
    size_t len
); // SDL_memset

void* memset4(
    void* dst,
    Uint32 val,
    size_t dwords
); // SDL_memset4

int memcmp(
    const void* s1,
    const void* s2,
    size_t len
); // SDL_memcmp

size_t wcslen(
    const wchar_t* wstr
); // SDL_wcslen

size_t wcsnlen(
    const wchar_t* wstr,
    size_t maxlen
); // SDL_wcsnlen

size_t wcslcpy(
    wchar_t* dst,
    const wchar_t* src,
    size_t maxlen
); // SDL_wcslcpy

size_t wcslcat(
    wchar_t* dst,
    const wchar_t* src,
    size_t maxlen
); // SDL_wcslcat

wchar_t* wcsdup(
    const wchar_t* wstr
); // SDL_wcsdup

wchar_t* wcsstr(
    const wchar_t* haystack,
    const wchar_t* needle
); // SDL_wcsstr

wchar_t* wcsnstr(
    const wchar_t* haystack,
    const wchar_t* needle,
    size_t maxlen
); // SDL_wcsnstr

int wcscmp(
    const wchar_t* str1,
    const wchar_t* str2
); // SDL_wcscmp

int wcsncmp(
    const wchar_t* str1,
    const wchar_t* str2,
    size_t maxlen
); // SDL_wcsncmp

int wcscasecmp(
    const wchar_t* str1,
    const wchar_t* str2
); // SDL_wcscasecmp

int wcsncasecmp(
    const wchar_t* str1,
    const wchar_t* str2,
    size_t maxlen
); // SDL_wcsncasecmp

long wcstol(
    const wchar_t* str,
    wchar_t** endp,
    int base
); // SDL_wcstol

size_t strlen(
    const char* str
); // SDL_strlen

size_t strnlen(
    const char* str,
    size_t maxlen
); // SDL_strnlen

size_t strlcpy(
    char* dst,
    const char* src,
    size_t maxlen
); // SDL_strlcpy

size_t utf8strlcpy(
    char* dst,
    const char* src,
    size_t dst_bytes
); // SDL_utf8strlcpy

size_t strlcat(
    char* dst,
    const char* src,
    size_t maxlen
); // SDL_strlcat

char* strdup(
    const char* str
); // SDL_strdup

char* strndup(
    const char* str,
    size_t maxlen
); // SDL_strndup

char* strrev(
    char* str
); // SDL_strrev

char* strupr(
    char* str
); // SDL_strupr

char* strlwr(
    char* str
); // SDL_strlwr

char* strchr(
    const char* str,
    int c
); // SDL_strchr

char* strrchr(
    const char* str,
    int c
); // SDL_strrchr

char* strstr(
    const char* haystack,
    const char* needle
); // SDL_strstr

char* strnstr(
    const char* haystack,
    const char* needle,
    size_t maxlen
); // SDL_strnstr

char* strcasestr(
    const char* haystack,
    const char* needle
); // SDL_strcasestr

char* strtok_r(
    char* str,
    const char* delim,
    char** saveptr
); // SDL_strtok_r

size_t utf8strlen(
    const char* str
); // SDL_utf8strlen

size_t utf8strnlen(
    const char* str,
    size_t bytes
); // SDL_utf8strnlen

char* itoa(
    int value,
    char* str,
    int radix
); // SDL_itoa

char* uitoa(
    unsigned int value,
    char* str,
    int radix
); // SDL_uitoa

char* ltoa(
    long value,
    char* str,
    int radix
); // SDL_ltoa

char* ultoa(
    unsigned long value,
    char* str,
    int radix
); // SDL_ultoa

char* lltoa(
    long long value,
    char* str,
    int radix
); // SDL_lltoa

char* ulltoa(
    unsigned long long value,
    char* str,
    int radix
); // SDL_ulltoa

int atoi(
    const char* str
); // SDL_atoi

double atof(
    const char* str
); // SDL_atof

long strtol(
    const char* str,
    char** endp,
    int base
); // SDL_strtol

unsigned long strtoul(
    const char* str,
    char** endp,
    int base
); // SDL_strtoul

long long strtoll(
    const char* str,
    char** endp,
    int base
); // SDL_strtoll

unsigned long long strtoull(
    const char* str,
    char** endp,
    int base
); // SDL_strtoull

double strtod(
    const char* str,
    char** endp
); // SDL_strtod

int strcmp(
    const char* str1,
    const char* str2
); // SDL_strcmp

int strncmp(
    const char* str1,
    const char* str2,
    size_t maxlen
); // SDL_strncmp

int strcasecmp(
    const char* str1,
    const char* str2
); // SDL_strcasecmp

int strncasecmp(
    const char* str1,
    const char* str2,
    size_t maxlen
); // SDL_strncasecmp

char* strpbrk(
    const char* str,
    const char* breakset
); // SDL_strpbrk

Uint32 step_utf8(
    const char** pstr,
    size_t* pslen
); // SDL_StepUTF8

Uint32 step_back_utf8(
    const char* start,
    const char** pstr
); // SDL_StepBackUTF8

char* ucs4_to_utf8(
    Uint32 codepoint,
    char* dst
); // SDL_UCS4ToUTF8

int sscanf(
    const char* text,
    const char* fmt,
    ...
); // SDL_sscanf

int vsscanf(
    const char* text,
    const char* fmt,
    va_list ap
); // SDL_vsscanf

int snprintf(
    char* text,
    size_t maxlen,
    const char* fmt,
    ...
); // SDL_snprintf

int swprintf(
    wchar_t* text,
    size_t maxlen,
    const wchar_t* fmt,
    ...
); // SDL_swprintf

int vsnprintf(
    char* text,
    size_t maxlen,
    const char* fmt,
    va_list ap
); // SDL_vsnprintf

int vswprintf(
    wchar_t* text,
    size_t maxlen,
    const wchar_t* fmt,
    va_list ap
); // SDL_vswprintf

int asprintf(
    char** strp,
    const char* fmt,
    ...
); // SDL_asprintf

int vasprintf(
    char** strp,
    const char* fmt,
    va_list ap
); // SDL_vasprintf

void srand(
    Uint64 seed
); // SDL_srand

Sint32 rand(
    Sint32 n
); // SDL_rand

float randf(
    void
); // SDL_randf

Uint32 rand_bits(
    void
); // SDL_rand_bits

Sint32 rand_r(
    Uint64* state,
    Sint32 n
); // SDL_rand_r

float randf_r(
    Uint64* state
); // SDL_randf_r

Uint32 rand_bits_r(
    Uint64* state
); // SDL_rand_bits_r

double acos(
    double x
); // SDL_acos

float acosf(
    float x
); // SDL_acosf

double asin(
    double x
); // SDL_asin

float asinf(
    float x
); // SDL_asinf

double atan(
    double x
); // SDL_atan

float atanf(
    float x
); // SDL_atanf

double atan2(
    double y,
    double x
); // SDL_atan2

float atan2f(
    float y,
    float x
); // SDL_atan2f

double ceil(
    double x
); // SDL_ceil

float ceilf(
    float x
); // SDL_ceilf

double copysign(
    double x,
    double y
); // SDL_copysign

float copysignf(
    float x,
    float y
); // SDL_copysignf

double cos(
    double x
); // SDL_cos

float cosf(
    float x
); // SDL_cosf

double exp(
    double x
); // SDL_exp

float expf(
    float x
); // SDL_expf

double fabs(
    double x
); // SDL_fabs

float fabsf(
    float x
); // SDL_fabsf

double floor(
    double x
); // SDL_floor

float floorf(
    float x
); // SDL_floorf

double trunc(
    double x
); // SDL_trunc

float truncf(
    float x
); // SDL_truncf

double fmod(
    double x,
    double y
); // SDL_fmod

float fmodf(
    float x,
    float y
); // SDL_fmodf

int isinf(
    double x
); // SDL_isinf

int isinff(
    float x
); // SDL_isinff

int isnan(
    double x
); // SDL_isnan

int isnanf(
    float x
); // SDL_isnanf

double log(
    double x
); // SDL_log

float logf(
    float x
); // SDL_logf

double log10(
    double x
); // SDL_log10

float log10f(
    float x
); // SDL_log10f

double modf(
    double x,
    double* y
); // SDL_modf

float modff(
    float x,
    float* y
); // SDL_modff

double pow(
    double x,
    double y
); // SDL_pow

float powf(
    float x,
    float y
); // SDL_powf

double round(
    double x
); // SDL_round

float roundf(
    float x
); // SDL_roundf

long lround(
    double x
); // SDL_lround

long lroundf(
    float x
); // SDL_lroundf

double scalbn(
    double x,
    int n
); // SDL_scalbn

float scalbnf(
    float x,
    int n
); // SDL_scalbnf

double sin(
    double x
); // SDL_sin

float sinf(
    float x
); // SDL_sinf

double sqrt(
    double x
); // SDL_sqrt

float sqrtf(
    float x
); // SDL_sqrtf

double tan(
    double x
); // SDL_tan

float tanf(
    float x
); // SDL_tanf

SDL_iconv_t iconv_open(
    const char* tocode,
    const char* fromcode
); // SDL_iconv_open

int iconv_close(
    SDL_iconv_t cd
); // SDL_iconv_close

size_t iconv(
    SDL_iconv_t cd,
    const char** inbuf,
    size_t* inbytesleft,
    char** outbuf,
    size_t* outbytesleft
); // SDL_iconv

char* iconv_string(
    const char* tocode,
    const char* fromcode,
    const char* inbuf,
    size_t inbytesleft
); // SDL_iconv_string

bool size_mul_check_overflow(
    size_t a,
    size_t b,
    size_t* ret
); // SDL_size_mul_check_overflow

bool size_add_check_overflow(
    size_t a,
    size_t b,
    size_t* ret
); // SDL_size_add_check_overflow

/* Datatypes */

// SDL_calloc_func
// SDL_CompareCallback
// SDL_CompareCallback_r
// SDL_Environment
// SDL_free_func
// SDL_FunctionPointer
// SDL_iconv_t
// SDL_malloc_func
// SDL_realloc_func
// SDL_Time
using s_int_16 = Sint16; // Sint16
using s_int_32 = Sint32; // Sint32
using s_int_64 = Sint64; // Sint64
using s_int_8 = Sint8; // Sint8
using u_int_16 = Uint16; // Uint16
using u_int_32 = Uint32; // Uint32
using u_int_64 = Uint64; // Uint64
using u_int_8 = Uint8; // Uint8

/* Structs */

/* Enums */

/* Macros */

// SDL_arraysize
// SDL_clamp
// SDL_COMPILE_TIME_ASSERT
// SDL_const_cast
// SDL_copyp
// SDL_FLT_EPSILON
// SDL_FOURCC
// SDL_iconv_utf8_locale
// SDL_iconv_utf8_ucs2
// SDL_iconv_utf8_ucs4
// SDL_iconv_wchar_utf8
// SDL_IN_BYTECAP
// SDL_INIT_INTERFACE
// SDL_INOUT_Z_CAP
// SDL_INVALID_UNICODE_CODEPOINT
// SDL_max
// SDL_min
// SDL_NOLONGLONG
// SDL_OUT_BYTECAP
// SDL_OUT_CAP
// SDL_OUT_Z_BYTECAP
// SDL_OUT_Z_CAP
// SDL_PI_D
// SDL_PI_F
// SDL_PRILL_PREFIX
// SDL_PRILLd
// SDL_PRILLu
// SDL_PRILLx
// SDL_PRILLX
// SDL_PRINTF_FORMAT_STRING
// SDL_PRINTF_VARARG_FUNC
// SDL_PRINTF_VARARG_FUNCV
// SDL_PRIs32
// SDL_PRIs64
// SDL_PRIu32
// SDL_PRIu64
// SDL_PRIX32
// SDL_PRIx32
// SDL_PRIx64
// SDL_PRIX64
// SDL_reinterpret_cast
// SDL_SCANF_FORMAT_STRING
// SDL_SCANF_VARARG_FUNC
// SDL_SCANF_VARARG_FUNCV
// SDL_SINT64_C
// SDL_SIZE_MAX
// SDL_stack_alloc
// SDL_static_cast
// SDL_STRINGIFY_ARG
// SDL_UINT64_C
// SDL_WPRINTF_VARARG_FUNC
// SDL_WPRINTF_VARARG_FUNCV
// SDL_zero
// SDL_zeroa
// SDL_zerop

} // namespace  sdl3_wrapper
