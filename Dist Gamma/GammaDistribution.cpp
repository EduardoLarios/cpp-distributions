#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    int i, iterations;
    const int nstars = 100; // maximum number of stars to distribute

    default_random_engine generator;
    gamma_distribution<double> distribution(2.0, 2.0);

    printf("Numbers to be generated: ");
    scanf("%d", &iterations);

    int p[10] = {};

    for (int i = 0; i < iterations; ++i)
    {
        double number = distribution(generator);
        printf("%i): %f\n", i, number);
        if (number < 10)
            ++p[int(number)];
    }

    cout << "\nGamma Distribution Plot:" << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << i << "-" << (i + 1) << ": ";
        cout << string(p[i] * nstars / iterations, '*') << endl;
    }

    return 0;
}