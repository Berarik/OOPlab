#include "stdafx.h"

using namespace std;

namespace OOPLabs 
{
	void Vector::init(int w, const Square* inHead, int k)
	{
		if (w>0)
		{
			n = w;
			m = 1;
			Head = new Square[n];
			int i = 0;
			if (k != 0)
			{
				if (inHead)
				{
					for (; i<k; i++)       Head[i] = inHead[i];
				}
			}
			for (; i<n; i++)    Head[i] = 0;
		}
		else
		{
			n = 0;
			m = 1;
			Head = 0;
		}
	}
	void Vector::init(const Square * inHead, int k)
	{
		int i = 0;
		if (k != 0)
		{
			if (inHead)
			{
				for (; i<k; i++)       Head[i] = inHead[i];
			}
		}
		for (; i<n; i++)    Head[i] = 0;
	}
	/*ostream& operator<<(ostream& os, const Vector& Vect)
	{
		setlocale(LC_ALL, "RUS");
		streamsize k = cout.width();
		cout << "Вектор №" << Vect.ind;
		if (Vect.m*Vect.n)
		{
			cout << endl;
			for (int i = 0; i < Vect.n; i++)
			{
				if (k > 0) cout.width(k);
				os << Vect[i];
				if (k <= 0) cout << " ";
				os << endl;
			}
		}
		else cout << " пустая" << endl;
		return os;
	}*/
	//bool oprtmlpt(const Vector& Vec, const matrix& Mtr)
	//{
	//	return (Vec.Width() == Mtr.Width());
	//}
	//bool oprtmlpt(const matrix& Mtr, const Vector& Vec)
	//{
	//	return (Mtr.Height() == Vec.Width());
	//}
	//bool Vector::oprtmlpt(const Vector& Vec)
	//{
	//	return (n == Vec.n);
	//}
	//bool Vector::oprtmlpt(const matrix& Vec)
	//{
	//	return (n == Vec.Width());
	//}
	/*bool oprtsum(const Vector& Vec, const matrix& Mtr)
	{
		return ((Vec.Width() == Mtr.Width() && Vec.Height() == Mtr.Height()));
	}
	bool oprtsum(const matrix& Mtr, const Vector& Vec)
	{
		return (Mtr.Width() == Vec.Width() && Mtr.Height() == Vec.Height());
	}*/
	/*bool Vector::oprtsum(const Vector& Vec)
	{
		return (n == Vec.n&&m == Vec.m);
	}*/
	Square& Vector::operator[](int i)
	{
		if (i < 0 || i >= n) throw Exception(9, ind);
		return Head[i];
	}
	const Square& Vector::operator[](int i) const
	{
		if (i < 0 || i >= n) throw Exception(9, ind);
		return Head[i];
	}
	Vector::Vector(const Vector& Vec)
	{
		init(Vec.n,Vec.Head,Vec.n);
	}
	Vector::Vector(const matrix& Mtr)
	{
		operator=(Mtr);
	}
	Vector::~Vector()
	{
		cout << "Деструктор Вектор №" << ind << endl;
		if (Head != NULL)
		{
			delete Head;
		}
		Head = 0;
	}
	//Vector& Vector::operator=(const Vector& mtr)
	//{
	//	if (this == &mtr)
	//	{
	//		return *this;
	//	}
	//	if (m*n != mtr.m*mtr.n)
	//	{
	//		if (m*n != 0)
	//			delete[]Head;
	//		m = mtr.m;
	//		n = mtr.n;
	//		if (m*n != 0)
	//			Head = new Square[m*n];
	//		else Head = NULL;
	//	}
	//	else
	//	{
	//		m = mtr.m;
	//		n = mtr.n;
	//	}
	//	for (int i = 0; i<m*n; i++)  Head[i] = mtr.Head[i];
	//	return *this;
	//}
	Vector& Vector::operator*=(const Square& k)
	{
		matrix::operator*=(k);
	//	for (int i = 0; i<n*m; i++)
	//	{
	//		Head[i] *= k;
	//	}
		return *this;
	}
	Vector& Vector::operator*=(const Vector& Vec)
	{
		matrix::operator*=(Vec);
		return *this;
	}
	//Vector& Vector::operator*=(const matrix& Vec)
	//{
	//	if (oprtmlpt(Vec))
	//	{
	//		matrix::operator*=(Vec);
	//		return *this;
	//	}
	//}
	Vector& Vector::operator=(const matrix& mtr)
	{
		if (this == &mtr)
		{
			return *this;
		}
		if (mtr.Height() == 1 || mtr.Height() == 0)
		{
			if (m*n != mtr.Width()*mtr.Height())
			{
				if (m*n != 0)
					delete[]Head;
				m = mtr.Height();
				n = mtr.Width();
				if (m*n != 0)
					Head = new Square[m*n];
				else Head = NULL;
			}
			else
			{
				m = mtr.Height();
				n = mtr.Width();
			}
			for (int i = 0,j=0; i < m*n; i++)  Head[i] = mtr[j][i];
		}
		else
			throw Exception(8, ind);
		return *this;
	}
	/*
	Vector& Vector::operator+=(const Vector& Vec)
	{
		if (oprtsum(Vec))
		{
			for (int i = 0; i<n; i++)  Head[i] += Vec.Head[i];
		}
		else throw Exception(7, ind, Vec.ind);
		return *this;
	}
	Vector& Vector::operator-=(const Vector& Vec)
	{
		if (oprtsum(Vec))
		{
			for (int i = 0; i<n; i++)  Head[i] += Vec.Head[i];
		}
		else throw Exception(7, ind, Vec.ind);
		return *this;
	}
	
	Vector& operator+(const Vector& l, const Vector& r)
	{
		Vector mtr(l);
		return mtr += r;
	}
	Vector& operator-(const Vector& l, const Vector& r)
	{
		Vector mtr(l);
		return mtr -= r;
	}
	Vector& operator*(const Vector& l, const Vector& r)
	{
		Vector mtr = l;
		return mtr *= r;
	}
	Vector operator*(const Vector& l, const Square& k)
	{
		Vector mtr(l);
		return mtr *= k;
	}*/
	//matrix & operator+=(matrix & mtr, Vector & vec)
	//{
	//	if (oprtsum(mtr, vec))
	//		return mtr;
	//	else throw Exception(8, mtr.Index(), vec.ind);
	//}
	//matrix & operator-=(matrix & mtr, Vector & vec)
	//{
	//	if (oprtsum(mtr, vec))
	//		return mtr;
	//	else throw Exception(8, mtr.Index(), vec.ind);
	//}
	matrix & operator*=(matrix & mtr, Vector & vec)
	{
		if (vec.oprtmlpt(mtr))
			return mtr;
		else throw Exception(10, mtr.Index());
	}
	//Vector& Vector::operator*=(const matrix& mtr)
	//{
	//	return *this;
	//}
	//Vector& Vector::operator+=(const matrix& Vec)
	//{
	//	if (oprtsum(Vec))
	//	{
	//		for (int i = 0,j=0; i<n; i++)  Head[i] += Vec[j][i];
	//	}
	//	else throw Exception(10, ind);
	//	return *this;
	//}
	//Vector& Vector::operator-=(const matrix& Vec)
	//{
	//	if (oprtsum(Vec))
	//	{
	//		for (int i = 0, j = 0; i<n; i++)  Head[i] -= Vec[j][i];
	//	}
	//	else throw Exception(10, ind);
	//	return *this;
	//}
//	Vector& operator+(const Vector& l, const matrix& r)
//	{
//		Vector mtr(l);
//		return mtr += r;
//	}
//	Vector& operator-(const Vector& l, const matrix& r)
//	{
//		Vector mtr(l);
//		return mtr -= r;
//	}
	//Vector& operator*(const matrix& l, const Vector& r)
	//{
	//	matrix mtr = l;
	//	return Vector(mtr *= r);
	//}
	//matrix& operator*(const Vector& l, const matrix& r)
	//{
	//	matrix Mtr=l;
	//	return Mtr*=r;
	//}
}
