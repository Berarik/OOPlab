#pragma once

#include "stdafx.h"

namespace OOPLabs
{
	class matrix
	{
	protected:
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
		bool oprtmlpt(const matrix&);
		bool oprtsum(const matrix&);
		matrix& operator=(const matrix&);
		matrix& operator+=(const matrix&);
		matrix& operator-=(const matrix&);
		matrix& operator*=(const matrix&);
		matrix& operator*=(const Square&);
		Square* operator[](int);
		const Square* operator[](int) const;
		friend std::ostream& operator<<(std::ostream&, const matrix&);
		int Width() const;
		int Height() const;
		int Index() const;
	};
	matrix& operator+(const matrix&, const matrix&);
	matrix& operator-(const matrix&, const matrix&);
	matrix& operator*(const matrix&, const matrix&);
	matrix operator*(const matrix&, const Square&);
}