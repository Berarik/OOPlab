#include "stdafx.h"

using namespace std;
namespace OOPLabs
{
	char ec1[] = "некорректный размер матрицы є ";
	char ec2[] = "некорректный индекс матрицы є ";
	char ec3[] = "невозможно найти максимальный/минимальный элемент в матрице є ";
	char ec4[] = "невозможно сложить/вычесть матрицу є ";
	char ec41[] = " и матрицу є ";
	char ec5[] = "невозможно умножить матрицу є ";
	char ec51[] = " на матрицу є ";
	char ec6[] = "ќтрицательный размер  вадрата є";
	Exception::Exception(int errornumb, int m1, int m2)
	{
		m1 = m1;
		m2 = m2;
		ExceptionNumber = errornumb;
	}
	void Exception::GetException()
	{
		switch (ExceptionNumber)
		{
		case 1:
			cout << ec1 << m1 << endl;
			break;
		case 2:
			cout << ec2 << m1 << endl;
			break;
		case 3:
			cout << ec3 << m1 << endl;
			break;
		case 4:
			cout << ec4 << m1 << ec41 << m2 << endl;
			break;
		case 5:
			cout << ec5 << m1 << ec51 << m2 << endl;
			break;
		case 6:
			cout << ec6 << endl;
			break;
		}
	}
}