// weibull_distribution
#include <iostream>
#include <random>

using namespace std;

int main()
{
    const int nrolls = 10000; // number of experiments
    const int nstars = 100;   // maximum number of stars to distribute

    default_random_engine generator;
    weibull_distribution<double> distribution(2.0, 4.0);

    int p[10] = {};

    for (int i = 0; i < nrolls; ++i)
    {
        double number = distribution(generator);
        if (number < 10)
            ++p[int(number)];
    }

    cout << "weibull_distribution (2.0,4.0):" << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << i << "-" << (i + 1) << ": ";
        cout << string(p[i] * nstars / nrolls, '*') << endl;
    }

    return 0;
}