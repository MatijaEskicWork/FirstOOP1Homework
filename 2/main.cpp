#include <iostream>
#include "Piksel.h"
#include "Pozicija.h"
#include "Slika.h"
#include "CrnoBelaSlika.h"

int main() {

	Slika *slika = new Slika(10, 20);
	std::cout << *slika;

	slika->SetPiksel(Piksel{ 150, 150, 150 }, Pozicija{ 10, 4 });
	std::cout << (*slika)[Pozicija{ 10, 4 }];

	Piksel p1 = { 10, 30, 40 };
	Piksel p2 = { 10, 20, 30 };
	Piksel p4 = { 10, 25, 35 };
	Piksel p3 = p1 + p2;
	if (p3 == p4)
		std::cout << p3;

	slika = new CrnoBelaSlika(10, 20);
	slika->SetPiksel(Piksel{ 150, 150, 150 }, Pozicija{ 10, 4 });
	std::cout << *slika;

	Pozicija poz1 = { 1, 2 };
	Pozicija poz2 = { 3, 7 };
	std::cout << std::endl;
	std::cout << poz1 - poz2;
	system("PAUSE");
	return 0;
}