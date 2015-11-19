#pragma once

#include "stdafx.h"
#include "Matrix.h"

namespace OOPLabs
{

	class Vector : public matrix
	{
	private:
		void init(unsigned int w, const Square* inHead = NULL, unsigned int k = 0);
	public:
		void init(const Square* inHead, unsigned int k);
		Vector(int wh = 0, Square* inVect = NULL, int k =0 ) :matrix(wh, 1, inVect, k) {};
		Vector(const Vector&);
		Vector(const matrix&);
		~Vector();																																																		//friend std::ostream& operator<<(std::ostream&, const Vector&);
		//bool oprtmlpt(const Vector&);
		//bool oprtsum(const Vector&);
		Square& operator[](unsigned int);
		const Square& operator[](unsigned int) const;
		//Vector& operator=(const Vector&);
		 Vector& operator*=(const Square&);
		Vector& operator*=(const Vector&);
		//Vector& operator*=(const matrix&);
		Vector& operator=(const matrix&);
		//Vector& operator+=(const matrix&);
		//Vector& operator*=(const matrix&);
		//Vector& operator-=(const matrix&);
		//bool oprtmlpt(const Vector&);
		//bool oprtmlpt(const matrix&);
		//bool oprtsum(const matrix&);
		/*Vector& operator+=(const Vector&);		
		Vector& operator-=(const Vector&);
		friend matrix& operator+=(matrix&, Vector&);B
		friend matrix& operator-=(matrix&, Vector&);*/
		//friend matrix& operator*=(matrix&, Vector&);
	};
	//Vector& operator*(const matrix&, const Vector&);
	//matrix& operator*(const Vector&, const matrix&);
	//matrix& operator*=(matrix&, Vector&);
	/*Vector& operator+(const Vector&, const Vector&);
	Vector& operator-(const Vector&, const Vector&);
	;*/
	//bool oprtsum(const Vector&, const matrix&);
	//bool oprtsum(const matrix&, const Vector&);
	//bool oprtmlpt(const Vector&, const matrix&);
	//bool oprtmlpt(const matrix&, const Vector&);
}
