#include "engine.h"

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

namespace gls1 {
void engine::start_up() {
  logger_ = std::make_unique<logger>("gls1.log");
  window_ = std::make_unique<window>(logger_.get());
  renderer_ = std::make_unique<renderer>();

  window_->start_up();
  renderer_->start_up();
}

void engine::shut_down() {
  renderer_->shut_down();
  window_->shut_down();
}

void engine::run() {
  while (!window_->should_close()) {
    glfwPollEvents();

    renderer_->update();
    renderer_->render();

    window_->swap_buffers();
  }
}
}  // namespace gls1