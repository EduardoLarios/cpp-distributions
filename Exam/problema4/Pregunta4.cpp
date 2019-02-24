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

        if (distance_squared <= 1)
        {
            number_in_circle++;
        }
    }

    long double acum = number_in_circle / ((double)number_of_tosses);
    
    return acum;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int number_of_tosses = 1;
    int maxiter = 1;
    int i = 0;
    long double acum = 0;
    
    cout << "Ingresar Limite de Iteraciones: " << endl;
    cin >> maxiter;

    while (number_of_tosses <= maxiter)
    {
<<<<<<< HEAD
        
        acum = montecarlo(number_of_tosses);

        printf("%i iterations: %Lf  \n", number_of_tosses, acum);
=======
        for (i = 0; i < N; i++)
        {
            pi = montecarlo(number_of_tosses);
        }
        printf("%i (N) -> Resultados: %Lf  \n", number_of_tosses + 1, pi);
>>>>>>> a3efb15e612807fa84421c931f17e88bf6c3c2fd
        number_of_tosses = number_of_tosses + 1;
    }

    return 0;
}