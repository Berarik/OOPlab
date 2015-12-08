#include "polynomial.h"
namespace OOPLabs
{
	polynomial::polynomial(double* coeffs, int N)
	{
		if (!N)
		{
			coeff = NULL;
			n = 0;
		}
		else
		{
			coeff = new double[N];
			n = N;
			for (int i = 0; i < N; i++)
				coeff[i] = coeffs[i];
		}
	
	}
	polynomial::polynomial(double coeffs, int N)
	{
		if (!N)
		{
			coeff = NULL;
			n = 0;
		}
		else
		{
			coeff = new double[N] {0};
			n = N;
				coeff[n-1] = coeffs;
		}

	}
	polynomial::polynomial(const polynomial & R)
	{
		n = R.n;
		if (n)
		{
			coeff = new double[n];
			for (int i = 0; i < n; i++)
			{
				coeff[i] = R.coeff[i];
			}
		}
		else 
		{
			coeff = NULL;
		}
	}
	polynomial& polynomial::operator=(const polynomial& R)
	{
		if (this == &R)
		{
			return *this;
		}
		if (n!=R.n)
		{
			if (n)
				delete[]coeff;
			n = R.n;
			if(n)
				coeff = new double[n];
			else coeff = NULL;
		}
		for (int i = 0; i < n; i++)
			coeff[i] = R.coeff[i];
		return *this;
	};
	polynomial& polynomial::operator*=(const polynomial& R)
	{
		polynomial temp;
		temp.n = n + R.n-1;
		temp.coeff = new double[temp.n ]{0};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < R.n; j++)
			{
				temp.coeff[i + j] += coeff[i] * R.coeff[j];
			}
		}
		return operator=(temp);
	}
	polynomial & polynomial::operator*=(double d)
	{
		for (int i = 0; i < n; i++)
		{
			coeff[i] *= d;
		}
		return *this;
	}
	polynomial & polynomial::operator/=(const polynomial & R)
	{
		Update();
		polynomial temp(*this), temp2, temp3, temp4;
		if (n >= R.n)
		{
			int nrn = n - R.n;
			temp2.n = nrn + 1;
			temp2.coeff = new double[nrn + 1]{ 0 };
			//cout << "\ntemp" << temp << "\ntemp2" << temp2;
			for (int i = 1; i <= nrn + 1; i++)
			{
				temp2.coeff[nrn + 1 - i] = temp.coeff[n - i] / R.coeff[R.n - 1];
				temp3 = R;
				temp4 = polynomial(temp2.coeff[nrn + 1 - i], nrn + 2 - i);
				temp3 *= temp4;
				temp -= temp3;
				//cout << "\ntemp" << temp << "\ntemp2" << temp2 << "\ntemp3" << temp3 << "\ntemp4" << temp4;
			}
		}
		else throw Exception(12);
		temp2.Update();
		return operator=(temp2);
	}
	polynomial & polynomial::operator%=(const polynomial & R)
	{
		Update();
		polynomial temp(*this), temp2,temp3, temp4;
		if (n >= R.n)
		{
			int nrn = n - R.n;
			temp2.n = nrn + 1;
			temp2.coeff = new double[nrn + 1]{0};
			//cout << "\ntemp" << temp << "\ntemp2" << temp2;
			for (int i = 1; i <= nrn + 1; i++)
			{
				temp2.coeff[nrn + 1 - i] = temp.coeff[n - i] / R.coeff[R.n-1];
				temp3 = R;
				temp4 = polynomial(temp2.coeff[nrn + 1 - i], nrn + 2 - i);
				temp3 *= temp4;
				temp -= temp3;
				//cout <<"\ntemp"<< temp << "\ntemp2" << temp2<< "\ntemp3" << temp3<< "\ntemp4" << temp4;
			}
		}
		else throw Exception(12);
		temp.Update();
		return operator=(temp);
	}
	polynomial& polynomial::operator-=(const polynomial& R)
	{
		if (n >= R.n)
		{
			for (int i = 0; i < R.n; i++)
			{
				coeff[i] -= R.coeff[i];
			}
		}
		else
		{
			const int k = R.n;
			double *cf = new double[k] {0};
			int i;
			for (i = 0; i < n; i++)
			{
				cf[i] = coeff[i] - R.coeff[i];
			}
			for (; i < R.n; i++)
			{
				cf[i] = -R.coeff[i];
			}
			delete[]coeff;
			n = R.n;
			coeff = new double[n] {0};
			for (i = 0; i < R.n; i++)
			{
				coeff[i] = cf[i];
			}
		}
		return *this;
	}
	double polynomial::operator()(double x) const
	{
		double res=0;
		for (int i = 0; i < n; i++)
		{
			res += coeff[i]*pow(x, i);
		}
		return res;
	}
	void polynomial::Update()
	{
		for (int i = n-1; i > 0; i--)
		{
			if (!coeff[i])	n = i;
			else break;
		}
	}
	;
	polynomial& polynomial::operator+=(const polynomial& R)
	{
		if (n >= R.n)
		{
			for (int i = 0; i < R.n; i++)
			{
				coeff[i] += R.coeff[i];
			}
		}
		else
		{
			const int k = R.n+1;
			double *cf = new double[k] {0};
			int i = 0;
			for (; i < n; i++)
			{
				cf[i] = coeff[i]+ R.coeff[i];
			}
			for (; i < R.n; i++)
			{
				cf[i] = R.coeff[i];
			}
			delete[]coeff;
			n = R.n+1;
			coeff = new double[n] {0};
			for ( i = 0; i < R.n; i++)
			{
				coeff[i] = cf[i];
			}
		}
		return *this;
	};
	int polynomial::Power()
	{
		return n;
	};
	ostream& operator<<(ostream& os, const polynomial& P)
	{
		streamsize k = cout.width();
		//cout << "\nПолином:";
		if (P.n)
		{
			//cout<< "\nСтепень "<<P.n-1<<endl;
			bool f = false;
			for (int i = P.n-1; i>=0; i--)
			{
					if (P.coeff[i])
					{
						//if (k > 0) cout.width(k);
						if (!f)
						{
							f = true;
							cout << P.coeff[i];
							if(i)
								cout << "x^" << i;
						}
						else
						{
							if (P.coeff[i] > 0)
								cout << "+";
							cout << P.coeff[i]; 
							if (i) 
								cout << "x^" << i;
							//if (k <= 0) cout << " ";

						}	
					}
				}
				//cout << endl;
		}
		//else cout << " пустой" << endl;
		return os;
	}
	polynomial operator*(const polynomial& L,const polynomial &R)
	{
		polynomial pol(L);
		return pol *= R;
	}
	polynomial operator/(const polynomial& L, const polynomial &R)
	{
		polynomial pol(L);
		return pol /= R;
	}
	polynomial operator%(const polynomial& L, const polynomial &R)
	{
		polynomial pol(L);
		return pol %= R;
	}
	polynomial operator*(const polynomial & L, double d)
	{
		polynomial pol(L);
		return pol *= d;
	}
	polynomial operator*(double d, const polynomial & L)
	{
		polynomial pol(L);
		return pol *= d;
	}
	polynomial operator-(const polynomial& L, const polynomial &R)
	{
		polynomial pol(L);
		return pol -= R;
	}
	bool operator==(const polynomial & L, double R)
	{
		polynomial temp(L);
		temp.Update();
		if(temp.n==0|| temp.n>1)
			return false;
		else if (temp.n = 1)
		{
			if (temp.coeff[0] == R)
				return true;
		}
		return false;
	}
	bool operator!=(const polynomial & L, double R)
	{
		return operator==(L, R) ? 0 : 1;
	}
	bool operator>(const polynomial & L, const polynomial & R)
	{
		polynomial templ(L), tempr(R);
		templ.Update();
		tempr.Update();
		if (templ.n > tempr.n)
			return true;
		return false;
	}
	polynomial operator+(const polynomial& L, const polynomial &R)
	{
		polynomial pol(L);
		return pol += R;
	}
};
