#pragma once
#include "service.h"
#include <assert.h>
#include <string.h>
int addMasina(MyList* v, char* nr_inmat, char* model, char* categorie) {
	Masina m = createMasina(nr_inmat, model, categorie);
	int successful = valideazaMasina(m);
	if (!successful) {
		destroyMasina(&m);
		return 0;
	}
	add(v, m);
	return 1;

}
int findMasina(MyList* v, char* nr_inmat) {
	int poz_to_delete = -1;
	for (int i = 0; i < v->length; i++) {
		Masina m = get(v, i);
		if (strcmp(m.nr_inmat, nr_inmat) == 0) {
			poz_to_delete = i;
			break;
		}
	}
	return poz_to_delete;
}
int deleteMasina(MyList* v, char* nr_inmat) {
	int poz_to_delete = findMasina(v, nr_inmat);
	if (poz_to_delete != -1) {
		Masina m = delete(v, poz_to_delete);
		destroyMasina(&m);
		return 1;
	}
	else
		return 0;
}
int modifyMasina(MyList* v, char* nr_inmat, char* model, char* categorie) {
	int poz_to_delete = findMasina(v, nr_inmat);
	if (poz_to_delete != -1) {
		Masina masinaNoua = createMasina(nr_inmat, model, categorie);
		Masina m = get(v, poz_to_delete);
		destroyMasina(&m);
		setElem(v, poz_to_delete, masinaNoua);
		return 1;
	}
	else
		return 0;
}
MyList filterMasini(MyList* v, char* categorie) {
	
	if (strcmp(categorie, "") != 0) {
		MyList filteredList = createEmpty();
		for (int i = 0; i < v->length; i++) {
			Masina m = get(v, i);
			if (strcmp(categorie, m.categorie) == 0)
				add(&filteredList, createMasina(m.nr_inmat, m.model, m.categorie));
		}
		return filteredList;
	}
	else {
		return copyList(v);
	}
	
}
//MyList sortMelodii(MyList* v) {
//	
//}

void testAddService() {
	MyList v = createEmpty();

	int successful1 = addMasina(&v, "BH14ECM", "Seat Ibiza", "Coupe");
	assert(successful1 == 1);

	int successful2 = addMasina(&v, "", "", "Coupe");
	assert(successful2 == 0);

	int successful3 = addMasina(&v, "BH19CLD", "Ford Mondeo", "");
	assert(successful3 == 0);

	assert(size(&v) == 1);
	Masina m = get(&v, 0);

	assert(strcmp(m.nr_inmat, "BH14ECM") == 0);
	assert(strcmp(m.model, "Seat Ibiza") == 0);
	assert(strcmp(m.categorie, "Coupe") == 0);
	destroy(&v);


}
void testFindService() {
	MyList v = createEmpty();

	int successful1 = addMasina(&v, "BH14ECM", "Seat Ibiza", "Coupe");
	assert(successful1 == 1);

	int successful2 = addMasina(&v, "BH19CLD", "Ford Mondeo", "Docker");
	assert(successful2 == 1);

	int successful3 = addMasina(&v, "B77TTT", "Chevrolet Aveo", "SUV");
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int poz = findMasina(&v, "BH19CLD");

	assert(poz == 1);

	destroy(&v);
	assert(size(&v) == 0);
}
void testModifyService() {
	MyList v = createEmpty();

	int successful1 = addMasina(&v, "BH19CLD", "Seat Ibiza", "Coupe");
	assert(successful1 == 1);

	int successful2 = addMasina(&v, "BH14ECM", "Ford Mondeo", "Docker");
	assert(successful2 == 1);

	int successful3 = addMasina(&v, "B77TTT", "Chevrolet Aveo", "SUV");
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int modify_success = modifyMasina(&v, "BH19CLD", "Ford Mondeo", "Docker");
	assert(modify_success == 1);
	int modify_success2 = modifyMasina(&v, "B19CLD", "Seat Ibiza", "Coupe");
	assert(modify_success2 == 0);
	destroy(&v);
}
void testDeleteService() {
	MyList v = createEmpty();

	int successful1 = addMasina(&v, "BH19CLD", "Seat Ibiza", "Coupe");
	assert(successful1 == 1);

	int successful2 = addMasina(&v, "BH14ECM", "Ford Mondeo", "Docker");
	assert(successful2 == 1);

	int successful3 = addMasina(&v, "B77TTT", "Chevrolet Aveo", "SUV");
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int succesful_del = deleteMasina(&v, "BH19CLD");
	assert(succesful_del == 1);
	int succesfully_del = deleteMasina(&v, "B19CLD");
	assert(succesfully_del == 0);
	destroy(&v);
	assert(size(&v) == 0);
}

void testFilterService() {
	MyList v = createEmpty();

	int successful1 = addMasina(&v, "BH19CLD", "Seat Ibiza", "Coupe");
	assert(successful1 == 1);

	int successful2 = addMasina(&v, "BH14ECM", "Ford Mondeo", "Docker");
	assert(successful2 == 1);

	int successful4 = addMasina(&v, "B77TTT", "Chevrolet Aveo", "SUV");
	assert(successful4 == 1);

	int successful3 = addMasina(&v, "BH07TTT", "Volkswagen Passat", "Docker");
	assert(successful3 == 1);

	assert(size(&v) == 4);

	MyList filteredList = filterMasini(&v, "Docker");
	assert(size(&filteredList) == 2);
	destroy(&filteredList);

	filteredList = filterMasini(&v, "Mini");
	assert(size(&filteredList) == 0);
	destroy(&filteredList);



	filteredList = filterMasini(&v, "");
	assert(size(&filteredList) == 4);
	destroy(&filteredList);

	destroy(&v);

}
//void testSortService() {
//	MyList v = createEmpty();
//
//	int successful1 = addMelodie(&v, "Child in Time", "Deep Purple", 59);
//	assert(successful1 == 1);
//
//	int successful2 = addMelodie(&v, "Kashmir", "Led Zeppelin", 56);
//	assert(successful2 == 1);
//
//	int successful4 = addMelodie(&v, "When The Levee Breaks", "Led Zeppelin", 58);
//	assert(successful4 == 1);
//
//	int successful3 = addMelodie(&v, "(Don't fear) The Reaper", "Blue Oyster Cult", 76);
//	assert(successful3 == 1);
//
//	assert(size(&v) == 4);
//	MyList sortedList = sortMelodii(&v);
//	assert(get(&sortedList, 0).durata == 56);
//	assert(get(&sortedList, 1).durata == 58);
//	assert(get(&sortedList, 2).durata == 59);
//	assert(get(&sortedList, 3).durata == 76);
//
//
//	destroy(&sortedList);
//	destroy(&v);
//}