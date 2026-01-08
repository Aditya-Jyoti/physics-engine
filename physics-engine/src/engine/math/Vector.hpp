#pragma once

#include <cmath>
#include <ostream>

template <std::size_t N> struct Vector {
  double data[N];

  double &operator[](std::size_t i) { return data[i]; }
  double operator[](std::size_t i) const { return data[i]; }

  /*
   * Overloads
   */

  // Scalar multiplication
  Vector<N> operator*(double scalar) const {
    Vector<N> result;
    for (std::size_t i = 0; i < N; i++) {
      result[i] = data[i] * scalar;
    }
    return result;
  };

  // Addition
  Vector<N> operator+(const Vector<N> &other) const {
    Vector<N> result;
    for (std::size_t i = 0; i < N; i++) {
      result[i] = data[i] + other[i];
    }
    return result;
  };

  // Subtraction
  Vector<N> operator-(const Vector<N> &other) const {
    Vector<N> result;
    for (std::size_t i = 0; i < N; i++) {
      result[i] = data[i] - other[i];
    }
    return result;
  };

  /*
   * Methods
   */

  // length of vector
  double magnitude() const {
    double sum = 0.0;
    for (std::size_t i = 0; i < N; i++)
      sum += data[i] * data[i];
    return std::sqrt(sum);
  };

  // vector direction without magnitude
  Vector<N> normalize() const {
    double mag = magnitude();

    if (mag == 0.0) {
      return *this;
    }

    Vector<N> result;
    for (std::size_t i = 0; i < N; i++)
      result[i] = data[i] / mag;
    return result;
  };

  // dot product
  double dot(const Vector<N> &other) const {
    double result = 0.0;
    for (std::size_t i = 0; i < N; i++) {
      result += data[i] * other[i];
    }
    return result;
  };

  // cross product (only for 2D and 3D vectors)
  auto cross(const Vector<N> &other) const {
    if constexpr (N == 2) {
      return data[0] * other[1] -
             data[1] * other[0]; // 2D cross product to scalar (z-component)
    } else if constexpr (N == 3) {
      // 3D cross product to vector
      return Vector<3>{data[1] * other[2] - data[2] * other[1],
                       data[2] * other[0] - data[0] * other[2],
                       data[0] * other[1] - data[1] * other[0]};
    } else {
      static_assert(N == 2 || N == 3,
                    "Cross product only defined for 2D and 3D vectors");
    }
  }
};

using Vector2D = Vector<2>;
using Vector3D = Vector<3>;

/*
 * printing overload
 */

template <std::size_t N>
std::ostream &operator<<(std::ostream &cout, const Vector<N> &vector) {
  os << "Vector" << N << "D (";
  for (std::size_t i = 0; i < N; ++i) {
    cout << vector[i];
    if (i + 1 < N)
      cout << ", ";
  }
  cout << ")";
  return cout;
}