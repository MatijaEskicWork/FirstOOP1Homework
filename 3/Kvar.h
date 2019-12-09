#ifndef _KVAR_H_
#define _KVAR_H_
#include "Datum.h"
#include <string>


class Kvar {
public:
	
	Kvar(const std::string& str1, const Datum& dat ) {
		this->opis = str1;
		this->datum = dat;
	}

	std::string getOpis() const {
		return opis;
	}

	Datum getDatum() const {
		return datum;
	}

	void SetOtklonjen(bool b) {
		this->otklonjen = b;
	}

	friend std::ostream& operator<<(std::ostream& os, const Kvar& k) {
		return os << k.datum << "-" << k.opis;
	}

private:
	std::string opis;
	Datum datum;
	bool otklonjen;
};

#endif
