#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun( double x ) {
                                return 2*cos(x-1)*sin(x+7);
}

int main( int argc, char **argv ) {
                                int n= argc > 1 ? atoi( argv[1] ) : 100;
                                FILE *out= argc > 2 ? fopen( argv[2], "w" ) : stdout;

                         	int a=0;

                                int i;
                                double dx = 3.14*2/n;

                                for( i =0; i < n; i++ ) {
                                                                fprintf( out, "%g %g\n", a+i*dx, fun(a+i*dx) );
                                }
                                fclose( out );

                                return 0;
}
