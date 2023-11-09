#ifndef GLS1_ENGINE_H_
#define GLS1_ENGINE_H_

#include <memory>

#include "logger.h"
#include "renderer.h"
#include "window.h"

namespace gls1 {
class engine final {
 public:
  void start_up();
  void shut_down();
  void run();

 private:
  std::unique_ptr<window> window_ = nullptr;
  std::unique_ptr<renderer> renderer_ = nullptr;
};
}  // namespace gls1

#endif