#include "renderer.h"

#include <glad/glad.h>

#include "cube1.h"
#include "rectangle1.h"
#include "rectangle2.h"
#include "triangle1.h"

namespace gls1 {
void renderer::start_up() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  render_object *c1 = new cube1();

  objects_.push_back(c1);
}

void renderer::shut_down() {
  for (auto object : objects_) {
    delete object;
  }
}

void renderer::update() {
  for (auto object : objects_) {
    object->update(camera_->view());
  }
}

void renderer::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto object : objects_) {
    object->render();
  }
}
}  // namespace gls1
