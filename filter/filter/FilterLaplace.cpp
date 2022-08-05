#include "FilterLaplace.h"
#include "FilterBlur.h"
#include <iostream>
#include <vector>

using namespace imaging;
using namespace math;
using namespace std;

FilterLaplace::FilterLaplace()
{
	int ints[] = { 0,1,0,1,-4,1,0,1,0 };
	f.assign(ints,ints+9);
}

FilterLaplace::FilterLaplace(const FilterLaplace &src)
{
	f = src.f;
}

FilterLaplace::~FilterLaplace(){}

Image FilterLaplace:: operator << (const Image & image)
{
	cout << "Applying Laplace..." << endl;

	
	return FilterBlur::Sum(3,image,f);
}