#include <iostream>
#include <string>
#include <vector>
#include "../ppm/ppm.h"
#include "Array.h"
#include "Image.h"
#include "Filter.h"
#include "FilterLinear.h"
#include "FilterGamma.h"
#include "FilterBlur.h"
#include "FilterLaplace.h"
#include "Vec3.h"

using namespace std;
using namespace math;
using namespace imaging;

int main(int argc, char* argv[])
{
	bool file=false;
	bool inputs = false;
	vector <Filter*> filters;
	int i = 1;
	string ppmname;
	while(i<argc)
	{
		if (string(argv[i]) == "-f")
		{
			inputs = true;
			i++;
			if (string(argv[i]) == "gamma")
			{
				filters.push_back(new  FilterGamma(stof(argv[i + 1])));
				i+=2;
			}
			else if (string(argv[i]) == "linear")
			{
				element a = element(stof(argv[i+1]), stof(argv[i + 2]), stof(argv[i + 3]));
				element c = element(stof(argv[i + 4]), stof(argv[i + 5]), stof(argv[i + 6]));
				filters.push_back(new  FilterLinear(a, c));
				i += 7;
			}
			else if (string(argv[i]) == "blur")
			{
				int n = stoi(argv[i + 1]);
				filters.push_back(new FilterBlur(n));
				i += 2;
			}
			else if (string(argv[i]) == "laplace")
			{
				filters.push_back(new FilterLaplace());
				i++;
			}
			else
			{
				cout << "Wrong input!" << endl;
				return 0;
			}
		}
		else
		{
			if (i == argc - 1)
			{
				ppmname = string(argv[i]);
				file = true;
				break;
			}
			else
			{
				cout << "File name wasnt last!Try again!"<<endl;
				return 0;
			}
		}
	}
	if (inputs&&file)
	{
		const string filename = ppmname;
		const string format = ppmname.substr(ppmname.find_last_of(".") + 1);


		Image MyImage = Image();
		if (MyImage.load(filename, format))
		{
			for (int i = 0; i < filters.size(); i++)
			{
				MyImage.setData((*filters[i] << MyImage).getRawDataPtr());
			}
		}
		const string NewFilename = ppmname.insert(0, "filtered_");
		if (MyImage.save(NewFilename, format))//Saving new image
		{
			cout << "File created!" << endl;
		}
		else
		{
			cout << "Could not create file." << endl;
		}


		for (int i = 0; i < filters.size(); i++)
		{
			filters.erase(filters.begin(),filters.end());
		}
	}
	else if(!file)
	{
		cout << "\nNo File given!"<<endl;
	}
}