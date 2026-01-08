#pragma once

#include "../math/Vector.hpp"

template <std::size_t N> struct Body {
  Vector<N> position;
  Vector<N> velocity;
  Vector<N> force;
  double
      inverseMass; // 1 / mass because multiplication is cheaper than division
};

using Body2D = Body<2>;
using Body3D = Body<3>;