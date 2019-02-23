// weibull_distribution
#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    const int nstars = 100;   // maximum number of stars to distribute
    int digits, i, iterations;

    default_random_engine generator;
    weibull_distribution<double> distribution(2.0, 4.0);

    int p[10] = {};

    printf("Numbers to be generated: ");
    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i)
    {
        double number = distribution(generator);
        printf("%i): %i\n",i ,(int)number);

        if (number < 10)
            ++p[int(number)];
    }

    cout << "\nWeibull Distribution Plot:" << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << i << "-" << (i + 1) << ": ";
        cout << string(p[i] * nstars / iterations, '*') << endl;
    }

    return 0;
}