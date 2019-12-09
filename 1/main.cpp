#include <iostream> 
#include "Polje.h"
#include "PoljeSaSumom.h"
#include "PoljeSaPutom.h"
#include "Mapa.h"

int main() {

	Mapa *mapa = new Mapa(5, 4);
	//std::cout << *mapa;
	mapa->Zameni(2, 2, 10);
	mapa->Zameni(3, 3, PoljeSaPutom::ZEMLJANI);
	std::cout << *mapa;
	system("PAUSE");


	return 0;
}