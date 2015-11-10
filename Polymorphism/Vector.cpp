#include "stdafx.h"
//#include "Vector.h"
//#include "Matrix.h"
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//namespace OOPLab {
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
//}
