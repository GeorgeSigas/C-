#include <iostream>
#include "FilterLinear.h"

using namespace imaging;
using namespace std;
using namespace math;

FilterLinear::FilterLinear()
{
	a = 0;
	c = 0;
}

FilterLinear::FilterLinear(element FirstVec3, element SecVec3)
{
	a = FirstVec3;
	c = SecVec3;
}

FilterLinear::FilterLinear(const FilterLinear &src)
{
	a = src.a;
	c = src.c;
}

FilterLinear::~FilterLinear(){}

Image FilterLinear:: operator << (const Image & image)
{
	cout << "Applying Linear..."<<endl;
	Image NewImage = Image(image.getWidth(), image.getHeight());
	element NewElement;
	for (unsigned int i = 0; i < image.getHeight(); i++)
	{
		for (unsigned int j = 0; j < image.getWidth(); j++)
		{
			NewElement = a*(image.getItem(i, j)) + c;
			NewElement = NewElement.clampToLowerBound(0);
			NewElement = NewElement.clampToUpperBound(1.0);
			NewImage.setItem(i, j, NewElement);
		}
	}
	return NewImage;
}