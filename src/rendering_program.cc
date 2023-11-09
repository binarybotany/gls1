#include "rendering_program.h"

#include <glad/glad.h>

#include "file.h"
#include "lazy_singleton.h"
#include "logger.h"

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
    char infolog[1024];
    glGetShaderInfoLog(shader, 1024, nullptr, infolog);
    lazy_singleton<logger>::get().log(log_level::warning, std::string(infolog));
    glDeleteShader(shader);
    return;
  }

  shaders_.push_back(shader);
}

void rendering_program::link() const {
  for (const unsigned int shader : shaders_) {
    glAttachShader(program_, shader);
  }

  glLinkProgram(program_);

  glLinkProgram(program_);

  int linked = GL_FALSE;
  glGetProgramiv(program_, GL_LINK_STATUS, &linked);
  if (!linked) {
    char infolog[1024];
    glGetProgramInfoLog(program_, 1024, nullptr, infolog);
    lazy_singleton<logger>::get().log(log_level::warning, std::string(infolog));
    return;
  }

  for (const unsigned int shader : shaders_) {
    glDeleteShader(shader);
  }
}

void rendering_program::use() const { glUseProgram(program_); }

void rendering_program::set_mat4fv(const std::string &location,
                                   glm::mat4 matrix) const {
  use();

  unsigned int uniform_location =
      glGetUniformLocation(program_, location.c_str());

  glUniformMatrix4fv(uniform_location, 1, GL_FALSE, glm::value_ptr(matrix));
}
}  // namespace gls1