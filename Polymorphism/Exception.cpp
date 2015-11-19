#include "stdafx.h"
#include "Exception.h"
using namespace std;
char EC1[] = "Некорректный размер Матрицы № ";
char EC2[] = "Некорректный индекс Матрицы № ";
char EC3[] = "Невозможно найти максимальный/минимальный элемент в матрице № ";
char EC4[] = "Невозможно сложить/вычесть матрицу № ";
char EC41[] = " и матрицу № ";
char EC5[] = "Невозможно умножить матрицу № ";
char EC51[] = " на матрицу № ";
char EC6[] = "Невозможно умножить Вектор № ";
char EC61[] = " на вектор № ";
char EC7[] = "Невозможно сложить/вычесть вектор № ";
char EC71[] = " и вектор № ";
char EC11[] = "Невозможно скопировать Вектора № ";
char EC111[] = " на матрицу № ";
char EC9[] = "Некорректный индекс Вектора № ";

Exception::Exception(int ErrorNumb, int M1, int M2)
{
	o1 = M1;
	o2 = M2;
	ExceptionNumber = ErrorNumb;
}
void Exception::GetException()
{
	switch (ExceptionNumber)
	{
	case 1:
		cout << EC1 << o1 << endl;
		break;
	case 2:
		cout << EC2 << o1 << endl;
		break;
	case 3:
		cout << EC3 << o1 << endl;
		break;
	case 4:
		cout << EC4 << o1 << EC41 << o2 << endl;
		break;
	case 5:
		cout << EC5 << o1 << EC51 << o2 << endl;
		break;
	case 6:
		cout << EC6 << o1 << EC6 << o2 << endl;
		break;
	case 7:
		cout << EC7 << o1 << EC71 << o2 << endl;
		break;
	case 8:
		cout << EC4 << o1 << EC71 << o2 << endl;
		break;
	case 9:
		cout << EC9 << o1 << endl;
		break;
	case 10:
		cout << EC5 << o1 << EC61 <<o2<<endl;
		break;
	case 11:
		cout << EC11 << o1 << EC51 << o2 << endl;
		break;
	}
}