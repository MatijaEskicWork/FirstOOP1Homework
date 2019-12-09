#ifndef _CRNOBELASLIKA_H_
#define _CRNOBELASLIKA_H_
#include "Slika.h"

class CrnoBelaSlika: public Slika {
public:
	using Slika::Slika;
	void SetPiksel(const Piksel& piks, const Pozicija& poz) {
		Piksel * p = new Piksel();
		if (piks.getB() + piks.getG() + piks.getR() / 3 > 127) {
			delete p;
			p = new Piksel(255, 255, 255);
		}
		ekran[poz.GetVrsta()][poz.GetKolona()] = *p;
	}

};

#endif