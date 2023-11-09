#include "engine.h"

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

#include "lazy_singleton.h"

namespace gls1 {
void engine::start_up() {
  lazy_singleton<logger>::get().set_file("gls1.log");
  lazy_singleton<logger>::get().log(log_level::info, "Starting up engine");

  window_ = std::make_unique<window>();
  renderer_ = std::make_unique<renderer>();

  window_->start_up();
  renderer_->start_up();
}

void engine::shut_down() {
  lazy_singleton<logger>::get().log(log_level::info, "Shutting down engine");

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