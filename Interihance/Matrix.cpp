#include "stdafx.h"
#include "Matrix.h"
using namespace std;

namespace OOPLabs
{

	int matrix::cnt = 0;
	void matrix::init(int w, int h, const Square* inHead, int k)
	{
		if (h&&w)
		{
			m = h;
			n = w;
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
			m = n = 0;
			Head = 0;
		}
	}
	void matrix::init(const Square * inHead, int k)
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
	matrix::matrix(int w, int h, const Square* inHead, int k)
	{
		ind = cnt++;
		//cout << "Конструктор №" << ind << endl;
		if (w >= 0 && h >= 0)
		{
			init(w, h, inHead, k);
		}
		else throw Exception(1, ind);
	}
	matrix::matrix(int w, const Square* inHead, int k)
	{
		ind = cnt++;
		//cout << "Конструктор №" << ind << endl;
		if (w >= 0)
		{
			init(w, w, inHead, k);
		}
		else throw Exception(1, ind);
	}
	matrix::matrix(const matrix& mtr)
	{
		ind = cnt++;
		//cout << "Конструктор №" << ind << endl;
		init(mtr.n, mtr.m, mtr.Head, mtr.n*mtr.m);
	}
	matrix::~matrix()
	{
		//cout << "Деструктор №" << ind << endl;
		if (Head != NULL)
		{
			delete Head;
		}
	}
	bool matrix::oprtmlpt(const matrix &B)
		{
			return (m == B.n);
		}
	bool matrix::oprtsum(const matrix &B)
		{
			return (n == B.n&&m == B.m);
		}
	int matrix::Width() const
	{
		return n;
	}
	int matrix::Height() const
	{
		return m;
	}
	int matrix::Index() const
	{
		return ind;
	}
	matrix& matrix::operator=(const matrix& mtr)
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
	matrix& matrix::operator+=(const matrix& mtr)
	{
		if (oprtsum(mtr))
	{
		for (int i = 0; i<m*n; i++)  Head[i] += mtr.Head[i];
	}
	else throw Exception(4, ind, mtr.ind);
	return *this;
	}
	matrix& matrix::operator-=(const matrix& mtr)
	{
		if (oprtsum(mtr))
		{
			for (int i = 0; i < m*n; i++)  Head[i] -= mtr.Head[i];
		}
		else throw Exception(4, ind, mtr.ind);
		return *this;
	}
	matrix& matrix::operator*=(const matrix& mtr)
	{
		if (oprtmlpt(mtr))
		{
			matrix tmp(n, mtr.m);
			for (int i = 0; i<n; i++)
				for (int j = 0; j<mtr.m; j++)
					for (int k = 0; k<m; k++)
					{
						tmp.Head[j + i*(mtr.m)] += Head[k + i*m] * mtr.Head[j + k*(mtr.m)];
					}
			return (*this).operator=(tmp);
		}
		else throw Exception(5, ind, mtr.ind);
		return *this;
	}
	matrix& matrix::operator*=(const Square& k)
	{
		for (int i = 0; i<n*m; i++)
		{
			Head[i] *= k;
		}
		return *this;
	}
	const Square* matrix::operator[](int i) const
	{
		if (i < 0 || i >= n) throw Exception(2, ind);
		return &Head[i*m];
	}
	Square* matrix::operator[](int i)
	{
		if (i < 0 || i >= n) throw Exception(2, ind);
		return &Head[i*m];
	}
	matrix matrix::transpon() const
	{
		matrix tmp(Height(), Width());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp.Head[i + j*m] = Head[j + i*m];
		return tmp;
	}
	ostream& operator<<(ostream& os, const matrix& mtr)
	{
		streamsize k = cout.width();
		//cout << "Матрица №" << mtr.ind;
		if (mtr.m*mtr.n)
		{
			cout << endl;
			for (int i = 0; i<mtr.n; i++)
			{
				for (int j = 0; j<mtr.m; j++)
				{
					if (k>0) cout.width(k);
					cout << mtr[i][j];
					if (k <= 0) cout << " ";
				}
				cout << endl;
			}
		}
		else cout << " пустая" << endl;
		return os;
	}
	matrix operator+(const matrix& l, const matrix& r)
	{
		matrix mtr = l;
		return mtr += r;
	}
	matrix operator-(const matrix& l, const matrix& r)
	{
		matrix mtr = l;
		return mtr -= r;
	}
	matrix operator*(const matrix& l, const matrix& r)
	{
		matrix mtr = l;
		return mtr *= r;
	}
	matrix operator*(const matrix& l, const Square& k)
	{
		matrix mtr = l;
		return mtr *= k;
	}
}