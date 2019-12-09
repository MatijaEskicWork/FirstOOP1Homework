#ifndef _POLJE_H_
#define _POLJE_H_
#include <iostream>

class Polje {

public:

	Polje(int neprohodnost1 = 100) {
		this->neprohodnost = neprohodnost1;
	}

	virtual ~Polje(){
	}

	int GetNeprohodnost() const {
		return this->neprohodnost;
	}

	Polje operator++(int k) {
		if (this->neprohodnost + 1 <= 1000)
			++this->neprohodnost;
		return *this;
	}

	Polje operator--(int k) {
		if (this->neprohodnost - 1 >= 0)
			--this->neprohodnost;
		return *this;
	}

	virtual void ispis() const {
		std::cout << "S_" << neprohodnost;
	}

	friend std::ostream& operator<<(std::ostream& ot, const Polje& p) {
		p.ispis();
		return ot;
	}

	virtual Polje* kopija() const {
		return new Polje(*this);
	}

protected:
	int neprohodnost;
};



#endif
