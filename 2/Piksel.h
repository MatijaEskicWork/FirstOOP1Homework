#ifndef _PIKSEL_H_
#define _PIKSEL_H_
#include <ostream>

class Piksel {
public:
	Piksel(int r_ = 0, int g_ = 0, int b_ = 0) {
		this->r = r_;
		this->g = g_;
		this->b = b_;
	}

	int getR() const {
		return this->r;
	}

	int getG() const {
		return this->g;
	}

	int getB() const {
		return this->b;
	}

	friend Piksel operator+(const Piksel& p1, const Piksel& p2) {

		return Piksel{ (p1.r + p2.r) / 2, (p1.g + p2.g) / 2, (p1.b + p2.b) / 2 };
	}

	friend bool operator==(const Piksel& p1, const Piksel& p2) {
		return p1.r == p2.r && p1.g == p2.g && p1.b == p2.b;
	}

	friend std::ostream& operator<<(std::ostream& os, const Piksel& p) {
		return os << "(" << p.r << "," << p.g << "," << p.b << ")";
	}

	

private:
	int r, g, b;
};


#endif
