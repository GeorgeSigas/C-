#ifndef FilterL_
#define FilterL_

#include "Filter.h"
#include "Array.h"
#include "Image.h"
#include "Vec3.h"

using namespace imaging;
using namespace std;
using namespace math;

class FilterLinear :virtual public Filter 
{
private:
	element a, c;
public:

	FilterLinear();

	FilterLinear(element FirstVec3, element SecVec3);

	FilterLinear(const FilterLinear &src);

	~FilterLinear();


	Image operator << (const Image & image);
};
#endif