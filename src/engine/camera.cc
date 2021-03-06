#include <engine/camera.hh>

#include <iostream>

namespace ky
{
  Camera::Camera(float width, float height,
      Vec2 position)
    : projection_(Mat4())
    , view_(Mat4())
    , position_(position)
    , previous_position_(position)
    , rotation_(0)
  {
    resizeViewport(width, height);
    update();
  }

  void Camera::resizeViewport(float width, float height)
  {
    //TODO: Do we want to set them manually while creating a game ?
    float near = 0.0f;
    float far  = 1000.0f;

    projection_(0, 0) = 2.0f / (width);
    projection_(1, 1) = 2.0f / (-height);
    projection_(2, 2) = -2.0f / (far - near);

    projection_(3, 0) = -(width) / (width);
    projection_(3, 1) = -(height) / (-height);
    projection_(3, 2) = -(far + near) / (far - near);

    projection_(3, 3) = 1;

    update();
  }

  void Camera::update()
  {
    Mat4 T = Mat4::identity();
    T = T.translate(this->position_.negated());

    Mat4 R = Mat4::identity();
    R = R.rotateOnZ(-rotation_);
    view_ = Mat4::identity().translate(
        Vec2(Engine::instance().getDisplay().getWidth() / 2,
          Engine::instance().getDisplay().getHeight() / 2)) * R * T;
    transform_ = projection_ * view_;
  }

  void Camera::move(float x, float y)
  {
    this->previous_position_ = this->position_;
    float c = cos(DEG_TO_RAD * this->rotation_);
    float s = sin(DEG_TO_RAD * this->rotation_);
    this->position_ += Vec2(x * c - y * s, x * s + y * c);
    this->update();
  }

  void Camera::rotate(float angle)
  {
    this->rotation_ += angle;
    this->update();
  }
}
