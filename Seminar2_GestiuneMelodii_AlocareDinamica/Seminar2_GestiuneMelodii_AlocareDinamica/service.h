#pragma once
#include <stdlib.h>
#include "MyList.h"

/*
* Adauga o melodie
* 
* @param v: (adresa pentru) lista in care se adauga (MyList* v)
* @param nr_inmat: numarul de inmatriculare al masinii care se adauga (char*)
* @param model: modelul masinii care se adauga (char*)
* @param categorie: categoria masinii care se adauga (char*)
* 
* @return: 1 daca masina a fost adaugata cu succes, 0 altfel (int)
* post: masina cu datele date este adaugata in lista (daca este o masina valida)
*/
int addMasina(MyList* v, char* nr_inmat, char* model, char* categorie);

/*
* Sterge o masina
*
* @param v: (adresa pentru) lista din care se sterge (MyList* v)
* @param nr_inmat: numarul de inmatriculare al masinii care se sterge (char*)
*
* @return: 1 daca masina a fost stearsa cu succes, 0 altfel (int)
* post: masina cu numarul de inmatriculare nr_inmat este stearsa din lista daca exista
*/
int deleteMasina(MyList* v, char* nr_inmat);

/*
* Modifica o masina
*
* @param v: (adresa pentru) lista in care se modifica (MyList* v)
* @param nr_inmat: numarul de inmatriculare al masinii care se modifica (char*)
* @param model: noul model al masinii (char*)
* @param categorie: noua categorie a masinii (char*)
*
* @return: 1 daca masina a fost modificata cu succes, 0 altfel (int)
* post: masina cu numarul de inmatriculare nr_inmat are modelul model si categoria categorie (daca o astfel
*		de melodie exista)
*/
int modifyMasina(MyList* v, char* nr_inmat, char* model, char* categorie);


/*
* Gaseste o masina cu numarul de inmatriculare dat
*
* @param v: (adresa pentru) lista in care se cauta (MyList* v)
* @param nr_inmat: numarul de inmatriculare al masinii care se cauta (char*)
*
* @return: pozitia din lista a masinii cautate, -1 daca
			masina nu exista in lista (int)
*/
int findMasina(MyList* v, char* nr_inmat);

/*
* Filtreaza lista de masini dupa o categorie data
*
* @param v: (adresa pentru) lista data (MyList* v)
* @param categorie: categoria dupa care se filtreaza lista (char*)

*
* @return: lista cu masinile care au categoria categorie (MyList)
*		   daca categorie="" se returneaza o copie a listei originale
*/
MyList filterMasini(MyList* v, char* categorie);

/*
* Returneaza o lista sortata de masini
* Criteriu de sortare: numar de inmatriculare (alfabetic)
* 
* @param v: (adresa pentru) lista data (MyList* v)
* 
* @return: o lista sortata de masini  (MyList)
*/
//MyList sortMelodii(MyList* v);

void testAddService();
void testModifyService();
void testDeleteService();
void testFindService();
void testFilterService();
//void testSortService();

