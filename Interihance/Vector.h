#pragma once

#include "stdafx.h"
#include "Matrix.h"

namespace OOPLabs
{

	class Vector : public matrix
	{
	private:
		void init(int w, const Square* inHead = NULL, int k = 0);
	public:
		void init(const Square* inHead, int k);
		Vector(int wh = 0, Square* inVect = NULL, int k =0 ) :matrix(wh, 1, inVect, k) {};
		Vector(const Vector&);
		Vector(const matrix&);
		~Vector();			
		Vector& operator=(const matrix&);
	/*	Square& operator[](int i);
		const Square& operator[](int) const;*/
		bool oprtmlpt(const Vector&);
		bool oprtsum(const Vector&);
		bool oprtmlpt(const matrix&);
		//bool oprtsum(const matrix&);
		//friend std::ostream& operator<<(std::ostream&, const Vector&);
		//Vector& operator=(const Vector&);
		//Vector& operator*=(const Square&);
		//matrix& operator*=(const Vector&);
		//Vector& operator*=(const matrix&);
		//Vector& operator+=(const matrix&);
		//Vector& operator*=(const matrix&);
		//Vector& operator-=(const matrix&);
		//bool oprtmlpt(const Vector&);
		//Vector& operator+=(const Vector&);		
		//Vector& operator-=(const Vector&);
		//friend matrix& operator+=(matrix&, Vector&);
		//friend matrix& operator-=(matrix&, Vector&);
		//friend matrix& operator*=(matrix&, Vector&);
	};
	matrix operator*(const Vector&, const Vector&);
	matrix operator*(const Vector&, const matrix&);
	matrix operator*(const matrix&, const Vector&);
	/*Vector& operator+(const Vector&, const Vector&);
	Vector& operator-(const Vector&, const Vector&);
	//bool oprtsum(const Vector&, const matrix&);
	//bool oprtsum(const matrix&, const Vector&);
	//bool oprtmlpt(const Vector&, const matrix&);
	//bool oprtmlpt(const matrix&, const Vector&);*/
}
