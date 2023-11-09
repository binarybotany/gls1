#include "engine.h"

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

#include "lazy_singleton.h"

namespace gls1 {
void engine::start_up() {
  lazy_singleton<logger>::get().set_file("gls1.log");
  lazy_singleton<logger>::get().log(log_level::info, "Starting up engine");

  input_controller_ = std::make_unique<input_controller>();
  window_ = std::make_unique<window>();
  camera_ = std::make_unique<perspective_camera>();
  renderer_ = std::make_unique<renderer>(camera_.get());

  window_->start_up(input_controller_.get());
  renderer_->start_up();
}

void engine::shut_down() {
  lazy_singleton<logger>::get().log(log_level::info, "Shutting down engine");

  renderer_->shut_down();
  window_->shut_down();
}

void engine::run() {
  while (!window_->should_close()) {
    delta_time();

    input_controller_->process(delta_time_, camera_.get());

    renderer_->update();
    renderer_->render();

    window_->swap_buffers();
  }
}

void engine::delta_time() {
  float current_frame = (float)glfwGetTime();
  delta_time_ = current_frame - last_frame_;
  last_frame_ = current_frame;
}
}  // namespace gls1