#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

#include <math/math.hh>

namespace ky
{
  class Mat4
  {
    public:
      Mat4();

      static Mat4 identity();

      inline float& operator()(std::size_t col, std::size_t row)
      {
        if (row >= 4 || col >= 4)
          throw std::out_of_range("Matrix subscript out of bounds");
        return values_[col * 4 + row];
      }

      inline const float& operator()(std::size_t col, std::size_t row) const
      {
        if (row >= 4 || col >= 4)
          throw std::out_of_range("Matrix subscript out of bounds");
        return values_[col * 4 + row];
      }

      inline const std::vector<float>& getValues() const { return values_; }

      Mat4 operator*(const Mat4& rhs);
      Mat4& operator=(const Mat4& rhs);

      Mat4 translate(const Vec2& rhs);
      Mat4 rotateOnZ(float angle);
      void dump() const;
    private:
      std::vector<float> values_;
  };
}
