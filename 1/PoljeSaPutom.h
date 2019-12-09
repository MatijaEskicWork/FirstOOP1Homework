#ifndef _POLJESAPUTOM_H_
#define _POLJESAPUTOM_H_
#include "Polje.h"

class PoljeSaPutom : public Polje  {

public:
	enum VRSTAPUTA {ZEMLJANI = 'Z', KAMENI = 'K' };

	PoljeSaPutom(enum VRSTAPUTA vrsta_puta1, int neprohodnost1 = 100) : Polje(neprohodnost1) {
		this->v = vrsta_puta1;
	}

	void ispis() const override{
		std::cout << (char)v << "_" << neprohodnost;
	}

	/*friend std::ostream& operator<<(std::ostream& ot, const PoljeSaPutom& p) {
		p.ispis();
		return ot;
	}*/

	PoljeSaPutom* kopija() const override{
		return new PoljeSaPutom(*this);
	}

protected:
	enum VRSTAPUTA v;

};



#endif
