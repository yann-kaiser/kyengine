#pragma once

#include <math/math.hh>

#include <engine/engine.hh>

namespace ky
{
  class Camera
  {
    public:
      Camera(float left, float right, float top, float bottom,
          Vec2 position);

      void update();
      void move(float x, float y);
      void rotate(float angle);

      inline const Mat4& getProjection() { return projection_; };
      inline const Mat4& getView() { return view_; };
      inline const Mat4& getTransform() { return transform_; };
      inline float getRotation() { return rotation_; };

    private:
      Mat4 projection_;
      Mat4 view_;
      Mat4 transform_;

      Vec2 position_;
      Vec2 previous_position_;
      float rotation_;
  };
}
