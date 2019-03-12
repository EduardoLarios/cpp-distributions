#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  /* # of points in the 1st quadrant the circle */
  time_t t;
  long long int tosses, hits = 0;
  int n;
  double x, y, z, pi;

  printf("Ingrese el numero de variables: ");
  scanf("%lld", &tosses);
  printf("Ingrese el valor de N: ");
  scanf("%i", &n);

  /* initialize random numbers */
  srand((unsigned)time(&t));

  printf("Starting...\n");

  //#pragma omp parallel for shared(hits) private(i, x, y, z)
  for (int i = 0; i < tosses; i++)
  {
    x = (double)rand() / (double)RAND_MAX;
    y = (double)rand() / (double)RAND_MAX;
    z = pow(x, n) + pow(y, n);
    if (z <= 1.0) hits++;
  }

  pi = (double)hits / (double)tosses * 4;
  printf("Numero de variables: %lld\nPi value: %g \n", tosses, pi);

  return 0;

}