#include "stdafx.h"
#include "Exception.h"
using namespace std;
char EC1[] = "������������ ������ ������� � ";
char EC2[] = "������������ ������ ������� � ";
char EC3[] = "���������� ����� ������������/����������� ������� � ������� � ";
char EC4[] = "���������� �������/������� ������� � ";
char EC41[] = " � ������� � ";
char EC5[] = "���������� �������� ������� � ";
char EC51[] = " �� ������� � ";
char EC6[] = "���������� �������� ������ � ";
char EC61[] = " �� ������ � ";
char EC7[] = "���������� �������/������� ������ � ";
char EC71[] = " � ������ � ";
char EC11[] = "���������� ����������� ������� � ";
char EC111[] = " �� ������� � ";
char EC9[] = "������������ ������ ������� � ";

Exception::Exception(int ErrorNumb, int M1, int M2)
{
	o1 = M1;
	o2 = M2;
	ExceptionNumber = ErrorNumb;
}
void Exception::GetException()
{
	switch (ExceptionNumber)
	{
	case 1:
		cout << EC1 << o1 << endl;
		break;
	case 2:
		cout << EC2 << o1 << endl;
		break;
	case 3:
		cout << EC3 << o1 << endl;
		break;
	case 4:
		cout << EC4 << o1 << EC41 << o2 << endl;
		break;
	case 5:
		cout << EC5 << o1 << EC51 << o2 << endl;
		break;
	case 6:
		cout << EC6 << o1 << EC6 << o2 << endl;
		break;
	case 7:
		cout << EC7 << o1 << EC71 << o2 << endl;
		break;
	case 8:
		cout << EC4 << o1 << EC71 << o2 << endl;
		break;
	case 9:
		cout << EC9 << o1 << endl;
		break;
	case 10:
		cout << EC5 << o1 << EC61 <<o2<<endl;
		break;
	case 11:
		cout << EC11 << o1 << EC51 << o2 << endl;
		break;
	}
}