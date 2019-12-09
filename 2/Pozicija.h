#ifndef _POZICIJA_H_
#define _POZICIJA_H_

class Pozicija {
public:
	Pozicija(int vrsta_, int kolona_) {
		this->vrsta = vrsta_;
		this->kolona = kolona_;
	}

	int GetVrsta() const {
		return this->vrsta;
	}

	int GetKolona() const {
		return this->kolona;
	}

	friend int operator-(const Pozicija& p1, const Pozicija& p2) {
		return abs(p1.vrsta - p2.vrsta) + abs(p1.kolona - p2.kolona);
	}

private:
	int vrsta, kolona;
};

#endif