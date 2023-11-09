#ifndef GLS1_TRIANGLE1_H_
#define GLS1_TRIANGLE1_H_

#include <memory>

#include "render_object.h"
#include "rendering_program.h"

namespace gls1 {
class triangle1 final : public render_object {
 public:
  triangle1();
  ~triangle1();

  void render() const override;
  void update() override;

 private:
  unsigned int vbo_, vao_;
  std::unique_ptr<rendering_program> program_ = nullptr;
};
}  // namespace gls1

#endif