#include "rendering_program.h"

#include <glad/glad.h>

#include "file.h"

namespace gls1 {
rendering_program::rendering_program() { program_ = glCreateProgram(); }

rendering_program::~rendering_program() { glDeleteProgram(program_); }

void rendering_program::add_shader(int type, std::string filepath) {
  file shader_file(filepath);

  std::string contents = shader_file.contents();
  const char *source = contents.c_str();

  unsigned int shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  int compiled = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (!compiled) {
    // TODO: log
    char infolog[1024];
    glGetShaderInfoLog(shader, 1024, nullptr, infolog);
    std::cerr << infolog << std::endl;
    glDeleteShader(shader);
    return;
  }

  shaders_.push_back(shader);
}

void rendering_program::link() {
  for (const unsigned int shader : shaders_) {
    glAttachShader(program_, shader);
  }

  glLinkProgram(program_);

  glLinkProgram(program_);

  int linked = GL_FALSE;
  glGetProgramiv(program_, GL_LINK_STATUS, &linked);
  if (!linked) {
    // TODO: log
    char infolog[1024];
    glGetProgramInfoLog(program_, 1024, nullptr, infolog);
    std::cerr << infolog << std::endl;
    return;
  }

  for (const unsigned int shader : shaders_) {
    glDeleteShader(shader);
  }
}

void rendering_program::use() { glUseProgram(program_); }
}  // namespace gls1