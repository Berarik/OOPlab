#include "stdafx.h"
#include "Matrix.h"
using namespace std;

namespace OOPLabs
{

	int Matrix::cnt = 0;
	//char EC0[]="Невозможно инициализировать Матрицу № ";
		Matrix::Matrix(int h, int w, double* intHead, int k)
		{
			setlocale(LC_ALL, "RUS");
			ind = cnt++;
			//cout << "Конструктор №" << ind << endl;
			if (w >= 0 && h >= 0)
			{
				if (h&&w)
				{
					m = h;
					n = w;
					Head = new double[m*n];
					if (k != 0)
					{
						if (intHead)
						{
							for (int i = 0; i < k; i++)       Head[i] = intHead[i];
							for (int i = k; i < m*n; i++)     Head[i] = 0;
						}
					}
					else
					{
						for (int i = 0; i < m*n; i++)    Head[i] = 0;
					}
				}
				else
				{
					m = n = 0;
					Head = NULL;
				}
			}
			else throw Exception(1, ind);
		}
		Matrix::Matrix(int w, double* intHead, int k)
		{
			setlocale(LC_ALL, "RUS");
			ind = cnt++;
			//cout << "Конструктор №" << ind << endl;
			if (w >= 0)
			{
				m = n = w;
				Head = new double[m*n];
				if (k != 0)
				{
					if (intHead)
					{
						for (int i = 0; i < k; i++)       Head[i] = intHead[i];
						for (int i = k; i < m*n; i++)     Head[i] = 0;
					}
				}
				else
				{
					for (int i = 0; i < m*n; i++)    Head[i] = 0;
				}
			}
			else throw Exception(1, ind);
		}
		Matrix::Matrix(const Matrix& mtr)
		{
			setlocale(LC_ALL, "RUS");
			ind = cnt++;
			/*cout << "Конструктор №" << ind << endl;*/
			if (m*n != mtr.m*mtr.n)
			{
				m = mtr.m;
				n = mtr.n;
				Head = new double[m*n];
			}
			else
			{
				m = mtr.m;
				n = mtr.n;
			}
			for (int i = 0; i < m*n; i++)  Head[i] = mtr.Head[i];  //        else throw Exception(1,ind,mtr.ind);
		}
		Matrix::~Matrix()
		{
			setlocale(LC_ALL, "RUS");
			//cout << "Деструктор №" << ind << endl;
			delete[]Head;
		}
		bool Matrix::oprtmlpt(const Matrix &B)
		{
			return (m == B.n);
		}
		bool Matrix::oprtsum(const Matrix &B)
		{
			return (n == B.n&&m == B.m);
		}
		int Matrix::Width() const
		{
			return n;
		}
		int Matrix::Height() const
		{
			return m;
		}
		Matrix& Matrix::operator=(const Matrix& mtr)
		{
			if (this == &mtr)
			{
				return *this;
			}
			if (m*n != mtr.m*mtr.n)
			{
				m = mtr.m;
				n = mtr.n;
				Head = new double[m*n];
			}
			else
			{
				m = mtr.m;
				n = mtr.n;
			}
			for (int i = 0; i < m*n; i++)  Head[i] = mtr.Head[i];
			return *this;
		}
		Matrix& Matrix::operator+=(const Matrix& mtr)
		{
			if (oprtsum(mtr))
			{
				for (int i = 0; i < m*n; i++)  Head[i] += mtr.Head[i];
			}
			else throw Exception(4, ind, mtr.ind);
			return *this;
		}
		Matrix& Matrix::operator-=(const Matrix& mtr)
		{

			if (oprtsum(mtr))
			{
				for (int i = 0; i < m*n; i++)  Head[i] -= mtr.Head[i];                                                                               //            this->operator+=(mtr);//            mtr*=-1.0;
			}
			else throw Exception(4, ind, mtr.ind);
			return *this;
		}
		Matrix& Matrix::operator*=(const Matrix& mtr)
		{
			if (oprtmlpt(mtr))
			{
				Matrix tmp(n, mtr.m);
				for (int i = 0; i < n; i++)
					for (int j = 0; j < mtr.m; j++)
						for (int k = 0; k < m; k++)
						{
							tmp.Head[j + i*(mtr.m)] += Head[k + i*m] * mtr.Head[j + k*(mtr.m)];
						}
						return operator=(tmp);
			}
			else throw Exception(5, ind, mtr.ind);
			return *this;
		}
		Matrix& Matrix::operator*=(double k)
		{
			if (k == 1) { return *this; }
			for (int i = 0; i < n*m; i++)
			{
				Head[i] *= k;
			}
			return *this;
		}
		const double* Matrix::operator[](int i) const
		{
			if (i < 0 || i >= n) throw Exception(2, ind);
			return &Head[i*m];
		}
		double* Matrix::operator[](int i)
		{
			if (i < 0 || i >= n) throw Exception(2, ind);
			return &Head[i*m];
		}
		ostream& operator<<(ostream& os, const Matrix& mtr)
		{
			setlocale(LC_ALL, "RUS");
			streamsize k = cout.width();
			if (k <= 0) k = 5;
			cout << "Матрица №" << mtr.ind;
			if (mtr.m*mtr.n)
			{
				cout << endl;
				for (int i = 0; i < mtr.n; i++)
				{
					for (int j = 0; j < mtr.m; j++)
					{
						cout.width(k);
						os << mtr[i][j];
					}
					cout << endl;
				}
			}
			else cout << " пустая" << endl;
			return os;
		}
		Matrix& operator+(const Matrix& l, const Matrix& r)
		{
			Matrix mtr(l);
			return mtr += r;
		}
		Matrix& operator-(const Matrix& l, const Matrix& r)
		{
			Matrix mtr(l);
			return mtr -= r;
		}
		Matrix& operator*(const Matrix& l, const Matrix& r)
		{
			Matrix mtr = l;
			return mtr *= r;
		}
		Matrix& operator*(const Matrix& l, double k)
		{
			Matrix mtr(l);
			return mtr *= k;
		}
		ostream& operator<<(ostream& os, const Vector& Vect)
		{
			setlocale(LC_ALL, "RUS");
			streamsize k = cout.width();
			if (k <= 0) k = 5;
			cout << "Вектор №" <<Vect.ind;
			if (Vect.m*Vect.n)
			{
				cout << endl;
				for (int i = 0; i < Vect.n; i++)
				{
					for (int j = 0; j < Vect.m; j++)
					{
						cout.width(k);
						os << Vect[i][j];
					}
					cout << endl;
				}
			}
			else cout << " пустая" << endl;
			return os;
		}
		bool Vector::oprtmlpt(const Vector& Vec, const Matrix& Mtr)
		{
			return (Vec.m == Mtr.Width()) ;
		}
		bool Vector::oprtmlpt(const Matrix& Mtr, const Vector& Vec)
		{
			return (Mtr.Height() == Vec.n );
		}
		bool Vector::oprtmlpt(const Vector& Vec)
		{
			return (m == Vec.n );
		}
		bool Vector::oprtsum(const Vector& Vec,const Matrix& Mtr)
		{
			return ((Vec.n == Mtr.Width()&&Vec.m == Mtr.Height()) );
		}
		bool Vector::oprtsum(const Matrix& Mtr, const Vector& Vec)
		{
			return (Mtr.Width() == Vec.n&&Mtr.Height() == Vec.m);
		}
		bool Vector::oprtsum(const Vector& Vec)
		{
			return (n == Vec.n&&m == Vec.m);
		}
		Vector::Vector(Vector& Vec)
		{
			setlocale(LC_ALL, "RUS");
			ind = cnt++;
			/*cout << "Конструктор №" << ind << endl;*/
			if (m*n != Vec.m*Vec.n)
			{
				m = Vec.m;
				n = Vec.n;
				Head = new double[m*n];
			}
			else
			{
				m = Vec.m;
				n = Vec.n;
			}
			for (int i = 0; i < m*n; i++)  Head[i] = Vec.Head[i];
		}
		/*Vector::Vector(Vector& vec)
		{

		}*/
		//Vector& Vector::operator=(const Vector&)
		//{
		//	
		//}
}