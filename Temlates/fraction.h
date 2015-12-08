#pragma once
#include "stdafx.h"


namespace OOPLabs {
	template <class T>
	class fraction
	{
	private:
		T Numerator;//„ислитель
		T Denominator;//«наменатель
		T Remainder;//ќтстаток
		T Int = 0;
		T Result = 0;
	public:
		fraction<T>()
		{
			Numerator = 0;
			Denominator = 0;
		};
		fraction<T>(const fraction<T>& R)
		{
			if (R.Denominator)
			{
				Denominator = R.Denominator;
				Numerator = R.Numerator;
			}
			else throw Exception(15);
		}
		fraction<T>(T Nm, T Dn)
		{
			Numerator = Nm;
			Denominator = Dn;
		};
		fraction<T>& operator+=(const fraction<T>& R)
		{
			if (Denominator == R.Denominator)
			{
				Numerator += R.Numerator;
			}
			else
			{
				int templ = Numerator*R.Denominator, tempr = R.Numerator*Denominator;
				Numerator = templ + tempr;
				Denominator *= R.Denominator;

			}
			return *this;
		};
		fraction<T>& operator*=(const fraction<T>& R)
		{
			Numerator *= R.Numerator;
			if (R.Denominator)
				Denominator *= R.Denominator;
			else throw Exception(14);
		};
		fraction<T>& operator-=(const fraction<T>& R)
		{
			if (Denominator == R.Denominator)
			{
				Numerator -= R.Numerator;
			}
			else
			{
				int templ = Numerator*R.Denominator, tempr = R.Numerator*Denominator;
				Numerator = templ - tempr;
				Denominator *= R.Denominator;

			}
			return *this;
		};
		fraction<T>& operator/=(const fraction<T>& R)
		{
			Numerator *=R.Denominator;
			if (R.Numerator)
				Denominator *= R.Numerator;
			else throw Exception(14);
		};
		friend std::ostream& operator<<(std::ostream& os, const fraction<T>& Fr)
		{
			streamsize k = cout.width();
			cout << "\nƒробь:\n";
			if (Fr.Numerator!=0)
				cout << "\t" << Fr.Numerator << "\n";
			if (Fr.Int != 0)
				cout << Fr.Int;
			if (Fr.Numerator != 0)
				cout << "\t-------------------\n\t" << Fr.Denominator;
			cout << endl;
			return os;
		};
		void reducing() 
		{
			int n = Numerator;
			int d = Denominator;

			int nabs = n > 0 ? n : -n;
			int dabs = d > 0 ? d : -d;
			int min = nabs > dabs ? dabs : nabs;
			for (int divider = 2; divider <= min / 2 || divider == 2; ++divider)
				while ((n % divider == 0) && (d % divider == 0)) {
					n /= divider;
					d /= divider;
				}
			Numerator = n;
			Denominator = d;
		};
		void Alc()
		{
			if (Numerator > Denominator)
			{
				Int += Numerator / Denominator;
				Numerator %= Denominator;
			}
			};
	};
	template <class T>
	fraction<T>& operator/(const fraction<T>&, const fraction<T>&)
	{
		fraction<T> Fr(L);
		return Fr /= R;
	};
	template <class T>
	fraction<T>& operator*(const fraction<T>& L, const fraction<T>& R)
	{
		fraction<T> Fr(L);	
		return Fr *= R;
	};
	template <class T>
	fraction<T>& operator-(const fraction<T>&, const fraction<T>&)
	{
		fraction<T> Fr(L);	
		return Fr *= R;
	};
	template <class T>
	fraction<T>& operator+(const fraction<T>&, const fraction<T>&)
	{
		fraction<T> Fr(L);
		return Fr *= R;
	};
};

/*
а)	ќбеспечить выполнение 4-х арифметических действий над этими объектами (+=,	+, Ц=, Ц, *=, *, /=, /);
б)	ѕредусмотреть операцию автоматического Ђсокращени€ дробиї Ц удалени€
общих множителей числител€ и знаменател€;
в)	ќбеспечить операцию декомпозиции неправильной дроби на целую часть и 	правильную дробь, использу€ операцию делени€ с остатком.
*/
