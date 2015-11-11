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
	ostream& operator<<(ostream& os, const Vector& Vect)
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
	}
	bool Vector::oprtmlpt(const Vector& Vec, const matrix& Mtr)
	{
		return (Vec.m == Mtr.Width());
	}
	bool Vector::oprtmlpt(const matrix& Mtr, const Vector& Vec)
	{
		return (Mtr.Height() == Vec.n);
	}
	bool Vector::oprtmlpt(const Vector& Vec)
	{
		return (m == Vec.n);
	}
	bool Vector::oprtsum(const Vector& Vec, const matrix& Mtr)
	{
		return ((Vec.n == Mtr.Width() && Vec.m == Mtr.Height()));
	}
	bool Vector::oprtsum(const matrix& Mtr, const Vector& Vec)
	{
		return (Mtr.Width() == Vec.n&&Mtr.Height() == Vec.m);
	}
	bool Vector::oprtsum(const Vector& Vec)
	{
		return (n == Vec.n&&m == Vec.m);
	}
	Square& Vector::operator[](int i)
	{
		return Head[i];
	}
	const Square& Vector::operator[](int i) const
	{
		return Head[i];
	}
	Vector::Vector(const Vector& Vec)
	{
		init(Vec.n,Vec.Head,Vec.n);
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
	Vector& Vector::operator=(const Vector& mtr)
	{
		if (this == &mtr)
		{
			return *this;
		}
		if (m*n != mtr.m*mtr.n)
		{
			if (m*n != 0)
				delete[]Head;
			m = mtr.m;
			n = mtr.n;
			if (m*n != 0)
				Head = new Square[m*n];
			else Head = NULL;
		}
		else
		{
			m = mtr.m;
			n = mtr.n;
		}
		for (int i = 0; i<m*n; i++)  Head[i] = mtr.Head[i];
		return *this;
	}
	Vector& Vector::operator*=(const Vector& Vec)
	{
		return *this;
	}
	Vector& Vector::operator+=(const Vector& Vec)
	{
		if (oprtsum(Vec))
		{
			for (int i = 0; i<m*n; i++)  Head[i] += Vec.Head[i];
		}
		else throw Exception(4, ind, Vec.ind);
		return *this;
	}
	Vector& Vector::operator-=(const Vector& Vec)
	{
		for (int i = 0; i < m; i++)
		{
			Head[i] -= Vec.Head[i];
		}
		return *this;
	}
	Vector& Vector::operator*=(const Square& k)
	{
		for (int i = 0; i<n*m; i++)
		{
			Head[i] *= k;
		}
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
	}
}
