#pragma once
#include "stdafx.h"

namespace OOPLabs{
	class Square
	{
	private:
		double x, y, a;
	public:
		Square(double inX=0, double inY=0, double inA=0);
		double getCoorX() const;
		double getCoorY() const;
		double getA() const;
		void setcoorX(double inX);
		void setcoorY(double inY);
		void setA(double inA);
		bool AlessB(const Square& A) const;
		Square& operator*=(double);
		Square& operator*=(const Square&);
		Square& operator+=(const Square&);
		Square& operator-=(const Square&);
		friend std::ostream& operator<<(std::ostream&, const Square&);
	};
	Square operator*(const Square&, const Square&);
	Square operator*(const Square&, double);
	Square operator+(const Square&, const Square&);
	Square operator-(const Square&, const Square&);
}