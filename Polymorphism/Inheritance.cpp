// Polymorphism.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace OOPLabs;
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	const int k = 3;
	//double x[k] = { 3,4.9,7 };
	Square Sq[9];
	for (int i = 0; i < 9; i++)
	{
		Sq[i].setA(rand() % (i + 1) + 5);
		Sq[i].setcoorX(rand() % (i + 1) + 8);
		Sq[i].setcoorY(rand() % (i + 1) + 2);
	}
	int mjj = 3;
	matrix M1(3, 1, Sq, 3);
	cout << M1 << endl;
	matrix M2(3,1, (Sq+4), 3);
	cout << M2 << endl;
	Vector V1(3,Sq,k);
	cout << V1 << endl;
	Vector v2(V1);
	cout << v2 << endl;
	if (v2.oprtsum(V1))
	{
		v2 += V1;
		cout << v2;
	}

	cout << "Завершение работы программы.\nНажмити любую кнопку для выхода." << endl;
	cin.get();
    return 0;
}

//1. Конструкторы(по умолчанию+, с параметрами+, копирующий+);
//2. Проверка возможности сложения и умножения объектов(вектора и вектора+, вектора и матрицы+, матрицы и вектора+, матрицы и матрицы+);
//3. Оператор доступа к элементам вектора и матрицы[];+
//4. Оператор вывода в поток <<;+
//5. Математические операторы(+, –, *, +=, –=, *=, =) с объектами, а также умножение объектов на скаляр;