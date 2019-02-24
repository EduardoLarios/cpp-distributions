#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    int i, iterations;
    const int stars = 100;    // maximum number of stars to distribute
    const int intervals = 10; // number of intervals

    default_random_engine generator;
    exponential_distribution<double> distribution(3.5);

    printf("Numbers to be generated: ");
    scanf("%d", &iterations);

    int p[intervals] = {};

    for (int i = 0; i < iterations; ++i)
    {
        double number = distribution(generator);
        printf("%i): %f\n", i, number);
        if (number < 1.0)
            ++p[int(intervals * number)];
    }

    cout << "\nExponential Distribution Plot:" << endl;
    cout << fixed;
    cout.precision(1);

    for (int i = 0; i < intervals; ++i)
    {
        cout << float(i) / intervals << "-" << float(i + 1) / intervals << ": ";
        cout << string(p[i] * stars / iterations, '*') << endl;
    }

    return 0;
}