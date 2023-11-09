#ifndef GLS1_RENDERER_H_
#define GLS1_RENDERER_H_

#include <vector>

#include "perspective_camera.h"
#include "render_object.h"

namespace gls1 {
class renderer final {
 public:
  renderer(perspective_camera *camera) : camera_(camera) {}

  void start_up();
  void shut_down();

  void update();
  void render();

 private:
  perspective_camera *camera_;
  std::vector<render_object *> objects_;
};
}  // namespace gls1

#endif