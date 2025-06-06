#include "MathFunctions.h"

#include <iostream>
// TODO 11: include cmath
#include <cmath>

// TODO 10: Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#ifdef USE_MYMATH
	#include "mysqrt.h"
#endif

namespace mathfunctions {
	double sqrt(double x)
	{
	  // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
	  #ifdef USE_MYMATH
	  	std::cout << "Using mysqrt" << std::endl;
	  	return detail::mysqrt(x);
	  #else
	  	std::cout << "Using std sqrt" << std::endl;
	  	return std::sqrt(x);
	  #endif
	}
}
