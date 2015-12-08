#pragma once
#include "stdafx.h"
namespace OOPLabs
{
	template <class T>
	class matrix
	{
	private:
		void init(int w, int h, const T* inHead, int k);
	//	static int cnt;
		int ind, m, n;
		T* Head = NULL;
	public:
		void init(const T* inHead, int k);
		matrix(int, int, const T* inHead = NULL, int = 0);
		explicit matrix(int = 0, const T* inHead = NULL, int = 0);
		matrix(const matrix<T>&);
		~matrix();
		T* operator[](int);
		const T* operator[](int) const;
		//const Square& searchmax() const;
		//const Square& searchmin() const;
		bool oprtmlpt(const matrix<T>& B) const
		{
			return (m == B.n);
		}
		bool oprtsum(const matrix<T>& B) const
		{
			return (n == B.n&&m == B.m);
		}
		matrix<T>& operator=(const matrix<T>&);
		matrix<T>& operator+=(const matrix<T>&);
		matrix<T>& operator-=(const matrix<T>&);
		matrix<T>& operator*=(const matrix<T>&);
		matrix<T>& operator*=(const T&);
		template <class T>
		friend std::ostream& operator<<(std::ostream&, const matrix<T>&);

	};
	template <class T>
	matrix<T> operator+(const matrix<T>&, const matrix<T>&);
	template <class T>
	matrix<T> operator-(const matrix<T>&, const matrix<T>&);
	template <class T>
	matrix<T> operator*(const matrix<T>&, const matrix<T>&);
	template <class T>
	matrix<T> operator*(const matrix<T>&, const T&);
	template <class T>
	matrix<T> operator*(const T&, const matrix<T>&);

};
#include "template.cpp"