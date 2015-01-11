#include "aproksymator_f_trygonometrycznymi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define M_PI 3.14159265358979323846264338327

 
/*	Majac dane wspolrzedne parzystej liczby (2L) rownoodleglych
	punktow wyznaczamy a0, a1, a2,...anb,b1,b2,..,bnb, 
	gdzie nb-liczba funkcji bazowych.
	Funkcja Oblicz_a_b wyznacza a1,a2,...anb,b1,b2,...bnb
	w aproksymacji sredniokwadratowej parametry te liczymy nastepujaco:
	aj=1/L * suma (od i=0 do 2L-1)[f(xi)cos(PI()*i*j/L)]
	bj=1/L * suma (od i=0 do 2L-1)[f(xi)sin(PI()*i*j/L)]
	Wspolczynnik a0:
        dla j=0:
        a0=1/L * suma (od i=0 do 2L-1) [f(xi)]
*/
void 
oblicz_a_b(punkty_t *pts, parametry_funkcji_t *par)
{
	int i,j,k,L;
	double s,s1,s2,p;
	
	if (alokuj_parametry (par, pts->n) == 0) {
                par->x=pts->x;
                par->f=pts->y;
	}

	s=0.0;
	s1=0.0;
	s2=0.0;
	par->n=pts->n;
	par->nb=par->n;

	printf("par->n=%d\n",par->n);
	
	/*wyznaczanie liczby funkcji bazowych:
	musi byc spelniony nastepujacy warunek:	nb<L
	gdzie nb- liczba funkcji bazowych,
	      L- polowa parzystej liczby wczytanych punktow */

	if(par->n%2==1) par->n--;
	L=(par->n)/2;

	/*przyjmujemy najwieksza liczbe funkcji bazowych, wtedy 
	aproksymacja jest dokladniejsza: */
	par->nb=L-1;

	/*obliczam a0:*/
        for( k=0; k<=pts->n; k++)
                s+=pts->y[k];
        par->a[0]=s*2/pts->n;

	printf("a0=%f\n", par->a[0]);	
	printf("par->n=%d\n",par->n);
	printf("NB=%d, L=%d\n", par->nb, L);    

	/* Obliczam a1,a2,..anb,b1,b2,...,bnb.*/
	par->b[0]=0;

	for(j=1; j<=par->nb; j++) {
	     s1=0.0;
	     s2=0.0;
//	    printf("j=%d\n",j);
	     for(i=0; i<=2*L-1; i++)   {
		  p=i*j*M_PI/L;
		  s1+=pts->y[i]*cos(p);
		  s2+=pts->y[i]*sin(p);
	//	  printf("s1[%d]=%.2f\t s2[%d]=%.2f\n",i,s1,i,s2);
	     }
	     par->a[j]=s1/L;
	     par->b[j]=s2/L;
	     printf("a%d=%.2f b%d=%.2f\n",j,par->a[j],j,par->b[j]); 
	 }
}	
