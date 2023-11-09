#include "rectangle2.h"

#include <glad/glad.h>
#include <stb_image.h>

namespace gls1 {
rectangle2::rectangle2() {
  program_ = std::make_unique<rendering_program>();
  program_->add_shader(GL_VERTEX_SHADER, "position.vert.glsl");
  program_->add_shader(GL_FRAGMENT_SHADER, "");

  /* Texturing */
  int width, height, channels;
  unsigned char *data =
      stbi_load("images/checkers-16-16.png", &width, &height, &channels, 0);

  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);
}

rectangle2::~rectangle2() {}

void rectangle2::render() const {}

void rectangle2::update() {}

void rectangle2::bind() const { program_->use(); }

void rectangle2::unbind() const {}
}  // namespace gls1