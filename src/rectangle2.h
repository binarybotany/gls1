#ifndef GLS1_RECTANGLE2_H_
#define GLS1_RECTANGLE2_H_

#include <glm/mat4x4.hpp>
#include <memory>

#include "render_object.h"
#include "rendering_program.h"
#include "texture.h"

namespace gls1 {
class rectangle2 final : public render_object {
 public:
  rectangle2();
  virtual ~rectangle2();

  void render() const override;
  void update(glm::mat4 _) override;

  void bind() const;
  void unbind() const;

 private:
  unsigned int ebo_, vao_, vbo_;
  std::unique_ptr<rendering_program> program_ = nullptr;
  std::unique_ptr<texture> texture_ = nullptr;
};
}  // namespace gls1

#endif