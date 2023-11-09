#include "perspective_camera.h"

namespace gls1 {
perspective_camera::perspective_camera() {
  position_ = glm::vec3(0.0f, 0.0f, 3.0f);
  front_ = glm::vec3(0.0f, 0.0f, -1.0f);
  up_ = glm::vec3(0.0f, 1.0f, 0.0f);
}

perspective_camera::~perspective_camera() {}

glm::mat4 perspective_camera::view() const {
  return glm::lookAt(position_, position_ + front_, up_);
}

void perspective_camera::move_forwards(float delta_time) {
  position_ += speed_ * delta_time * front_;
}

void perspective_camera::move_backwards(float delta_time) {
  position_ -= speed_ * delta_time * front_;
}

void perspective_camera::move_left(float delta_time) {
  position_ -= glm::normalize(glm::cross(front_, up_)) * speed_ * delta_time;
}

void perspective_camera::move_right(float delta_time) {
  position_ += glm::normalize(glm::cross(front_, up_)) * speed_ * delta_time;
}

void perspective_camera::set_direction(float x_offset, float y_offset) {
  yaw_ += x_offset;
  pitch_ += y_offset;

  if (pitch_ > 89.0f) pitch_ = 89.0f;
  if (pitch_ < -89.0f) pitch_ = -89.0f;

  glm::vec3 direction;
  direction.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  direction.y = sin(glm::radians(pitch_));
  direction.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));

  front_ = glm::normalize(direction);
}
}  // namespace gls1