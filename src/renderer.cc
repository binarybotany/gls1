#include "renderer.h"

#include <glad/glad.h>

#include "triangle1.h"

namespace gls1 {
void renderer::start_up() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  render_object *t1 = new triangle1();

  objects_.push_back(t1);
}

void renderer::shut_down() {
  for (auto object : objects_) {
    delete object;
  }
}

void renderer::update() {
  for (auto object : objects_) {
    object->update();
  }
}

void renderer::render() {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto object : objects_) {
    object->render();
  }
}
}  // namespace gls1