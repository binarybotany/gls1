#ifndef GLS1_RENDER_OBJECT_H_
#define GLS1_RENDER_OBJECT_H_

#include <glm/mat4x4.hpp>

namespace gls1 {
class render_object {
 public:
  virtual ~render_object() = default;
  virtual void update(glm::mat4 view) {}
  virtual void render() const = 0;
};
}  // namespace gls1

#endif