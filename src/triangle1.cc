#include "triangle1.h"

#include <glad/glad.h>

namespace gls1 {
triangle1::triangle1() {
  program_ = std::make_unique<rendering_program>();
  program_->add_shader(GL_VERTEX_SHADER, "shaders/triangle1.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "shaders/triangle1.frag.glsl");
  program_->link();

  const float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                            0.0f,  0.0f,  0.5f, 0.0f};

  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);

  glGenBuffers(1, &vbo_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  program_->use();

  glBindVertexArray(NULL);
}

triangle1::~triangle1() {}

void triangle1::render() {
  program_->use();
  glBindVertexArray(vao_);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(NULL);
}

void triangle1::update() {}
}  // namespace gls1