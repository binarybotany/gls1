#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture_coordinates;

out vec2 vs_texture_coordinates;

void main() {
    gl_Position = vec4(position, 1.0);
    vs_texture_coordinates = texture_coordinates;
}