#ifndef FilterLa_
#define FilterLa_

#include "Filter.h"
#include "FilterBlur.h"

using namespace imaging;
using namespace std;

class FilterLaplace : public FilterBlur
{
private:
	vector<float> f;
public:
	FilterLaplace();

	FilterLaplace(const FilterLaplace &src);

	~FilterLaplace();

	Image operator << (const Image & image);
};
#endif
