#include "stdafx.h"

using namespace std;

namespace OOPLabs 
{
	void Vector::init(int h, const Square* inHead, int k)
	{
		if (h>0)
		{
			m = h;
			Head = new Square[m*n];
			int i = 0;
			if (k != 0)
			{
				if (inHead)
				{
					for (; i<k; i++)       Head[i] = inHead[i];
				}
			}
			for (; i<m*n; i++)    Head[i] = 0;
		}
		else
		{
			m = 0;
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
		for (; i<m*n; i++)    Head[i] = 0;
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
				for (int j = 0; j < Vect.m; j++)
				{
					if (k > 0) cout.width(k);
					cout << Vect[i][j];
					if (k <= 0) cout << " ";
				}
				cout << endl;
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
	Vector::Vector(Vector& Vec)
	{
		init(Vec.m,Vec.Head,Vec.m);
	}
}
