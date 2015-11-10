#pragma once

namespace OOPLab {
	class vect
	{
	private:
		double x, y, z;
		static int cnt;
		int ind;
	public:
		explicit vect(double = 0, double = 0, double = 0);//        /*explicit*/ vect();
		~vect();
		void coutcoor() const;
		double readx() const;
		double ready() const;
		double readz() const;
		void writex(double);
		void writey(double);
		void writez(double);
		void cpvect(const vect&);
		void mlpt(double);
		bool norm();
		double modul() const;
	};
	vect sum(const vect&, const vect&);
	vect sub(const vect&, const vect&);
	vect vmlpt(const vect &, const vect &);
	double anglevect(const vect&, const vect&);
	double sinvect(const vect&, const vect&);
	double cosvect(const vect&, const vect&);
	double smlpt(const vect&, const vect&);
}
