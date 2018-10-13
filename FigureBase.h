#pragma once
#include <vector>
class FigureBase
{
public:
	
	virtual std::vector<double> Point(double t) = 0; // возвращает координаты точки по параметру t
	virtual std::vector<double> firstDerivative(double t) = 0; // возвращает первую производную  по параметру t(вектор)
	virtual int Flag() = 0; 
	virtual double get_Radius()=0; // возвращает радис (для Ellepses, радиус большей полуоси)
	
};

