#include <math/mat3.hh>

namespace ky
{
  Mat3::Mat3()
    : values_(std::vector<float>(9))
  {}

  Mat3 Mat3::identity()
  {
    Mat3 res;
    res(0, 0) = 1.0f;
    res(1, 1) = 1.0f;
    res(2, 2) = 1.0f;

    return res;
  }

  Mat3 Mat3::operator*(const Mat3 &rhs)
  {
    Mat3 res;

    int r_index = 0;

    for (std::size_t col = 0; col < 3; col++)
    {
      for (std::size_t row = 0; row < 3; row++)
      {
        float sum = 0.0f;

        for (std::size_t i = 0; i < 3; i++)
          sum += rhs(col, i) * (*this)(i, row);

        res.values_[r_index++] = sum;
      }
    }

    return res;
  }

  Mat3& Mat3::operator=(const Mat3& rhs)
  {
    for (std::size_t i = 0; i < 3; i++)
      for (std::size_t j = 0; j < 3; j++)
        (*this)(i, j) = rhs(i, j);

    return *this;
  }

  Mat3 Mat3::translate(const Vec2& rhs)
  {
    Mat3 res = Mat3::identity();
    res(2, 0) = rhs.getX();
    res(2, 1) = rhs.getY();

    return res;
  }

  Mat3 Mat3::rotate(float angle)
  {
    float rad = DEG_TO_RAD * angle;
    Mat3 res = Mat3::identity();

    res(0, 0) = cos(rad);
    res(1, 0) = -sin(rad);
    res(0, 1) = sin(rad);
    res(1, 1) = cos(rad);

    return res;
  }

  void Mat3::dump() const
  {
    for (std::size_t i = 0; i < 3; i++)
    {
      for (std::size_t j = 0; j < 3; j++)
        std::cout << (*this)(j, i) << " ";
      std::cout << std::endl;
    }
  }
}
