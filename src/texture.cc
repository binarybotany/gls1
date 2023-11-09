#include "texture.h"

#include <glad/glad.h>
#include <stb_image.h>

#include "lazy_singleton.h"
#include "logger.h"

namespace gls1 {
texture::texture(const std::string &imagepath) {
  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  int width, height, channels;
  unsigned char *data =
      stbi_load(imagepath.c_str(), &width, &height, &channels, 0);

  if (data != nullptr) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    lazy_singleton<logger>::get().log(log_level::warning,
                                      "Unable to load texture");
  }

  stbi_image_free(data);
}

texture::~texture() {}

void texture::bind() const { glBindTexture(GL_TEXTURE_2D, texture_); }

void texture::unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }
}  // namespace gls1