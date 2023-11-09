cmake_minimum_required(VERSION 3.20)

set(gls1_headers 
    "engine.h" 
    "file.h"
    "lazy_singleton.h"
    "logger.h"
    "rectangle1.h"
    "rectangle2.h"
    "render_object.h" 
    "renderer.h"
    "rendering_program.h"
    "texture.h"
    "triangle1.h"
    "window.h")

set(gls1_sources 
    "engine.cc"
    "file.cc" 
    "logger.cc"
    "rectangle1.cc"
    "rectangle2.cc"
    "renderer.cc"
    "rendering_program.cc"
    "texture.cc"
    "triangle1.cc" 
    "window.cc")

add_executable(gls1 main.cc ${gls1_headers} ${gls1_sources})
target_link_libraries(gls1 PRIVATE glfw glad stb_image)