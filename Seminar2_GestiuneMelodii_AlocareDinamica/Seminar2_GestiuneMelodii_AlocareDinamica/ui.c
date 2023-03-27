#pragma once
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
#include <stdio.h>

#include "my_utils.h"
#include "service.h"


void testAll() {
	testCreateDestroy();
	testValideaza();
	testCreateVector();
	
	testIterate();
	testCopy();
	
	
	testAddService();
	
	testModifyService();
	
	testDeleteService();
	testFindService();
	testFilterService();

    testTrim();
	//testSortService();

}

void printAllMasini(MyList* v) {
	if (v->length == 0)
		printf("Nu exista masini.\n");
	else
	{
		printf("Masinile curente sunt:\n");
		for (int i = 0; i < size(v); i++) {
			Masina m = get(v, i);
			printf("Nr. inmat.: %s | Model: %s | Categorie: %s\n", m.nr_inmat, m.model, m.categorie);
		}
	}
}

void printMenu() {
	printf("1. Adauga masina\n2. Actualizare masina\n");
	printf("3. Sterge masina\n4. Afiseaza toate masinile de o anumita categorie\n");
	printf("5. Sorteaza masinie dupa nr. inmat.\n6. Tipareste toate\n0. Iesire\n");
}
void uiAdd(MyList* v) {
    char nr_inmat[30], model[30], categorie[30];
	char temp;
	scanf("%c", &temp);
	printf("Numarul de inmatriculare al masinii este:");
	fgets(nr_inmat, 30, stdin);
	printf("Modelul masinii este:");
	fgets(model, 30, stdin);
	printf("Categoria masinii este:");
	fgets(categorie, 30, stdin);
	trimTrailing(nr_inmat);
	trimTrailing(model);
    trimTrailing(categorie);

	int successful = addMasina(v,nr_inmat,model,categorie);
	if (successful)
		printf("Masina adaugata cu succes.\n");
	else
		printf("Masina invalida.\n");

}
void uiModify(MyList* v) {
    char nr_inmat[30], model[30], categorie[30];
    char temp;
    scanf("%c", &temp);
    printf("Numarul de inmatriculare al masinii este:");
    fgets(nr_inmat, 30, stdin);
    printf("Modelul masinii este:");
    fgets(model, 30, stdin);
    printf("Categoria masinii este:");
    fgets(categorie, 30, stdin);
    trimTrailing(nr_inmat);
    trimTrailing(model);
    trimTrailing(categorie);

	int successful = modifyMasina(v, nr_inmat, model, categorie);
	if (successful)
		printf("Masina modificata cu succes.\n");
	else
		printf("Nu exista masina cu datele date.\n");
}
void uiDelete(MyList* v) {
    char nr_inmat[30];
    char temp;
    scanf("%c", &temp);
    printf("Numarul de inmatriculare al masinii este:");
    fgets(nr_inmat, 30, stdin);
    trimTrailing(nr_inmat);
	int successful = deleteMasina(v, nr_inmat);
	if (successful)
		printf("Masina stearsa cu succes.\n");
	else
		printf("Nu exista masina cu datele date.\n");
}
void uiFilter(MyList* v) {
    char categorie[30];
    char temp;
    scanf("%c", &temp);
    printf("Categoria masinii este:");
    fgets(categorie, 30, stdin);
    trimTrailing(categorie);
	MyList filteredList = filterMasini(v, categorie);
	printAllMasini(&filteredList);
	destroy(&filteredList);

}
void uiSort() {

}
void run() {
	MyList songList = createEmpty();
	int running = 1;
	while (running) {
		printMenu();
		int cmd;
		printf("Comanda este:");
		scanf("%d", &cmd);
		switch (cmd) {
		case 1:
			uiAdd(&songList);
			break;
		case 2:
			uiModify(&songList);
			break;
		case 3:
			uiDelete(&songList);
			break;
		case 4:
			uiFilter(&songList);
			break;
		case 6:
			printAllMasini(&songList);
			break;
		case 0:
			running = 0;
			destroy(&songList);
			break;
		default:
			printf("Comanda invalida!\n");

		}
	}
}
int main() {
	testAll();
	run();
}
