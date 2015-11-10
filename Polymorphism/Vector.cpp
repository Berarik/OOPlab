#include "stdafx.h"
#include "Vector.h"
using namespace std;

namespace OOPLabs 
{
	ostream& operator<<(ostream& os, const Vector& Vect)
	{
		setlocale(LC_ALL, "RUS");
		streamsize k = cout.width();
		if (k <= 0) k = 5;
		cout << "Вектор №" << Vect.ind;
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
		setlocale(LC_ALL, "RUS");
		ind = cnt++;
		if (m*n != Vec.m*Vec.n)
		{
			m = Vec.m;
			n = Vec.n;
			Head = new Square[m*n];
		}
		else
		{
			m = Vec.m;
			n = Vec.n;
		}
		for (int i = 0; i < m*n; i++)  Head[i] = Vec.Head[i];
	}
//
//	//int vect::cnt = 1;
//	//using namespace std;
//	//vect::vect(double a, double b, double c)
//	//{
//	//	ind = cnt++;
//	//	cout << "\t\tКонструктор №" << ind << endl;
//	//	x = a;
//	//	y = b;
//	//	z = c;
//	//}
//	//vect::~vect()                                                                                                                                                           //    vect::vect()//    {//        x=y=z=0;//        ind=cnt++;//        cout <<"Конструктор №"<<ind<<endl;////    }
//	//{
//	//	cout << "\t\tДеструктор №" << ind << endl;
//	//}
//	//double vect::readx()    const
//	//{
//	//	return x;
//	//}
//	//double vect::ready()    const
//	//{
//	//	return y;
//	//}
//	//double vect::readz()    const
//	//{
//	//	return z;
//	//}
//	//void vect::writex(double a)
//	//{
//	//	x = a;
//	//}
//	//void vect::writey(double a)
//	//{
//	//	y = a;
//	//}
//	//void vect::writez(double a)
//	//{
//	//	z = a;
//	//}
//	//void vect::coutcoor() const
//	//{
//	//	cout << "\tКоординаты конца вектора: " << endl << " X : " << x << " Y : " << y << " Z : " << z << endl;
//	//}
//
//	//void vect::mlpt(double a)
//	//{
//	//	x *= a;
//	//	y *= a;
//	//	z *= a;
//	//}
//
//	//double vect::modul() const
//	//{
//	//	return sqrt(x*x + y*y + z*z);
//	//}
//
//	//double smlpt(const vect& a, const vect& b)
//	//{
//	//	return a.readx()*b.readx() + a.ready()*b.ready() + a.readz()*b.readz();
//	//}
//
//	//bool vect::norm()
//	//{
//	//	if (modul())
//	//	{
//	//		double s = modul();
//	//		x /= s;
//	//		y /= s;
//	//		z /= s;
//	//		return 1;
//	//	}
//	//	else return 0;
//	//}
//
//	//void vect::cpvect(const vect& a)
//	//{
//	//	x = a.x;
//	//	y = a.y;
//	//	z = a.z;
//	//}
//
//	//vect sum(const vect &a, const vect &b)
//	//{
//	//	return vect(a.readx() + b.readx(), a.ready() + b.ready(), a.readz() + b.readz());
//	//}
//
//	//vect sub(const vect &a, const vect &b)
//	//{
//	//	return vect(a.readx() - b.readx(), a.ready() - b.ready(), a.readz() - b.readz());
//	//}
//
//	//vect vmlpt(const vect &a, const vect &b)
//	//{
//	//	return vect(((a.ready()*b.readz()) - (a.readz()*b.ready())),
//	//		((a.readz()*b.readx()) - (a.readx()*b.readz())),
//	//		((a.readx()*b.ready()) - (a.ready()*b.readx())));
//	//}
//
//	//double cosvect(const vect& a, const vect& b)
//	//{
//	//	return smlpt(a, b) / (a.modul()*b.modul());
//	//}
//
//	//double sinvect(const vect& a, const vect& b)
//	//{
//	//	return vmlpt(a, b).modul() / (a.modul()*b.modul());
//	//}
//
//	//double anglevect(const vect& a, const vect& b)
//	//{
//	//	return atan2(sinvect(a, b), cosvect(a, b)) * 180 / M_PI;
//	//}
}
