#pragma once

#include <vector>
#include <math/math.hh>

namespace ky
{
  class Mat3
  {
    public:
      Mat3();

      static Mat3 identity();

      inline float& operator()(std::size_t col, std::size_t row)
      {
        if (row >= 3 || col >= 3)
          throw std::out_of_range("Matrix subscript ouf of bounds");

        return values_[col * 3 + row];
      }

      inline const float& operator()(std::size_t col, std::size_t row) const
      {
        if (row >= 3 || col >= 3)
          throw std::out_of_range("Matrix subscript ouf of bounds");

        return values_[col * 3 + row];
      }

      inline const std::vector<float>& getValues() const { return values_; }

      Mat3 operator*(const Mat3 &rhs);
      Mat3& operator=(const Mat3 &rhs);

      Mat3 translate(const Vec2& rhs);
      Mat3 rotate(float angle);
      void dump() const;
    private:
      std::vector<float> values_;
  };
}
