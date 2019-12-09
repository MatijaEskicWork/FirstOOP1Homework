#ifndef _POLJESASUMOM_H_
#define _POLJESASUMOM_H_
#include "Polje.h"

class PoljeSaSumom : public Polje {
public:
	PoljeSaSumom(unsigned gustina1, int neprohodnost1 = 100) : Polje(neprohodnost1) {
		this->gustina = gustina1; 
	}

	unsigned GetGustina() const {
		return this->gustina;
	}

	void ispis() const override {
		std::cout << "S_" << neprohodnost << "(" << gustina << ")";
	}

	/*friend std::ostream& operator<<(std::ostream& ot, const PoljeSaSumom& p) {
		p.ispis();
		return ot;
	}*/

	PoljeSaSumom* kopija() const override{
		return new PoljeSaSumom(*this);
	}



private:
	unsigned gustina;

};


#endif
