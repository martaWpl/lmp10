#ifndef PUNKTY_H
#define PUNKTY_H

#include <stdio.h>

//struktura opisująca punkty pobierane z pliku:
typedef struct {
		int n;
		double *x;
		double *y;
} punkty_t;

int czytaj_bledne_punkty ( FILE* inf, punkty_t *pts);

#endif

