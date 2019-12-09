#ifndef _DATUM_H_
#define _DATUM_H_
#include <string>
#include <ostream>

class Datum {
public :
	Datum(int dan_ = 30, int mesec_ = 11, int godina_ = 2019) {
		this->dan = dan_;
		this->mesec = mesec_;
		this->godina = godina_;
	}

	int& operator[](const std::string index) {
		int k = -1;
		if (index == "dan") return this->dan;
		else if (index == "mesec") return this->mesec;
		else if (index == "godina") return this->godina;
		else return k;
	}

	int operator[](const std::string index) const {
		if (index == "dan") return this->dan;
		else if (index == "mesec") return this->mesec;
		else if (index == "godina") return this->godina;
		else return -1;
	}

	friend bool operator<(const Datum& dat1, const Datum& dat2) {
		return (dat1["godina"] < dat2["godina"]) || (dat1["godina"] == dat2["godina"] && dat1["mesec"] < dat2["mesec"]) ||
			(dat1["godina"] == dat2["godina"] && dat1["mesec"] == dat2["mesec"] && dat1["dan"] < dat2["dan"]);
	}

	friend std::ostream& operator<<(std::ostream& os, const Datum& d) {
		return os << d["dan"] << "." << d["mesec"] << "." << d["godina"] << ".";
	}

private:
	int dan, mesec, godina;
};



#endif
