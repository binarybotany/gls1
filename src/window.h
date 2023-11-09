#ifndef GLS1_WINDOW_H_
#define GLS1_WINDOW_H_

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace gls1 {
class window final {
 public:
  void start_up();
  void shut_down();

  bool should_close();
  void swap_buffers();

 private:
  GLFWwindow *glfw_window_ = nullptr;
};
}  // namespace gls1

#endif