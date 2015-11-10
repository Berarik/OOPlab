// Matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
using namespace OOPLabs;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Лабораторная работа №2" << endl;
	Square Sq[9];
	for (int i = 0; i < 9; i++)
	{
		Sq[i].setA(rand()%(i+1)+5);
		Sq[i].setcoorX(rand() % (i + 1)+8);
		Sq[i].setcoorY(rand() % (i + 1)+2);
	}
	try
	{
		matrix M(3, 4, Sq, 5);
				//	const matrix tt(3, 3);
				//	tt.searchmaxSquareSize().setA(5);
				//	cout << M<<tt;
		matrix Lab2(2, 3);
		cout << Lab2;
		Lab2 = Lab2;
			//cout << "Max elem" << Lab2.searchmaxSquareSize() << "\nMin elem" << Lab2.searchmaxSquareSize() << endl;
		matrix Lab2_1(2, 3, Sq, 5);
		cout << Lab2_1 << endl;
			// matrix lab2_9(Lab2*Lab2_1);//Ошибка умножения
		matrix Lab2_8(Lab2_1);
		cout << Lab2_8 << endl;
		cout << Lab2 + Lab2_1;
		cout << Lab2_1 << endl;
		Lab2 = Lab2_1;
		cout << Lab2 << endl;
		cout << Lab2_1 << endl;
		matrix Lab2_3 = Lab2;
		Lab2 *= 3;
		cout << Lab2 << endl;
		cout << Lab2_3 << endl;
		Lab2_3 += Lab2;
		cout << Lab2_3 << endl;
		Lab2_3 -= Lab2;
		cout << Lab2_3 << endl;
		matrix Lab2_2(3, 3, Sq, 2);
		cout << Lab2_2 << endl;
			//Lab2_3-=Lab2_2;/*Ошибка сложения/вычитания */
		cout << Lab2_3 << endl;
		matrix Lab2_4(2, 3), Lab2_5(3, 2);
		Lab2_4.init(Sq, 6);
		Lab2_5.init(Sq, 4);
			////for (int i = 0; i<2; i++)
		////{
		////	for (int j = 0; j<3; j++)
		////	{
		////		Lab2_4[i][j] = rand() % 17;
		////		Lab2_5[j][i] = rand() % 22;
		////	}
		////}
		cout << Lab2_4 << endl << Lab2_5 << endl;
		Lab2_4=Lab2_5;
			//cout << Lab2_4 << "\nMax elem " << Lab2_4.searchmaxelem() << endl << Lab2_5 << "\nMax elem " << Lab2_5.searchmaxelem() << endl;
		matrix Lab2_6(3, Sq, 3);
		cout << Lab2_6 << endl;
			//Lab2_4*=Lab2_5;/*Ошибка умножения*/
		cout << "setw(1)\n" << setw(1) << Lab2_4 << endl;
		matrix Lab2_7;
			//cout << Lab2_6 << endl;
		cout << Lab2_7;
		Lab2_7 = Lab2_6*Lab2_2;
		cout << "setw(7)\n" << setw(7) << Lab2_7;
		matrix Lab2_12(1, 1);
		cout << Lab2_12 * 4;
			//matrix Lab2_10(0,-10);/*Ошибка размера матрицы */
			//Lab2_12[-1][0];/*Ошибка индексирования*/
	}
	catch (Exception Err)
	{
		Err.GetException();
	}
	cout << "Завершение работы программы.\nНажмите любую клавишу для закрытия программы." << endl;
	cin.get();
	return 0;
}
