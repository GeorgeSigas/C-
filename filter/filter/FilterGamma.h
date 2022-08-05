#ifndef FilterG_
#define FilterG_

#include "Filter.h"

using namespace imaging;
using namespace std;

class FilterGamma :virtual public Filter
{
private:
	float g;
public:

	FilterGamma();

	FilterGamma(float gamma);

	FilterGamma(const FilterGamma &src);

	~FilterGamma();

	Image operator << (const Image & image);
};
#endif