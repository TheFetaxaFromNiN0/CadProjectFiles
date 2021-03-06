// FigursWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "Circles.h"
#include "Helixes.h"
#include "Ellipses.h"
#include "FigureBase.h"
#include <algorithm>
#include <memory>


std::vector<std::shared_ptr <FigureBase>> randomFigure(std::vector<std::shared_ptr <FigureBase>>); // заполняет случайным образом контейеекр объектами
std::vector<std::shared_ptr <FigureBase>>  chooseCircles(std::vector<std::shared_ptr <FigureBase>>); // заполняет контейнер окружностями из первого контейнера
bool comparator(std::shared_ptr <FigureBase> a, std::shared_ptr <FigureBase> b); // функция для сортировки(используется в функции sort из STL)
double get_SumRadius(std::vector<std::shared_ptr <FigureBase>>); // возращает сумму радиуса для окружности из 2го контейнера
void ShowCordinate(std::vector<double>);


int main()
{

	double sum = 0;
	double t;
	std::vector<std::shared_ptr <FigureBase>> vec; // контейнер для всех фигур
	std::vector<std::shared_ptr <FigureBase>>  vecCircles;// контейнер только для окружностей
	vec = randomFigure(vec);
	printf("Coordinates:\n");
	for (std::shared_ptr <FigureBase> v : vec)
	{
		t = (double)(rand() % 628 / 100);
		printf("t=%f \n", t);
		ShowCordinate(v->Point(t));
		printf("-coordinate\n");
		ShowCordinate(v->firstDerivative(t));
		printf("-coordinateDerivative");
		printf("\n");
	}
	printf("\n----------------------------\n");
	vecCircles = chooseCircles(vec);
	printf("\n----------------------------\n");
	for (std::shared_ptr <FigureBase> v2 : vecCircles)
	{
		printf("rad %f  - not sorted\n", v2->get_Radius());
	}
	printf("\n----------------------------\n");
	std::sort(vecCircles.begin(), vecCircles.end(), comparator);
	for (std::shared_ptr <FigureBase> v2 : vecCircles)
	{
		printf("rad %f -sorted\n", v2->get_Radius());
	}

	sum = get_SumRadius(vecCircles);
	printf("\n----------------------------\n");
	printf("%f- sum of radius\n", sum);

}


std::vector<std::shared_ptr <FigureBase>> randomFigure(std::vector<std::shared_ptr <FigureBase>> v)
{
	// Путь создаётся 10 объектов 3х классов случайным образом
	std::vector<int> mask(10);
	for (int i = 0; i < 10; i++)
	{
		mask[i] = rand() % 3;
	}

	for (int m : mask)
	{
		printf("%d ", m);
	}
	printf("\n ");
	for (int i = 0; i < 10; i++)
	{
		if (mask[i] == 0)
		{

			v.emplace_back(std::make_shared<Сircles>());
		}
		if (mask[i] == 1)
		{

			v.emplace_back(std::make_shared<Ellipses>());
		}
		if (mask[i] == 2)
		{

			v.emplace_back(std::make_shared<Helixes>());
		}

	}
	return v;

}



std::vector<std::shared_ptr <FigureBase>>  chooseCircles(std::vector<std::shared_ptr <FigureBase>>  v)
{
	std::vector<std::shared_ptr <FigureBase>>  vec;
	for (std::shared_ptr <FigureBase> vector : v)
	{
		if (vector->Flag() == 0)
		{
			vec.push_back(vector);
		}

	}
	return vec;

}
void ShowCordinate(std::vector<double> coor)
{
	for (double c : coor)
	{
		printf("{%f}", c);
	}
}




bool comparator(std::shared_ptr <FigureBase> a, std::shared_ptr <FigureBase> b)
{
	return (a->get_Radius() < b->get_Radius());
}

double get_SumRadius(std::vector<std::shared_ptr <FigureBase>> vec)
{
	double sum = 0;
	for (std::shared_ptr <FigureBase> v : vec)
	{
		sum = sum + v->get_Radius();
	}
	return sum;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
