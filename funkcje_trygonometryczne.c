#include "funkcje_trygonometryczne.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define MALLOC_FAILED( P, SIZE ) (((P)=malloc( (SIZE)*sizeof( *(P))))==NULL)
#define M_PI 3.14159265358979323846264338327

int
alokuj_parametry (parametry_funkcji_t *par, int n)
{
  par->n = n;
  return MALLOC_FAILED (par->x, par->n)
    || MALLOC_FAILED (par->f, par->n)
    || MALLOC_FAILED (par->a, par->n)
    || MALLOC_FAILED (par->b, par->n);
}

int
czytaj_parametry (parametry_funkcji_t *par, FILE *inf)
{
  int i;
  if (fscanf (inf, "%d", &(par->n)) != 1 || par->n < 0)
    return 1;

  if (alokuj_parametry (par, par->n))
    return 1;

  for (i = 0; i < par->n; i++)
    if (fscanf
        (inf, "%lf %lf %lf %lf %lf", par->x + i, par->f + i, &(par->a0),
         par->a + i, par->b + i ) != 5)
      return 1;

  return 0;
}

void
wypisz_parametry (parametry_funkcji_t *par, FILE *ouf)
{
  int i;
  fprintf (ouf, "%d\n", par->n);
  for (i = 0; i < par->n; i++)
    fprintf (ouf, "%g %g %g %g %g\n", par->x[i], par->f[i], par->a0,
             par->a[i], par->b[i]);
}

double
wartosc_parametrow (parametry_funkcji_t *par, double x)
{
  int i;
  double s=1/2*(par->a0);

  for (i = 1; i <= par->nb; i++) {
        s=s+(par->a[i])*cos(i*x)+(par->b[i])*sin(i*x);
  }
  return s;
}

