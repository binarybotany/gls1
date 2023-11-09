#include "triangle1.h"

#include <glad/glad.h>

namespace gls1 {
triangle1::triangle1() {
  program_ = std::make_unique<rendering_program>();
  program_->add_shader(GL_VERTEX_SHADER, "shaders/position.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "shaders/burgundy.frag.glsl");
  program_->link();

  const float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                            0.0f,  0.0f,  0.5f, 0.0f};

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);

  bind();

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  unbind();
}

triangle1::~triangle1() {
  glDeleteBuffers(1, &vbo_);
  glDeleteVertexArrays(1, &vao_);
}

void triangle1::render() const {
  bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
  unbind();
}

void triangle1::update() {}

void triangle1::bind() const {
  program_->use();

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
}

void triangle1::unbind() const {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
}  // namespace gls1