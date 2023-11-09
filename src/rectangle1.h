#ifndef GLS1_RECTANGLE1_H_
#define GLS1_RECTANGLE1_H_

#include "render_object.h"

namespace gls1 {
class rectangle1 final : public render_object {
  rectangle1();
  ~rectangle1();

  void render() const override;
  void update() override;
};
}  // namespace gls1

#endif