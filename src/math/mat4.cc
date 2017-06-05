#include <math/mat4.hh>

namespace ky
{
  Mat4::Mat4()
    : values_(std::vector<float>(16))
  {
    for (std::size_t i = 0; i < 4; i++)
      for (std::size_t j = 0; j < 4; j++)
        values_[i * 4 + j] = 0;
  }

  Mat4 Mat4::identity()
  {
    Mat4 res;
    res(0, 0) = 1.0f;
    res(1, 1) = 1.0f;
    res(2, 2) = 1.0f;
    res(3, 3) = 1.0f;

    return res;
  }

  Mat4 Mat4::operator*(const Mat4 &rhs)
  {
    Mat4 r;
    int r_index = 0;
    for (std::size_t col = 0; col < 4; col++) {
      for (std::size_t row = 0; row < 4; row++) {
        float sum = 0.0f;

        for (std::size_t i = 0; i < 4; i++)
          sum += rhs.values_[col * 4 + i] * values_[i * 4 + row];

        r.values_[r_index++] = sum;
      }
    }
  return r;
  }

  Mat4& Mat4::operator=(const Mat4& rhs)
  {
    for (std::size_t i = 0; i < 4; i++)
      for (std::size_t j = 0; j < 4; j++)
        values_[i * 4 + j] = rhs(i, j);

    return *this;
  }

  Mat4 Mat4::translate(const Vec2& rhs)
  {
    Mat4 res = Mat4::identity();
    res(3, 0) = rhs.getX();
    res(3, 1) = rhs.getY();

    return res;
  }

  Mat4 Mat4::rotateOnZ(float angle)
  {
    float rad = DEG_TO_RAD * angle;
    Mat4 res = Mat4::identity();
    res(0, 0) = cos(rad);
    res(1, 0) = -sin(rad);
    res(0, 1) = sin(rad);
    res(1, 1) = cos(rad);

    return res;
  }

  void Mat4::dump() const
  {
    for (std::size_t i = 0; i < 4; i++)
    {
      for (std::size_t j = 0; j < 4; j++)
        std::cout << (*this)(j, i) << " ";
      std::cout << std::endl;
    }
  }
}
