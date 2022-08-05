#ifndef FilterB_
#define FilterB_

#include "Filter.h"
#include "Array.h"

using namespace imaging;
using namespace std;

class FilterBlur :virtual public Filter,virtual public math::Array<float> //extends both Filter and Array classes
{
private:
	int N;
	vector<float> f;
public:
	FilterBlur();

	FilterBlur(int n);

	FilterBlur(const FilterBlur &src);

	~FilterBlur();

	Image Sum(int N, const Image & image,vector<float> F);

	Image operator << (const Image & image);
};
#endif