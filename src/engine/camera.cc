#include <engine/camera.hh>

#include <iostream>

namespace ky
{
  Camera::Camera(float left, float right, float top, float bottom,
      Vec2 position)
    : projection_(Mat4())
    , view_(Mat4())
    , position_(position)
    , previous_position_(position)
    , rotation_(0)
  {
    float near = 0.0f;
    float far  = 1000.0f;

    projection_(0, 0) = 2.0f / (right - left);
    projection_(1, 1) = 2.0f / (top - bottom);
    projection_(2, 2) = -2.0f / (far - near);

    projection_(3, 0) = -(right + left) / (right - left);
    projection_(3, 1) = -(top + bottom) / (top - bottom);
    projection_(3, 2) = -(far + near) / (far - near);

    projection_(3, 3) = 1;

    update();
  }

  void Camera::update()
  {
    Mat4 T = Mat4::identity();
    T = T.translate(this->position_.negated());

    Mat4 R = Mat4::identity();
    R = R.translate(Vec2(400, 300)).rotateOnZ(-rotation_);

    view_ = T * R;
  }

  void Camera::move(float x, float y)
  {
    this->previous_position_ = this->position_;
    this->position_ += Vec2(x, y);
    this->update();
  }

  void Camera::rotate(float angle)
  {
    this->rotation_ += angle;
    this->update();
  }
}
