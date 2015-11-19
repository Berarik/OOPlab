#pragma once

#include "stdafx.h"

namespace OOPLabs
{
	class matrix
	{
	protected:
		void init(int n, int m, const Square* inHead, unsigned int k);
		static unsigned int cnt;
		unsigned int ind, m, n;
		Square* Head = NULL;
	public:
		void init(const Square* inHead, unsigned int k);
		matrix(int, int, const Square* inHead = NULL, unsigned int = 0);
		explicit matrix(int = 0, const Square* inHead = NULL, unsigned int = 0);
		matrix(const matrix&);
		~matrix();
		virtual bool oprtmlpt(const matrix&);
		bool oprtsum(const matrix&);
		virtual matrix& operator=(const matrix&);
		matrix& operator+=(const matrix&);
		matrix& operator-=(const matrix&);
		matrix& operator*=(const matrix&);
		matrix& operator*=(const Square&);
		Square* operator[](unsigned int);
		const Square* operator[](unsigned int) const;
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