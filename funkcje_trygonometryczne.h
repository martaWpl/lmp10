
#ifndef FUNKCJE_TRYGONOMETRYCZNE_H
#define FUNKCJE_TRYGONOMETRYCZNE_H

#include <stdio.h>
//struktura do liczenia wielomianu za pomocą funkcji trygonometrycznych
//	n-liczba punktow
//	nb-liczba bazowa 
//	x- wskaźnik do tablicy zawierającej współrzędne x punktów
//	f- wskaźnik do tablicy zawierajacej współrzędne y punktów
//	a- wskaźniki a dla poszczególnych punktów
//	b- wskaźniki b dla poszczególnych punktów
typedef struct {
		int n;
		int nb;
		double *x;
		double *f;
		double *a;
		double *b;
} parametry_funkcji_t;

int alokuj_parametry( parametry_funkcji_t *par, int n );

int  czytaj_parametry ( parametry_funkcji_t *par,  FILE * inf );

void  wypisz_parametry ( parametry_funkcji_t *par, FILE * ouf );

double wartosc_wielomianu( parametry_funkcji_t *par, double x);

#endif

