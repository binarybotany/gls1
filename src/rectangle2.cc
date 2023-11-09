#include "rectangle2.h"

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stb_image.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace gls1 {
rectangle2::rectangle2() {
  const float vertices[] = {0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                            0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                            -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f};

  const unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  program_ = std::make_unique<rendering_program>();
  program_->add_shader(GL_VERTEX_SHADER, "shaders/rectangle2.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "shaders/rectangle2.frag.glsl");
  program_->link();

  texture_ = std::make_unique<texture>("images/checkers-16-16.png");

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);

  bind();

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(6 * sizeof(float)));

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  unbind();
}

rectangle2::~rectangle2() {
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
  glDeleteBuffers(1, &ebo_);
}

void rectangle2::render() const {
  bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  unbind();
}

void rectangle2::update(glm::mat4 _) {
  glm::mat4 transform = glm::mat4(1.0f);
  transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
  transform =
      glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

  program_->set_mat4fv("transform", transform);
}

void rectangle2::bind() const {
  program_->use();
  texture_->bind();

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
}

void rectangle2::unbind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  texture_->unbind();
}
}  // namespace gls1