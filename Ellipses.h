#pragma once
#include "FigureBase.h"

class Ellipses :
	public FigureBase
{
private:
	double radiusA;
	double radiusB;
	std::vector<double> coordinate;
public:
	Ellipses()
	{
		radiusA= (double)((rand() % 100 + 2) ); 
		radiusB = (double)((rand() % 100 + 3) ); 
	}
	std::vector<double> Point(double t) override
	{
		std::vector<double> coordinate;
		double x = radiusA * cos(t);
		coordinate.push_back(x);
		double y = radiusB * sin(t);
		coordinate.push_back(y);
		double z = 0;
		coordinate.push_back(z);
		return coordinate;

	}

	virtual std::vector<double> firstDerivative(double t) override
	{
		std::vector<double> vec;
		double x = radiusA * (-sin(t)); // (a*cost)`=a*(-sint)
		vec.push_back(x);
		double y = radiusB * (cos(t)); // (b*sint)`=b*(cost)
		vec.push_back(y);
		double z = 0; 
		vec.push_back(z);
		return vec;
	}

	

	virtual double get_Radius()
	{
		return radiusA;
	}

	virtual int Flag() override
	{
		return 1;
	}
};

