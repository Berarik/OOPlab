// OOPlab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vector.h"
#include <locale.h>

using namespace std;
using namespace OOPLab;

class Square
{
private:
	double x, y, a;
public:
	Square(double inX = 0, double inY = 0, double inA = 0)
	{
		x = inX;
		y = inY;
		if (inA < 0)
			throw "a<0";
		a = inA;
	}
	double getCoorX() const
	{
		return x;
	}
	double getCoorY() const
	{
		return y;
	}
	double getA() const
	{
		return a;
	}
	void setcoorX(double inX)
	{
		x = inX;
	}
	void setcoorY(double inY)
	{
		y = inY;
	}
	void setA(double inA)
	{
		if (inA < 0)
			throw "a<0";
		a = inA;
	}
	bool AlessB(const Square& A/*,const Square& B*/) const
	{
		return (*this).a < A.a;
	}
};
bool AlessB(const Square& A, const Square& B)
{
	return A.getA() < B.getA();
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Square A(0, 0, 3),B(3,5,5),C(1,3,1);
	if (A.AlessB(B))
	{
		cout << "Стророна квадрата A < Стророна квадрата B\n";
	}
	else
	{
		cout << "Стророна квадрата A >= Стророна квадрата B\n";

	}
	if(AlessB(A, C))
	{
		cout << "Стророна квадрата A < Стророна квадрата C\n";
	}
	else
	{
		cout << "Стророна квадрата A >= Стророна квадрата C\n";

	}
	/*	//	vect explctvect=1;
	//	explctvect.coutcoor();
	const double f = -7;
	cout << "ООП лабораторная №1" << endl;
	vect A(11, 13, 1);
	A.coutcoor();
	vect B(-1, 1, 3);
	B.coutcoor();
	vect c(0, 0, 0);
	c.cpvect(A);
	cout << "Копирование вектора A в C" << endl;
	c.coutcoor();
	c.mlpt(f);
	cout << "Умножение вектора на скаляр A * " << f << endl;
	c.coutcoor();
	c.cpvect(sum(A, B));
	cout << "Сложение векторов A и B" << endl;
	c.coutcoor();
	c.cpvect(sub(A, A));
	cout << "Вычитание из вектора A вектора A" << endl;
	c.coutcoor();
	c.cpvect(vmlpt(A, B));
	cout << "Векторное произведение A и B" << endl;
	c.coutcoor();
	cout << "Модуль вектора C = " << c.modul() << endl;
	if (c.norm())
	{
		cout << "Нормировка вектора C" << endl;
		c.coutcoor();
	}
	else
	{
		cout << "Нормировка вектора C неудалась " << endl;
		c.coutcoor();
	}
	cout << "Модуль вектора C = " << c.modul() << endl;
	cout << "Угол AOB = " << anglevect(A, B) << endl
		<< "Угол AOC = " << anglevect(A, c) << endl;
	*/
	cout << "Завершение работы программы.\nНажмите любую клавишу для закрытия программы." << endl;
	cin.get();
	return 0;
}