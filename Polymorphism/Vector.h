#pragma once

#include "stdafx.h"
#include "Matrix.h"

namespace OOPLabs
{

	class Vector : matrix
	{
	public:
		Vector(int wh = 0, double*inVect = NULL, int k = 0) :matrix(wh, 1, inVect, k) {};
		Vector(Vector&);
		friend std::ostream& operator<<(std::ostream&, const Vector&);
		bool oprtmlpt(const Vector&, const matrix&);
		bool oprtmlpt(const matrix&, const Vector&);
		bool oprtmlpt(const Vector&);
		bool oprtsum(const Vector&, const matrix&);
		bool oprtsum(const matrix&, const Vector&);
		bool oprtsum(const Vector&);
	};
//	/*class Vector :public Matrix
//	{
//		explicit Vector(int m =  0, double*inVect = NULL, int k = 0):Matrix(m, 1, inVect, k)
//		{}
//		explicit Vector(Matrix&)
//		{}
//		Vector(Vector&);
//		~Vector();
//		Vector& operator=(const Vector&);
//		Vector& operator+=(const Vector&);
//		Vector& operator-=(const Vector&);
//		Vector& operator*=(const Vector&);
//		Vector& operator*=(double);
//		double* operator[](int);
//		const double* operator[](int) const;
//
//	};*/
//	//class Vector: public Matrix
//	//{
//	//private:
//	//	//double x, y, z;
//	//	//static int cnt;
//	//	//int ind;
//	//public:
//	//	//explicit vect(double = 0, double = 0, double = 0);//        /*explicit*/ vect();
//	//	//~vect();
//	//	//void coutcoor() const;
//	//	//double readx() const;
//	//	//double ready() const;
//	//	//double readz() const;
//	//	//void writex(double);
//	//	//void writey(double);
//	//	//void writez(double);
//	//	//void cpvect(const vect&);
//	//	//void mlpt(double);
//	//	//bool norm();
//	//	//double modul() const;
//	//};
//	/*vect sum(const vect&, const vect&);
//	vect sub(const vect&, const vect&);
//	vect vmlpt(const vect &, const vect &);
//	double anglevect(const vect&, const vect&);
//	double sinvect(const vect&, const vect&);
//	double cosvect(const vect&, const vect&);
//	double smlpt(const vect&, const vect&);*/
}
