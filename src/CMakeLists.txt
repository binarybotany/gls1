cmake_minimum_required(VERSION 3.20)

set(gls1_headers 
    "engine.h" 
    "file.h"
    "logger.h"
    "render_object.h" 
    "renderer.h"
    "rendering_program.h"
    "triangle1.h"
    "window.h")

set(gls1_sources 
    "engine.cc"
    "file.cc" 
    "logger.cc"
    "renderer.cc"
    "rendering_program.cc"
    "triangle1.cc" 
    "window.cc")

add_executable(gls1 main.cc ${gls1_headers} ${gls1_sources})
target_link_libraries(gls1 PRIVATE glfw glad)