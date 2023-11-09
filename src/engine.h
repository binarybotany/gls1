#ifndef GLS1_ENGINE_H_
#define GLS1_ENGINE_H_

#include <memory>

#include "input_controller.h"
#include "logger.h"
#include "perspective_camera.h"
#include "renderer.h"
#include "window.h"

namespace gls1 {
class engine final {
 public:
  void start_up();
  void shut_down();
  void run();

 private:
  void delta_time();

  float delta_time_ = 0.0f;
  float last_frame_ = 0.0f;

  std::unique_ptr<window> window_ = nullptr;
  std::unique_ptr<renderer> renderer_ = nullptr;
  std::unique_ptr<perspective_camera> camera_ = nullptr;
  std::unique_ptr<input_controller> input_controller_ = nullptr;
};
}  // namespace gls1

#endif