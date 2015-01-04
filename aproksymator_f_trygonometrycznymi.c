#include "aproksymator_f_trygonometrycznymi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define M_PI 3.14159265358979323846264338327

double
Oblicz_a0(punkty_t * pts)
{
	double s=0;
	int i;
	for( i=0; i<=pts->n; i++)
		s+=pts->y[i];
	return s/pts->n;
}

void 
	Oblicz_a_b(punkty_t *pts, parametry_funkcji_t *par)
{
	double s1,s2;
	int i,j,L;
	s1=0.0;
	s2=0.0;
	par->n=pts->n;
	printf("par->n=%d\n",par->n);
	par->nb=par->n;
	if(par->n%2==1) par->n--;
	L=(par->n)/2;
	printf("a0=%f\n", par->a0);	
	par->nb=L-1;
 
	printf("NB=%d, L=%d\n", par->nb, L);    
	double p;

	par->a[0]=par->a0;
	par->b[0]=0;

	printf(" NB=%d\n", par->nb);

	for(j=1; j<=par->nb; j++) {
		s1=0.0;
		s2=0.0;
//	    printf("j=%d\n",j);
	    for(i=0; i<=2*L-1; i++)   {
		p=i*j*M_PI/L;
		s1=s1+pts->y[i]*cos(p);
		s2=s2+pts->y[i]*sin(p);
	//	printf("s1[%d]=%.2f\t s2[%d]=%.2f\n",i,s1,i,s2);
	    }
	   par->a[j]=s1/L;
	   par->b[j]=s2/L;
	   printf("a%d=%.2f b%d=%.2f\n",j,par->a[j],j,par->b[j]); 
	}
}	


void
oblicz_parametry(punkty_t * pts, parametry_funkcji_t * par)
{

	double         *x = pts->x;
	double         *y = pts->y;

	par->a0=Oblicz_a0 (pts);

if (alokuj_parametry (par, pts->n) == 0) {
			par->x=x;
			par->f=y;
			Oblicz_a_b(pts, par);
	}
}

