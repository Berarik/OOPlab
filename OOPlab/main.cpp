// OOPlab.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		cout << "�������� �������� A < �������� �������� B\n";
	}
	else
	{
		cout << "�������� �������� A >= �������� �������� B\n";

	}
	if(AlessB(A, C))
	{
		cout << "�������� �������� A < �������� �������� C\n";
	}
	else
	{
		cout << "�������� �������� A >= �������� �������� C\n";

	}
	/*	//	vect explctvect=1;
	//	explctvect.coutcoor();
	const double f = -7;
	cout << "��� ������������ �1" << endl;
	vect A(11, 13, 1);
	A.coutcoor();
	vect B(-1, 1, 3);
	B.coutcoor();
	vect c(0, 0, 0);
	c.cpvect(A);
	cout << "����������� ������� A � C" << endl;
	c.coutcoor();
	c.mlpt(f);
	cout << "��������� ������� �� ������ A * " << f << endl;
	c.coutcoor();
	c.cpvect(sum(A, B));
	cout << "�������� �������� A � B" << endl;
	c.coutcoor();
	c.cpvect(sub(A, A));
	cout << "��������� �� ������� A ������� A" << endl;
	c.coutcoor();
	c.cpvect(vmlpt(A, B));
	cout << "��������� ������������ A � B" << endl;
	c.coutcoor();
	cout << "������ ������� C = " << c.modul() << endl;
	if (c.norm())
	{
		cout << "���������� ������� C" << endl;
		c.coutcoor();
	}
	else
	{
		cout << "���������� ������� C ��������� " << endl;
		c.coutcoor();
	}
	cout << "������ ������� C = " << c.modul() << endl;
	cout << "���� AOB = " << anglevect(A, B) << endl
		<< "���� AOC = " << anglevect(A, c) << endl;
	*/
	cout << "���������� ������ ���������.\n������� ����� ������� ��� �������� ���������." << endl;
	cin.get();
	return 0;
}