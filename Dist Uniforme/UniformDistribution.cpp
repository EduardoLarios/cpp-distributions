#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    int i, iterations;
    const int intervals = 10;
    const int nstars = 100; // maximum number of stars to distribute

    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    printf("Numbers to be generated: ");
    scanf("%d", &iterations);

    int p[intervals] = {};

    for (int i = 0; i < iterations; ++i)
    {
        double number = distribution(generator);
        printf("%i): %f\n",i , number * 10);

        ++p[int(intervals * number)];
    }

    cout << "\nUniform Distribution Plot:" << endl;
    cout << fixed;
    cout.precision(1);

    for (int i = 0; i < intervals; ++i)
    {
        cout << (float(i) / intervals) * 10 << "-" << (float(i + 1) / intervals) * 10 << ": ";
        cout << string(p[i] * nstars / iterations, '*') << endl;
    }

    return 0;
}