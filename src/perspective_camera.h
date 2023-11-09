#ifndef GLS1_PERSPECTIVE_CAMERA_H_
#define GLS1_PERSPECTIVE_CAMERA_H_

#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace gls1 {
class perspective_camera final {
 public:
  perspective_camera();
  ~perspective_camera();

  glm::mat4 view() const;

  void move_forwards(float delta_time);
  void move_backwards(float delta_time);
  void move_left(float delta_time);
  void move_right(float delta_time);
  void set_direction(float x_offset, float y_offset);

 private:
  glm::vec3 position_;
  glm::vec3 front_;
  glm::vec3 up_;

  float yaw_ = -90.0f;
  float pitch_ = 0.0f;
  float speed_ = 3.0f;
};
}  // namespace gls1

#endif