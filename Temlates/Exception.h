#pragma once
#include "stdafx.h"

namespace OOPLabs
{
	class Exception
	{
	private:
		int ExceptionNumber, m1, m2;
	public:
		Exception(int = -1, int = -1, int = -1);
		void GetException();
		/*
		�����   ��������
		1       ������������ ������ �������
		2       ������������ ������ �������
		3       ���������� ����� �����������/����������� �������
		4       ���������� �������/������� ������� � � ������� �
		5       ���������� �������� ������� � �� ������� �
		*/
	};
}