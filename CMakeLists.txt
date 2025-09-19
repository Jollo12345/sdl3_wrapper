cmake_minimum_required(VERSION 3.16)

project(sdl3_wrapper
    LANGUAGES CXX
    VERSION 0.0.0
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)

set(${PROJECT_NAME}_HEADERS
    include/sdl3_wrapper/event.h
    include/sdl3_wrapper/gpu.h
    include/sdl3_wrapper/init.h
    include/sdl3_wrapper/iostream.h
    include/sdl3_wrapper/stdinc.h
    include/sdl3_wrapper/video.h

    include/util.h
)

set(${PROJECT_NAME}_SOURCES
    src/sdl3_wrapper/gpu.cpp
    src/sdl3_wrapper/init.cpp
    src/sdl3_wrapper/iostream.cpp
    src/sdl3_wrapper/stdinc.cpp
    src/sdl3_wrapper/video.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL3::SDL3
    spdlog::spdlog
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS
    ${PROJECT_NAME}
)
