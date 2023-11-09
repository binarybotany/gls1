#include "window.h"

#include <cstdlib>

#include "lazy_singleton.h"
#include "logger.h"

namespace gls1 {
void window::start_up() {
  if (!glfwInit()) {
    lazy_singleton<logger>::get().log(log_level::error,
                                      "Unable to initialize GLFW");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  glfw_window_ = glfwCreateWindow(1024, 768, "GLS1", nullptr, nullptr);

  if (glfw_window_ == nullptr) {
    lazy_singleton<logger>::get().log(log_level::error,
                                      "Unable to create window");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(glfw_window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    lazy_singleton<logger>::get().log(
        log_level::error, "Unable to initialize OpenGL 4.6 context");
    glfwDestroyWindow(glfw_window_);
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}

void window::shut_down() {
  if (glfw_window_ != nullptr) {
    glfwDestroyWindow(glfw_window_);
  }
  glfwTerminate();
}

bool window::should_close() { return glfwWindowShouldClose(glfw_window_); }

void window::swap_buffers() { glfwSwapBuffers(glfw_window_); }
}  // namespace gls1