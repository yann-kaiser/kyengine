#pragma once

#include <cmath>
#include <math/math.hh>

namespace ky
{
  struct Vec2
  {
    public:
      Vec2();
      Vec2(float x, float y);

      inline float length() { return sqrt(x_ * x_ + y_ * y_); }
      inline float getX() { return x_; }
      inline float getY() { return y_; }
      inline float getX() const { return x_; }
      inline float getY() const { return y_; }

      inline float dot(const Vec2& rhs) { return this->x_ * rhs.x_ +
        this->y_ * rhs.y_; }

      inline Vec2 negated() { return Vec2(-this->x_, -this->y_); }

      Vec2 normalized();

      Vec2 operator+(const Vec2& rhs);
      Vec2 operator+(float rhs);
      Vec2& operator+=(const Vec2& rhs);

      Vec2 operator-(const Vec2& rhs);
      Vec2 operator-(float rhs);
      Vec2& operator-=(const Vec2& rhs);

      Vec2 operator*(float rhs);
      Vec2& operator*=(float rhs);

      Vec2 operator/(float rhs);
      Vec2& operator/=(float rhs);

      Vec2& operator=(const Vec2& rhs);
      Vec2 rotate(float angle);
    private:
      float x_;
      float y_;
  };
}
