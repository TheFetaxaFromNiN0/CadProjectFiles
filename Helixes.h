#pragma once
#include "FigureBase.h"
class Helixes :
	public FigureBase
{
private:
	double radius;
public:
	Helixes()
	{
		radius= (double)((rand() % 100+1)); 
	}
	std::vector<double> Point(double t) override
	{
		std::vector<double> coordinate;
		double x = radius * cos(t);
		coordinate.push_back(x);
		double y = radius * sin(t);
		coordinate.push_back(y);
		double z = t;
		coordinate.push_back(z);
		return coordinate;

	}


	virtual std::vector<double> firstDerivative(double t) override
	{
		std::vector<double> vec;
		double x = radius * (-sin(t)); // (r*cost)`=r*(-sint)
		vec.push_back(x);
		double y = radius * (cos(t)); // (r*sint)`=r*(cost)
		vec.push_back(y);
		double z = t; // t`=1
		vec.push_back(z);
		return vec;
	}
	
	

	virtual double get_Radius()
	{
		return radius;
	}
	virtual int Flag() override
	{
		return 2;
	}
};

