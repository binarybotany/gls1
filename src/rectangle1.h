#ifndef GLS1_RECTANGLE1_H_
#define GLS1_RECTANGLE1_H_

#include <memory>

#include "render_object.h"
#include "rendering_program.h"

namespace gls1 {
class rectangle1 final : public render_object {
 public:
  rectangle1();
  virtual ~rectangle1();

  void render() const override;

  void bind() const;
  void unbind() const;

 private:
  unsigned int ebo_, vao_, vbo_;
  std::unique_ptr<rendering_program> program_ = nullptr;
};
}  // namespace gls1

#endif