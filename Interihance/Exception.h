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
�����   ��������
1       ������������ ������ �������
2       ������������ ������ �������
3       ���������� ����� �����������/����������� �������
4       ���������� �������/������� ������� � � ������� �
5       ���������� �������� ������� � �� ������� �
*/