#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <stdio.h>


typedef struct {
	char* nr_inmat;
	char* model;
	char* categorie;
} Masina;

/*
* Creeaza o noua masina
* 
* @param nr_inmat: numarul de inmatriculare al masinii (string)
* @param model: modelul masinii (string)
* @param categorie: categoria masinii (string)
* 
* @return masina creata (Masina)
*/

Masina createMasina(char* nr_inmat, char* model, char* categorie);

/*
* Distruge masina
*/
void destroyMasina(Masina* m);
/*
* Valideaza masina
* O masina este valida daca nr_inmatriculare, model si categoria diferit de ""
* @param m: masina de validat (Masina)
* 
* @return: 1 daca masina este valida, 0 daca nu
*/
int valideazaMasina(Masina m);

/*
* Creeaza o copie a masinii date (similar cu Python "deepcopy")
*/
Masina copyMasina(Masina m);

void testCreateDestroy();
void testValideaza();
