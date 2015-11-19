// Polymorphism.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Inheritance.h"


using namespace OOPLabs;
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Square Sq[9];
		for (int i = 0; i < 9; i++)
		{
			Sq[i].setA(rand() % (i + 1) + 5);
			Sq[i].setcoorX(rand() % (i + 1) + 8);
			Sq[i].setcoorY(rand() % (i + 1) + 2);
		}
		matrix M1(3, 3, Sq, 3), M2(3, 2, (Sq + 4), 3), M3(1, 1, Sq, 1);
		cout << M1 << endl;
		cout << M1.transpon();
		cout << M2 << endl;
		cout << M3 << endl;
		Vector v1(3, Sq, k), v2(v1);
		cout << v1 << endl << v2 << endl;
		cout<<M1.oprtmlpt(v1)<<endl<<v1.oprtmlpt(M1)<<endl;
		if (v1.oprtmlpt(v1))
		{
			cout << "V1" << v1 << endl;
			cout << "v1*v1" << v1*v1 << endl;
		}
		if (v1.oprtsum(v1))
		{
			cout << "V1" << v1 << endl;
			cout << "v1+v1" << v1 + v1 << endl;
		}
		if (v1.oprtsum(v1))
		{
			cout << "true v1[1]" << v1 << "v2[2]" << v1 << endl;
			v1[1] += v2[2];
			cout << "v1[1] += v2[3];" << "v1" << v1 << "v2" << v2 << endl;
			cout << "v1[1]" << v1[1] << "v2[3]" << v2[1] << endl;
		}
		v1 *= Sq[1];
		cout << v1 << endl;
		v1 = v2;
		cout << "v1"<< v1 << endl;
		v1 = M3;
		cout <<"m3"<< M3 << endl;
		cout <<"v1 = M3;"<< v1 << endl;
		//v1*=M3;
		//v2 *= v2;
//		matrix m(1, 3, Sq, 3), l(3, 1, &Sq[2],3);
//		Vector v(3, &Sq[4], 3);
//		v.oprtmlpt(m);
//		m.oprtmlpt(v);
////		l*=m;
//		cout <<l*m;
//		cout << m*v;
//		cout << v << m;
		if (M1.oprtmlpt(M2))
		{
			cout << "M1 "<< M1 << "M2"<<M2 << endl;
			M1 *= M2;
			cout <<"M1 *= M2;"<< M1;
		}
		if (M1.oprtsum(M2))
		{
			cout << "M1 " << M1 << "M2" << M2 << endl;
			M1 += M2;
			cout <<"M1 += M2;"<< M1;
		}
			cout << "TRUE" << endl;
			cout <<"v1"<< v1 << "Sq[1]"<<Sq[1]<<"\nV1 *= Sq[1];" << endl;
			v1 *= Sq[1];
			cout << v1 << endl;
		if (v1.oprtmlpt(v1))
		{
			cout << "true" << endl;
			v1 *= v1;
			cout << "v1 *= v1;\n" << v1 << endl;
		}
		if (v1.oprtsum(v1))
		{
			cout << "true v1" << v1 <<"v2"<< v1 <<endl;
			v1 += v1;
			cout << "v1 += v1;\n" << v1 << endl;
		}
		if (v1.oprtsum(v2))
		{
			cout << "true v1" << v1 << "v2" << v1 << endl;
			v1 -= v2;
			cout << "v1 -= v2;" << v1 << endl;
		}
		if (v1.oprtsum(v1))
		{
			cout << "true v1" << v1 <<"v2"<< v1 <<endl;
			v1 = (v1 + v1);
			cout << "v1 = (v1 + v1);" << v1 << endl;
		}
	
		/*if (v1.oprtsum(M1))
		{
			cout << "true v1" << v1 << "m1" << M1 << endl;
			v1 += M1;
			cout << "v1 += m1;" << "v1" << v1 << "m1" << M1 << endl;
		}*/
		if (M1.oprtsum(v1))
		{
			cout << "true v1" << v1 << "m1" << M1 << endl;
			M1 += v1;
			cout << "V1 += M1;" << "V1" << v1 << "M1" << M1 << endl;
		}
		cout << "V1" << v1<<endl;
		v1.init(&(Sq[3]), 3);
		cout << "v1.init(&(sq[3]), 3);\nv1"<< v1<<endl;
		cout << "Завершение работы программы.\nНажмите любую кнопку для выхода." << endl;
	}
	catch (Exception Err)
	{
		Err.GetException();
	}
	cin.get();
	return 0;
}



//1. Конструкторы(по умолчанию+, с параметрами+, копирующий+);+
//2. Проверка возможности сложения и умножения объектов(вектора и вектора+, вектора и матрицы+, матрицы и вектора+, матрицы и матрицы+);+
//3. Оператор доступа к элементам вектора и матрицы[];+
//4. Оператор вывода в поток <<;+
//5. Математические операторы(+, –, *, +=, –=, *=, =) с объектами, а также умножение объектов на скаляр;