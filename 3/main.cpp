#include <iostream>
#include "Datum.h"
#include "Kvar.h"

int main() {
	Datum *d1 = new Datum(1, 3, 2018);
	Datum *d2 = new Datum(1, 5, 2019);
	Datum *d3 = new Datum(2, 2, 2002);
	bool Ok = *d2 < *d3;
	if (Ok) std::cout << *d1;
	else  std::cout << *d2;
	std::cout << std::endl;
	std::cout << (*d3)["dan"] << "." << (*d3)["mesec"] << "." << (*d3)["godina"] << ".";
	Kvar k = { "neki", Datum(1, 2, 2005) };
	std::cout << k.getDatum() << k.getOpis();
	std::cout << std::endl;
	std::cout << k;

	system("PAUSE");
}
