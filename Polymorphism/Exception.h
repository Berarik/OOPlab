#pragma once
#include "stdafx.h"

class Exception
{
private:
	int ExceptionNumber, o1, o2;
public:
	Exception(int = -1, int = -1, int = -1);
	void GetException();
};
/*
Номер   Описание
1       Некорректный размер Матрицы
2       Некорректный индекс Матрицы
3       Невозможно найти макимальный/минимальный элемент
4       Невозможно сложить/вычесть матрицу № и матрицу №
5       Невозможно умножить матрицу № на матрицу №
*/