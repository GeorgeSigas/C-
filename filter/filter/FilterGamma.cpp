#include <iostream>
#include "FilterGamma.h"

using namespace imaging;
using namespace std;

FilterGamma::FilterGamma()
{
	g = 1.0;
}

FilterGamma::FilterGamma(float gamma)
{
	if (gamma < 0.5)
	{
		g = 0.5;
	}
	else if (gamma > 2.0)
	{
		g = 2.0;
	}
	else
	{
		g = gamma;
	}
}

FilterGamma::FilterGamma(const FilterGamma &src)
{
	g = src.g;
}

FilterGamma::~FilterGamma(){}


Image FilterGamma::operator << (const Image & image)
{
	cout << "Applying Gamma..."<<endl;
	Image NewImage = Image(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int j = 0; j < image.getWidth(); j++)
		{
			element NewElement = image.getItem(i, j);
			NewElement.x = pow(NewElement.x, g);
			NewElement.y = pow(NewElement.y, g);
			NewElement.z = pow(NewElement.z, g);
			NewImage.setItem(i, j, NewElement);
		}
	}
	return NewImage;
}