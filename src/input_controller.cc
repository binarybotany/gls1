#include "input_controller.h"

#include <cmath>

namespace gls1 {
void input_controller::process(float delta_time, perspective_camera *camera) {
  glfwPollEvents();

  if (glfwGetKey(glfw_window_, GLFW_KEY_W) == GLFW_PRESS) {
    camera->move_forwards(delta_time);
  }
  if (glfwGetKey(glfw_window_, GLFW_KEY_S) == GLFW_PRESS) {
    camera->move_backwards(delta_time);
  }
  if (glfwGetKey(glfw_window_, GLFW_KEY_A) == GLFW_PRESS) {
    camera->move_left(delta_time);
  }
  if (glfwGetKey(glfw_window_, GLFW_KEY_D) == GLFW_PRESS) {
    camera->move_right(delta_time);
  }
  if (glfwGetKey(glfw_window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(glfw_window_, GLFW_TRUE);
  }

  glfwGetCursorPos(glfw_window_, &xpos_, &ypos_);

  if (std::abs(last_x_ - (float)xpos_) >
          std::numeric_limits<float>::epsilon() ||
      std::abs(last_y_ - (float)ypos_) >
          std::numeric_limits<float>::epsilon()) {
    static bool initial = true;
    if (initial) {
      last_x_ = (float)xpos_;
      last_y_ = (float)ypos_;
      initial = false;
    }

    float x_offset = (float)xpos_ - last_x_;
    float y_offset = (float)ypos_ - last_y_;

    last_x_ = (float)xpos_;
    last_y_ = (float)ypos_;

    x_offset *= sensitivity_;
    y_offset *= sensitivity_;

    camera->set_direction(x_offset, y_offset);
  }
}
}  // namespace gls1