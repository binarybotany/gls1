cmake_minimum_required(VERSION 3.20)

set(gls1_headers 
    "cube1.h"
    "cube2.h"
    "engine.h" 
    "file.h"
    "input_controller.h"
    "lazy_singleton.h"
    "logger.h"
    "perspective_camera.h"
    "rectangle1.h"
    "rectangle2.h"
    "render_object.h" 
    "renderer.h"
    "rendering_program.h"
    "texture.h"
    "triangle1.h"
    "window.h")

set(gls1_sources
    "cube1.cc" 
    "cube2.cc"
    "engine.cc"
    "file.cc" 
    "input_controller.cc"
    "logger.cc"
    "perspective_camera.cc"
    "rectangle1.cc"
    "rectangle2.cc"
    "renderer.cc"
    "rendering_program.cc"
    "texture.cc"
    "triangle1.cc" 
    "window.cc")

add_executable(gls1 main.cc ${gls1_headers} ${gls1_sources})
target_link_libraries(gls1 PRIVATE glad glfw glm stb_image)