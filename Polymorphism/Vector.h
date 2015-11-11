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
		Vector(int wh = 0, Square* inVect = NULL, int k = 0) :matrix(wh, 1, inVect, k) {};
		Vector(Vector&);
		friend std::ostream& operator<<(std::ostream&, const Vector&);
		bool oprtmlpt(const Vector&, const matrix&);
		bool oprtmlpt(const matrix&, const Vector&);
		bool oprtmlpt(const Vector&);
		bool oprtsum(const Vector&, const matrix&);
		bool oprtsum(const matrix&, const Vector&);
		bool oprtsum(const Vector&);
	};
}
