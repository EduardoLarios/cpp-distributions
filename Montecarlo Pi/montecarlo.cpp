
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main()
{
  /* # of points in the 1st quadrant the circle */
  time_t t;
  int i;
  double ms = 0;
  long long int tosses, hits = 0;
  double x, y;
  double z, pi;

  printf("Ingrese el numero de variables para estimar PI: ");
  scanf("%lld", &tosses);

  /* initialize random numbers */
  srand((unsigned)time(&t));

  printf("Starting...\n");
  start_timer();

  //#pragma omp parallel for shared(hits) private(i, x, y, z)
  for (i = 0; i < tosses; i++)
  {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if (z <= 1) hits++;
  }

  ms = stop_timer();

  pi = (double)hits / tosses * 4;
  printf("Numero de variables: %lld\nPi value: %g \n", tosses, pi);
  printf("Tiempo tomado: %.5lf ms\n", ms);

  return 0;

}