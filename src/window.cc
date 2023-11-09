#include "window.h"

#include <cstdlib>

#include "lazy_singleton.h"
#include "logger.h"

namespace gls1 {
void window::start_up(input_controller* input_controller) {
  input_controller_ = input_controller;

  if (!glfwInit()) {
    lazy_singleton<logger>::get().log(log_level::error,
                                      "Unable to initialize GLFW");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_SAMPLES, 4);

  glfw_window_ = glfwCreateWindow(1024, 768, "GLS1", nullptr, nullptr);

  if (glfw_window_ == nullptr) {
    lazy_singleton<logger>::get().log(log_level::error,
                                      "Unable to create window");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(glfw_window_);
  glfwSetInputMode(glfw_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    lazy_singleton<logger>::get().log(
        log_level::error, "Unable to initialize OpenGL 4.6 context");
    glfwDestroyWindow(glfw_window_);
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // TODO: Add configuration for hardcoded width and height
  glViewport(0, 0, 1024, 768);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback((GLDEBUGPROC)debug_message_callback, nullptr);

  glfwSetWindowUserPointer(glfw_window_, this);
  input_controller_->set_glfw_window(glfw_window_);
}

void window::shut_down() {
  if (glfw_window_ != nullptr) {
    glfwDestroyWindow(glfw_window_);
  }
  glfwTerminate();
}

bool window::should_close() const {
  return glfwWindowShouldClose(glfw_window_);
}

void window::swap_buffers() const { glfwSwapBuffers(glfw_window_); }

GLFWwindow* window::glfw_window() const { return glfw_window_; }

void window::debug_message_callback(int source, int type, unsigned int id,
                                    int severity, unsigned int length,
                                    const char* message,
                                    const void* userParam) {
  lazy_singleton<logger>::get().log(log_level::debug, std::string(message));
}
}  // namespace gls1