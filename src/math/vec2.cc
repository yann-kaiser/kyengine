#include <math/vec2.hh>

namespace ky
{
  Vec2::Vec2()
    : x_(0)
    , y_(0)
  {}

  Vec2::Vec2(float x, float y)
    : x_(x)
    , y_(y)
  {}

  Vec2 Vec2::normalized()
  {
    Vec2 res;

    float length = this->length();
    if (length == 0.0f)
      return Vec2(0.0f, 0.0f);

    res.x_ = this->x_ / length;
    res.y_ = this->y_ / length;

    return res;
  }

  Vec2 Vec2::operator+(const Vec2& rhs)
  {
    Vec2 res;
    res.x_ = this->x_ + rhs.x_;
    res.y_ = this->y_ + rhs.y_;

    return res;
  }

  Vec2 Vec2::operator+(float rhs)
  {
    Vec2 res;
    res.x_ = this->x_ + rhs;
    res.y_ = this->y_ + rhs;

    return res;
  }

  Vec2& Vec2::operator+=(const Vec2& rhs)
  {
    this->x_ += rhs.x_;
    this->y_ += rhs.y_;

    return *this;
  }

  Vec2 Vec2::operator-(const Vec2& rhs)
  {
    Vec2 res;
    res.x_ = this->x_ - rhs.x_;
    res.y_ = this->y_ - rhs.y_;

    return res;
  }

  Vec2 Vec2::operator-(float rhs)
  {
    Vec2 res;
    res.x_ = this->x_ - rhs;
    res.y_ = this->y_ - rhs;

    return res;
  }

  Vec2& Vec2::operator-=(const Vec2& rhs)
  {
    this->x_ -= rhs.x_;
    this->y_ -= rhs.y_;

    return *this;
  }

  Vec2 Vec2::operator*(float rhs)
  {
    Vec2 res;
    res.x_ = this->x_ * rhs;
    res.y_ = this->y_ * rhs;

    return res;
  }

  Vec2& Vec2::operator*=(float rhs)
  {
    this->x_ *= rhs;
    this->y_ *= rhs;

    return *this;
  }

  Vec2 Vec2::operator/(float rhs)
  {
    Vec2 res;
    res.x_ = this->x_ / rhs;
    res.y_ = this->y_ / rhs;

    return res;
  }

  Vec2& Vec2::operator/=(float rhs)
  {
    this->x_ /= rhs;
    this->y_ /= rhs;

    return *this;
  }

  Vec2& Vec2::operator=(const Vec2& rhs)
  {
    this->x_ = rhs.x_;
    this->y_ = rhs.y_;

    return *this;
  }

  Vec2 Vec2::rotate(float angle)
  {
    float rad = angle * DEG_TO_RAD;

    float c = cos(rad);
    float s = sin(rad);

    Vec2 res(this->getX() * c - this->getY() * s,
        this->getX() * s + this->getY() * c);

    return res;
  }
}
