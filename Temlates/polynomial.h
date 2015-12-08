#pragma once
#include "stdafx.h"
namespace OOPLabs
{
	class polynomial
	{
	private:
		double* coeff;
		int n;
	public:
		polynomial(double* = NULL,int = 0);
		polynomial(double, int);
		polynomial(const polynomial&);
		polynomial& operator=(const polynomial&);
		polynomial& operator*=(const polynomial&);
		polynomial& operator*=(double);
		polynomial& operator/=(const polynomial&);
		polynomial& operator%=(const polynomial&);
		polynomial& operator+=(const polynomial&);
		polynomial& operator-=(const polynomial&);
		friend bool operator==(const polynomial&, double);
		friend bool operator!=(const polynomial&, double);
		friend bool operator>(const polynomial&, const polynomial&);
		double operator()(double) const;
		void Update();
		int Power();
		friend std::ostream& operator<<(std::ostream&, const polynomial&);
	};
	polynomial operator*(const polynomial&, const polynomial&);
	polynomial operator/(const polynomial&, const polynomial&);
	polynomial operator%(const polynomial&, const polynomial&);
	polynomial operator*(const polynomial&, double);
	polynomial operator*(double, const polynomial&);
	polynomial operator+(const polynomial&, const polynomial&);
	polynomial operator-(const polynomial&, const polynomial&);
	
	

};
