#pragma once
#include <vector>
class FigureBase
{
public:
	
	virtual std::vector<double> Point(double t) = 0; // ���������� ���������� ����� �� ��������� t
	virtual std::vector<double> firstDerivative(double t) = 0; // ���������� ������ �����������  �� ��������� t(������)
	virtual int Flag() = 0; 
	virtual double get_Radius()=0; // ���������� ����� (��� Ellepses, ������ ������� �������)
	
};

