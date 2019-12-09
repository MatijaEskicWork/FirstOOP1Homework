#ifndef _SLIKA_H_
#define _SLIKA_H_
#include "Piksel.h"
#include "Pozicija.h"

class Slika {
public:
	Slika(int w_, int h_) {
		this->w = w_;
		this->h = h_;
		ekran = new Piksel*[h];
		for (int i = 0; i < h; i++) {
			ekran[i] = new Piksel[w];
			for (int j = 0; j < w; j++) {
				ekran[i][j] = Piksel{};
			}
		}
	}

	virtual ~Slika() {
		brisi();
	}

	int GetW() const {
		return this->w;
	}

	int GetH() const {
		return this->h;
	}

	Piksel& operator[](const Pozicija& poz) {
		return ekran[poz.GetVrsta()][poz.GetKolona()];
	}

	Piksel operator[](const Pozicija& poz) const {
		return ekran[poz.GetVrsta()][poz.GetKolona()];
	}

	virtual void SetPiksel(const Piksel& piks, const Pozicija& poz) {
		ekran[poz.GetVrsta()][poz.GetKolona()] = piks;	
	}

	int getSize() const {
		return	this->w * this->h * 24;
	}

	friend std::ostream& operator<<(std::ostream& os, const Slika& s) {
		os << s.getSize() << std::endl;
		for (int i = 0; i < s.h; i++) {
			for (int j = 0; j < s.w; j++) {
				os << s.ekran[i][j] << " ";
			}
			os << std::endl;
		}
		return os;
	}



protected:
	int w, h;
	Piksel **ekran;
	void brisi() {
		for (int i = 0; i < h; i++) {
			delete[] ekran[i];
		}
		delete[] ekran;
		this->w = 0;
		this->h = 0;
	}
};


#endif