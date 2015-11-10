#pragma once
#include "stdafx.h"
#include <stdarg.h>
#include <stdlib.h>
#include <iomanip>

namespace OOPLabs
{
	class matrix
	{
	private:
		void init(int w, int h, const Square* inHead, int k);
		static int cnt;
		int ind, m, n;
		Square* Head = NULL;
	public:
		void init(const Square* inHead, int k);
		matrix(int, int, const Square* inHead = NULL, int = 0);
		explicit matrix(int = 0, const Square* inHead = NULL, int = 0);
		matrix(const matrix&);
		~matrix();
		Square* operator[](int);
		const Square* operator[](int) const;
		const Square& searchmaxSquareSize() const;
		const Square& searchminSquareSize() const;
		bool oprtmlpt(const matrix&) const;
		bool oprtsum(const matrix&) const;
		matrix& operator=(const matrix&);
		matrix& operator+=(const matrix&);
		matrix& operator-=(const matrix&);
		matrix& operator*=(const matrix&);
		matrix& operator*=(const Square&);
		friend std::ostream& operator<<(std::ostream&, const matrix&);
	};
	matrix operator+(const matrix&, const matrix&);
	matrix operator-(const matrix&, const matrix&);
	matrix operator*(const matrix&, const matrix&);
	matrix operator*(const matrix&, const Square&);
	matrix operator*(const Square&, const matrix&); //Умножение слева
}
