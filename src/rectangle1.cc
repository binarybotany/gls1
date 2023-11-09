#include "rectangle1.h"

#include <glad/glad.h>

namespace gls1 {
rectangle1::rectangle1() {
  const float vertices[] = {0.5f,  0.5f,  0.0f, 0.5f,  -0.5f, 0.0f,
                            -0.5f, -0.5f, 0.0f, -0.5f, 0.5f,  0.0f};

  const unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  program_ = std::make_unique<rendering_program>();
  program_->add_shader(GL_VERTEX_SHADER, "shaders/position.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "shaders/firebrick.frag.glsl");
  program_->link();

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);

  bind();

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  unbind();
}

rectangle1::~rectangle1() {
  glDeleteBuffers(1, &ebo_);
  glDeleteBuffers(1, &vbo_);
  glDeleteVertexArrays(1, &vao_);
}

void rectangle1::render() const {
  bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  unbind();
}

void rectangle1::update() {}

void rectangle1::bind() const {
  program_->use();

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
}

void rectangle1::unbind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
}  // namespace gls1