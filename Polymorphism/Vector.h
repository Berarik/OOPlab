#pragma once

#include "stdafx.h"
#include "Matrix.h"

namespace OOPLabs
{

	class Vector : matrix
	{
	private:
		void init(int w, const Square* inHead = NULL, int k = 0);	
	public:
		void init(const Square* inHead, int k);
		Vector(int wh = 0, Square* inVect = NULL, int k =0 ) :matrix(wh, 1, inVect, k) {};
		Vector(const Vector&);
		~Vector();
		friend std::ostream& operator<<(std::ostream&, const Vector&);
		bool oprtmlpt(const Vector&);
		bool oprtsum(const Vector&);
		Square& operator[](int);
		const Square& operator[](int) const;
		Vector& operator=(const Vector&);
		Vector& operator+=(const Vector&);
		Vector& operator*=(const Vector&);
		Vector& operator-=(const Vector&);
		Vector& operator*=(const Square&);
		Vector& operator=(const matrix&);
		Vector& operator+=(const matrix&);
		Vector& operator*=(const matrix&);
		Vector& operator-=(const matrix&);
//		Vector& operator*=(const matrix&);
		int Width() const;
		int Height() const;

	};
	Vector& operator+(const Vector&, const Vector&);
	Vector& operator-(const Vector&, const Vector&);
	Vector& operator*(const Vector&, const Vector&);
	Vector operator*(const Vector&, const Square&);
	bool oprtsum(const Vector&, const matrix&);
	bool oprtsum(const matrix&, const Vector&);
	bool oprtmlpt(const Vector&, const matrix&);
	bool oprtmlpt(const matrix&, const Vector&);
}
