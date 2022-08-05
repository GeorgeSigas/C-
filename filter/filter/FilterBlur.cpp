#include "FilterBlur.h"
#include <iostream>

using namespace imaging;
using namespace math;
using namespace std;

FilterBlur::FilterBlur()
{
	N = 0;
}

FilterBlur::FilterBlur(int n)
{
	N = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f.push_back(1 / float(pow(n, 2)));
		}
	}
}

FilterBlur::FilterBlur(const FilterBlur &src)
{
	N = src.N;
}

FilterBlur::~FilterBlur(){}

Image FilterBlur::Sum(int N, const Image & image, vector<float> f)
{
	Image NewImage = Image(image.getWidth(), image.getHeight());

 	int m = 0;
	int n = 0;
	Array F = Array(N, N, f);
	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int j = 0; j < image.getWidth(); j++) //for every pixel
		{
			element NewElement = 0;
			for (m = -N / 2; m <= N / 2; m++)
			{
				for (n = -N / 2; n <= N / 2; n++)
				{
					if (((j + n >= 0) && (j + n < image.getHeight())) || ((i + m >= 0) && (i + m < image.getWidth())))
					{

						NewElement += image.getItem(i + m, j + n)*F.getItem(m + N / 2, n + N / 2);

					}
				}
			}
			NewElement = NewElement.clampToUpperBound(1.0);
			NewElement = NewElement.clampToLowerBound(0);
			NewImage.setItem(i, j, NewElement);
		}
	}
	return NewImage;
}


Image FilterBlur:: operator << (const Image & image)
{
	cout << "Applying Blur..." << endl;
	
	return Sum(N,image,f);
}