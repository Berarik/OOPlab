#pragma once

#include "stdafx.h"
#include <stdarg.h>
#include <stdlib.h>
#include <iomanip>
#include "Exception.h"


namespace OOPLabs
{
	class Matrix
	{
	protected:
		static int cnt;
		int ind, m, n;
		double* Head;
	public:
		explicit Matrix(int, int = 0, double*inHead = NULL, int = 0);
		explicit Matrix(int = 0, double*inHead = NULL, int = 0);
		Matrix(const Matrix&);
		virtual ~Matrix();
		bool oprtmlpt(const Matrix&);
		bool oprtsum(const Matrix&);
		Matrix& operator=(const Matrix&);
		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(double);
		double* operator[](int);
		const double* operator[](int) const;
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		int Width() const;
		int Height() const;
	};
		class Vector : Matrix
		{
		public:
			Vector(int wh = 0, double*inVect = NULL, int k = 0) :Matrix(wh, 1, inVect, k) {};
			Vector(Vector&);
			friend std::ostream& operator<<(std::ostream&, const Vector&);
			bool oprtmlpt(const Vector&, const Matrix&);
			bool oprtmlpt(const Matrix&, const Vector&);
			bool oprtmlpt(const Vector&);
			bool oprtsum(const Vector&,const Matrix&);
			bool oprtsum(const Matrix&, const Vector&);
			bool oprtsum(const Vector&);
			//Matrix&
			//explicit Vector(Matrix&)
			//{}
		//	Vector(Vector& vec) :Matrix(vec) {};
			/*Vector& operator=(const Vector&);
			Vector& operator+=(const Vector&);
			Vector& operator-=(const Vector&);
			Vector& operator*=(const Vector&);
			Vector& operator*=(double);
			double* operator[](int);
			const double* operator[](int) const;*/
		};
	Matrix& operator+(const Matrix&, const Matrix&);
	Matrix& operator-(const Matrix&, const Matrix&);
	Matrix& operator*(const Matrix&, const Matrix&);
	Matrix& operator*(const Matrix&, double);
	//Vector& operator+(const Vector&, const Vector&);
	//Vector& operator-(const Vector&, const Vector&);
	//Vector& operator*(const Vector&, const Vector&);
	//Vector& operator*(const Vector&, double);

}