#ifndef _MAPA_H_
#define _MAPA_H_
#include "Polje.h"
#include "PoljeSaPutom.h"
#include "PoljeSaSumom.h"

class Mapa {
public:
	Mapa(const int vrste1, const int kolone1) {
		if (dobreGranice(vrste1, kolone1)) {
			this->vrste = vrste1;
			this->kolone = kolone1;
			matrica = new Polje**[vrste1];
			for (int i = 0; i < vrste1; i++) {
				matrica[i] = new Polje*[kolone1];
				for (int j = 0; j < kolone1; j++) {
					matrica[i][j] = new Polje();
				}
			}
		}
	}

	Mapa(Mapa& m){
		kopiraj(m);
	}

	Mapa(Mapa&& m) {
		premesti(m);
	}

	~Mapa() { brisi(); }

	friend Mapa& operator +=(Mapa& mapa, int broj) {
		for (int i = 0; i < mapa.vrste; i++) {
			for (int j = 0; j < mapa.kolone; j++) {
				for (int k = 0; k < broj; k++)
					mapa.matrica[i][j]++;
			}
		}
		return mapa;
	}

	friend Mapa operator -=(Mapa& mapa, int broj) {
		broj = -broj;
		mapa += broj;
		return mapa;
	}

	Mapa& Zameni(const int vrsta1,  const int kolona1, const enum PoljeSaPutom::VRSTAPUTA v1) {
		if (dobreIvice(vrsta1, kolona1)) {
			int k = matrica[vrsta1 - 1][kolona1 - 1]->GetNeprohodnost();
			delete matrica[vrsta1 - 1][kolona1 - 1];
			matrica[vrsta1 - 1][kolona1 - 1] = new PoljeSaPutom(v1, k);
			return *this;
		}
	}

	Mapa& Zameni(const int vrsta1, const int kolona1, const unsigned gustina1) {
		if (dobreIvice(vrsta1, kolona1)) {
			int k = matrica[vrsta1 - 1][kolona1 - 1]->GetNeprohodnost();
			delete matrica[vrsta1 - 1][kolona1 - 1];
			matrica[vrsta1 - 1][kolona1 - 1] = new PoljeSaSumom(gustina1, k);
			return *this;
		}
	}

	friend std::ostream& operator<<(std::ostream& ot, const Mapa& mapa) {
		for (int i = 0; i < mapa.vrste; i++) {
			for (int j = 0; j < mapa.kolone; j++) {
				ot << *(mapa.matrica[i][j]); 
				std::cout << "\t";
			}
			ot << std::endl;
		}
		return ot;
	}

private :

	int Neprohodno(int i, int j) const {
		return matrica[i][j]->GetNeprohodnost();
	}

	void kopiraj(const Mapa &t) {
		for (int i = 0; i < vrste; i++) {
			for (int j = 0; j < kolone; j++) {
				if (t.matrica[i][j])
					matrica[i][j] = t.matrica[i][j]->kopija();
				else
					matrica[i][j] = nullptr;
			}
		}
	}

	void premesti(Mapa &t) {
		for (int i = 0; i < vrste; i++) {
			for (int j = 0; j < kolone; j++) {
				matrica[i][j] = t.matrica[i][j];
				t.matrica[i][j] = nullptr;			}		}	}	
	void brisi() {
		for (int i = 0; i < vrste; i++) {
			delete[]matrica[i];
			for (int j = 0; j < kolone; j++) {
				delete matrica[i][j];
			}
		}
		delete[]matrica;
		this->matrica = nullptr;
	}

	bool dobreGranice(int x, int y) {
		return x > 0 && y > 0;
	}

	bool dobreIvice(int x, int y) {
		return x > 0 && x <= vrste + 1 && y > 0 && y <= kolone + 1;
	}

	Polje*** matrica;
	int vrste, kolone;
};

#endif
