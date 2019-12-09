#ifndef _GARANCIJA_H_
#define _GARANCIJA_H_
#include "Datum.h"
#include "Kvar.h"
#include <ostream>
#include <string>


class Garancija {
public:



	Garancija(const Datum& pocetak_, const Datum& kraj_) {
		this->pocetak = pocetak_;
		this->kraj = kraj_;
		this->br_kvarova = 0;
	}

	void DodajKvar(const Kvar& k) {
		if (pocetak < k.getDatum() && k.getDatum() < kraj && list->rep)
		(*list)+= k;
	}

	int GetBrKvarova()const {
		return br_kvarova;
	}

	class List {
	protected:
		struct Elem {
			Kvar k;
			Elem* next;
			Elem(Kvar kk, Elem *n = nullptr) :k(kk), next(n) {}
		};
		void kopirajListu(const List& l) {
			for (Elem* e = l.glava; e; e = e->next) {
				*this += e->k;
			}
		}
		void pomeriListu(List& l) {
			glava = l.glava;
			l.glava = nullptr;
		}
		void brisiListu() {
			while (glava) {
				Elem* tmp = glava;
				glava = glava->next;
				delete tmp;
			}
		}
		Elem* glava = nullptr, *rep = nullptr;
	public:
		List() = default;

		List(List& l) {
			kopirajListu(l);
		}

		Elem GetRep() const {
			return this->rep;
		}

		List(List&& l) {
			pomeriListu(l);
		}

		List& operator+=(Kvar k) {
			rep = (glava == nullptr ? glava : rep->next) = new Elem(k);
			return *this;
		}

		virtual ~List() {
			brisiListu();
		}
	};

private:
	Datum pocetak, kraj;
	int br_kvarova;


protected:
	List *list;
};


#endif