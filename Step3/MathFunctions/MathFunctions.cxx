#include "MathFunctions.h"

#include <cmath>
#include <iostream>

#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{
// which square root function should we use?
#ifdef USE_MYMATH
  std::cout << "Use our own square root function" << std::endl;
  return detail::mysqrt(x);
#else
  std::cout << "Use the standard square root function" << std::endl;
  return std::sqrt(x);
#endif
}
}
