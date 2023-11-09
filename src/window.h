#ifndef GLS1_WINDOW_H_
#define GLS1_WINDOW_H_

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "input_controller.h"

namespace gls1 {
class window final {
 public:
  void start_up(input_controller* input_controller);
  void shut_down();

  bool should_close() const;

  void swap_buffers() const;

  GLFWwindow* glfw_window() const;

 private:
  GLFWwindow* glfw_window_ = nullptr;
  input_controller* input_controller_ = nullptr;

  static void debug_message_callback(int source, int type, unsigned int id,
                                     int severity, unsigned int length,
                                     const char* message,
                                     const void* userParam);
};
}  // namespace gls1

#endif