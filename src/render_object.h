#ifndef GLS1_RENDER_OBJECT_H_
#define GLS1_RENDER_OBJECT_H_

namespace gls1 {
class render_object {
 public:
  virtual ~render_object() = default;
  virtual void update() = 0;
  virtual void render() = 0;
};
}  // namespace gls1

#endif