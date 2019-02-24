#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#define N 1

using namespace std;

long double montecarlo(int number_of_tosses)
{
    int number_in_circle = 0;
    int toss;

    for (toss = 0; toss < number_of_tosses; toss++)
    {
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0; //float in range -1 to 1
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0; //float in range -1 to 1
        double distance_squared = pow(x, toss) + pow(y, toss);
        //printf("%f - %f\n", x,y);
        if (distance_squared <= 1)
        {
            number_in_circle++;
        }
    }

    long double pi = number_in_circle / ((double)number_of_tosses);
    return pi;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int number_of_tosses = 1;
    int maxiter = 1;
    cout << "Ingresar Limite de Iteraciones:" << endl;
    cin >> maxiter;

    int i = 0;

    printf("starting...\n");
    long double pi = 0;
    while (pi != 3.14159 && number_of_tosses <= maxiter)
    {
        for (i = 0; i < N; i++)
        {
            pi = montecarlo(number_of_tosses);
        }
        printf("%i iterations  (N) -> Pi: %Lf  \n", number_of_tosses + 1, pi);
        number_of_tosses = number_of_tosses + 1;
    }
    //printf("%Lf\n", pi);
    //printf("%i", number_of_tosses);

    return 0;
}