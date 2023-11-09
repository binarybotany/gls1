#ifndef GLS1_RENDERER_H_
#define GLS1_RENDERER_H_

#include <vector>

#include "render_object.h"

namespace gls1 {
class renderer final {
 public:
  void start_up();
  void shut_down();

  void update();
  void render();

 private:
  std::vector<render_object *> objects_;
};
}  // namespace gls1

#endif