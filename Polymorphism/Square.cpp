#include "stdafx.h"

using namespace std;

namespace OOPLabs
{
	Square& Square::operator*=(double X)
	{
		double x = a;
		x *= X;
		if (x >= 0)
		{
			(*this).setA(x);
			return *this;

		}
		else throw Exception(6);
	};
	Square& Square::operator*=(const Square& L)
	{
		double x = a;
		x *= L.getA();
		if (x >= 0)
		{
			(*this).setA(x);
			return *this;
		}
		else throw Exception(6);
	};
	Square& Square::operator+=(const Square& L)
	{
		double x = a;
		x += L.getA();
		if (x >= 0)
		{
			(*this).setA(x);
			return *this;
		}
		else throw Exception(6);
	};
	Square& Square::operator-=(const Square& L)
	{
		double x = a;
		x -= L.getA();
		if (x >= 0)
		{
			(*this).setA(x);
			return *this;
		}
		else throw Exception(6);
	};
	Square::Square(double inX, double inY, double inA)
	{
		x = inX;
		y = inY;
		if (inA < 0)
			throw "a<0";
		a = inA;
	}
	double Square::getCoorX() const
	{
		return x;
	}
	double Square::getCoorY() const
	{
		return y;
	}
	double Square::getA() const
	{
		return a;
	}
	void Square::setcoorX(double inX)
	{
		x = inX;
	}
	void Square::setcoorY(double inY)
	{
		y = inY;
	}
	void Square::setA(double inA)
	{
		if (inA < 0)
			throw "a<0";
		a = inA;
	}
	bool Square::AlessB(const Square& A) const
	{
		return (*this).a < A.a;
	}

	Square operator*(const Square& L, double R) { Square mtr(L);	return mtr *= R; };
	Square operator*(const Square& L, const Square& R) { Square mtr(L);	return mtr *= R; };
	Square operator+(const Square& L, const Square& R) { Square mtr(L);	return mtr += R; };
	Square operator-(const Square& L, const Square& R) { Square mtr(L);	return mtr -= R; };
	ostream& operator<<(ostream& os, const Square& sq)
	{
		streamsize k = cout.width();
		if (k <= 0) k = 5;
		cout << "(";
		cout.width(k / 3);
		cout << sq.getCoorX() << ",";
		cout.width(k / 3);
		cout << sq.getCoorY() << ") ";
		cout.width(k / 3);
		cout << sq.getA() << " ";
		return os;
	}
};