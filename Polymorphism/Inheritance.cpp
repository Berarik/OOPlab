// Polymorphism.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Inheritance.h"


using namespace OOPLabs;
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	const int k = 3;
	//double x[k] = { 3,4.9,7 };
	try
	{
		Square Sq[9];
		for (int i = 0; i < 9; i++)
		{
			Sq[i].setA(rand() % (i + 1) + 5);
			Sq[i].setcoorX(rand() % (i + 1) + 8);
			Sq[i].setcoorY(rand() % (i + 1) + 2);
		}
		int mjj = 3;
		/*matrix M1(3, 3, Sq, 3);
		cout << M1 << endl;
		matrix M2(3, 2, (Sq + 4), 3);
		cout << M2 << endl;
		matrix M3(1, 1, Sq, 1);
		cout << M3 << endl;
		Vector V1(3, Sq, k);
		cout << V1 << endl;
		Vector v2(V1);
		cout << v2 << endl;
		M1.oprtmlpt(V1);
		V1.oprtmlpt(M1);
		V1 *= Sq[1];
		cout << V1 << endl;
		V1 = v2;
		cout << V1 << endl;
		V1 = M3;
		cout << V1 << endl;
		V1*=M3;
		v2 *= v2;*/
		matrix m(1, 3, Sq, 3), l(3, 1, &Sq[2],3);
		Vector v(3, &Sq[4], 3);
		v.oprtmlpt(m);
		m.oprtmlpt(v);
		l = l*m;
		//cout <<l;
		//cout << m*v;
		//cout << v << m;
		//if (M1.oprtmlpt(M2))
		//{
		//	M1 *= M2;
		//	cout <<"M1 *= M2;"<< M1;
		//}
		//if (M1.oprtsum(M2))
		//{
		//	M1 += M2;
		//	cout <<"M1 += M2;"<< M1;
		//}
		//	cout << "TRUE" << endl;
		//	cout << V1 << "	V1 *= Sq[1];" << endl;
		//	V1 *= Sq[1];
		//	cout << V1 << endl;
		//	//cout << "Матрица\n" << M1;
		//	//cout << "TRUE" << endl;
		//if (V1.oprtmlpt(V1))
		//{
		//	cout << "TRUE" << endl;
		//	V1 *= V1;
		//	cout << "V1 *= V1;\n" << V1 << endl;
		//}
		//if (V1.oprtsum(V1))
		//{
		//	cout << "TRUE" << endl;
		//	V1 += V1;
		//	cout << "V1 += V1;\n" << V1 << endl;
		//}
		//if (V1.oprtsum(V1))
		//{
		//	cout << "TRUE" << endl;
		//	V1 -= V1;
		//	cout << "V1 -= V1;" << V1 << endl;
		//}
		//if (V1.oprtsum(V1))
		//{
		//	cout << "TRUE" << endl;
		//	V1 = (V1 + V1);
		//	cout << "V1 = (V1 + V1);" << V1 << endl;
		//}
		//if (V1.oprtsum(V1))
		//{
		//	cout << "TRUE" << endl;
		//	V1[1] += v2[3];
		//	cout << "V1[1] += v2[3];" << "V1" << V1 << "v2" << v2 << endl;
		//	cout << "v1[1]" << V1[1] << "v2[3]" << v2[3] << endl;
		//}
		//if (V1.oprtsum(M1))
		//{
		//	cout << "TRUE" << endl;
		//	V1 += M1;
		//	cout << "V1 += M1;" << "V1" << V1 << "M1" << M1 << endl;
		//}
		//if (M1.oprtsum(V1))
		//{
		//	cout << "TRUE" << endl;
		//	M1 += V1;
		//	cout << "V1 += M1;" << "V1" << V1 << "M1" << M1 << endl;
		//}
		//cout << "V1.init(&(Sq[3]), 3);\nV1" << V1;
		//V1.init(&(Sq[3]), 3);
		//cout << "\n V1"<< V1<<endl;
		//Vector v3(1, Sq, 1), v4(1, Sq, 1);
		//matrix m3(1, Sq, 1), m4(1, Sq, 1);
		//cout << "\tвектторы\n" << v3 << v4 << endl;
		//cout << "\tМатрицы\n" << m3 << m4 << endl;
		////v3 = v3* m3;
		//cout << v3;
		//v3 *= m3;
		//cout << v3;
		//v4 *= v4;
		//cout << v4;
		//v4 = v4;
		//cout << "\tвектторы\n" << v3 << v4 << endl;
		//cout << "\tМатрицы\n" << m3 << m4 << endl;
		cout << "Завершение работы программы.\nНажмити любую кнопку для выхода." << endl;
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