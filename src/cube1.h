#ifndef GLS1_CUBE1_H_
#define GLS1_CUBE1_H_

#include <glm/mat4x4.hpp>
#include <memory>

#include "render_object.h"
#include "rendering_program.h"
#include "texture.h"

namespace gls1 {
class cube1 final : public render_object {
 public:
  cube1();
  ~cube1();

  void render() const override;
  void update(glm::mat4 view) override;

  void bind() const;
  void unbind() const;

 private:
  unsigned int vao_, vbo_;
  std::unique_ptr<rendering_program> program_ = nullptr;
  std::unique_ptr<texture> texture_ = nullptr;
};
}  // namespace gls1

#endif