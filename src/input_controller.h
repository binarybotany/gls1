#ifndef GLS1_INPUT_CONTROLLER_H_
#define GLS1_INPUT_CONTROLLER_H_

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

#include "perspective_camera.h"

namespace gls1 {
class input_controller final {
 public:
  void process(float delta_time, perspective_camera *camera);

  void set_glfw_window(GLFWwindow *window) { glfw_window_ = window; }

 private:
  GLFWwindow *glfw_window_;
  double xpos_, ypos_;
  float last_x_, last_y_;
  float sensitivity_ = 0.1f;
};
}  // namespace gls1

#endif