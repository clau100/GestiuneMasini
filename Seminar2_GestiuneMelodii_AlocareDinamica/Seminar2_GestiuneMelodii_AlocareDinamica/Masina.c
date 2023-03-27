#pragma once
#include "Masina.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Masina createMasina(char* nr_inmat, char* model, char* categorie) {
	Masina m;
	int nrC = (int) strlen(nr_inmat)+1;
	m.nr_inmat = malloc( nrC * sizeof(char));
	strcpy(m.nr_inmat, nr_inmat);

	nrC = (int) strlen(model) + 1;
	m.model = malloc(nrC * sizeof(char));
	strcpy(m.model, model);

    nrC = (int) strlen(categorie) + 1;
    m.categorie = malloc(nrC * sizeof(char));
    strcpy(m.categorie, categorie);
	return m;
}

void destroyMasina(Masina* m) {
	free(m->nr_inmat);
	free(m->model);
    free(m->categorie);
}

Masina copyMasina(Masina m) {
	return createMasina(m.nr_inmat, m.model, m.categorie);
}
int valideazaMasina(Masina m) {
	if (strlen(m.nr_inmat) == 0)
		return 0;
	if (strlen(m.model) == 0)
		return 0;
	return strlen(m.categorie) != 0;
}

void testCreateDestroy() {
	Masina m = createMasina("BH14ECM", "Seat Ibiza", "Coupe");

	assert(strcmp(m.nr_inmat, "BH14ECM") == 0);
	assert(strcmp(m.model, "Seat Ibiza") == 0);
	assert(strcmp(m.categorie, "Coupe") == 0);

	destroyMasina(&m);
}

void testValideaza() {
	Masina m1 = createMasina("", "Seat Ibiza", "suv");
	assert(valideazaMasina(m1) == 0);

	Masina m2 = createMasina("ABC", "", "suv");
	assert(valideazaMasina(m2) == 0);

	Masina m3 = createMasina("ABC", "Seat Ibiza", "");
	assert(valideazaMasina(m3) == 0);

	Masina m4 = createMasina("ABC", "Seat Ibiza", "suv");
	assert(valideazaMasina(m4) == 1);

	destroyMasina(&m1);
	destroyMasina(&m2);
	destroyMasina(&m3);
	destroyMasina(&m4);

}