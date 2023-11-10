#version 460 core

out vec4 out_color;

in vec2 vs_texture_coordinates;

uniform vec3 object_color;
uniform vec3 light_color;

uniform sampler2D texture_sampler;

void main() {
   vec4 color = vec4(light_color * object_color, 1.0);
   out_color = texture(texture_sampler, vs_texture_coordinates) * color;
}