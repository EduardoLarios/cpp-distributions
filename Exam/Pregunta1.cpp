#include <stdio.h>
#include <iostream>  
#include <algorithm> 
#include <vector>    
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

class linearGen
{
  public:
    int _a, _c;
    unsigned int modulo, _seed;

    linearGen(int seed, int a, int c, int mod) : _seed(seed), _a(a), _c(c), modulo(mod) {}
    int rnd()
    {
        return (_seed = (_a * _seed + _c) % modulo);
    }
};

void mediana(float arr[], int size)
{
    int m, imp;
    float prom;

    if (size % 2 == 1)
    {
        m = (size / 2) + .5;
        printf("\nMediana: %.1f", arr[m]);
    }

    else
    {
        imp = (size / 2);
        prom = (arr[imp] + arr[imp + 1]) / 2;
        printf("\nMediana: %.1f\n", prom);
    }
}

void promedio(float num[])
{
    int n, i;
    float sum = 0.0, avg;

    n = 101;
    for (i = 0; i < n; i++)
        sum += num[i];
    avg = sum / n;
    cout << "\nPromedio: " << avg;
}

float calculateSD(float data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;

    for (i = 0; i < 101; ++i)
    {
        sum += data[i];
    }

    mean = sum / 101;

    for (i = 0; i < 101; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 101);
}

int main(int argc, char *argv[])
{
    float arr[101];
    int seed, a, c, mod;

    cout << endl
         << "Linear Congruence:" << endl
         << "=========" << endl;
    cout << "Ingresa el valor de la semilla: ";
    cin >> seed;

    cout << "Ingresa el valor de (a): ";
    cin >> a;

    cout << "Ingresa el valor de (c): ";
    cin >> c;

    cout << "Ingresa el valor de modulo: ";
    cin >> mod;

    linearGen generator(seed, a, c, mod);

    for (int x = 0; x < 101; x++)
    {
        arr[x] = generator.rnd();
    }

    for (int x = 0; x < 101; x++)
    {
        arr[x] = arr[x] / 32768;
    }

    sort(arr, arr + 101);

    for (int x = 0; x < 101; x++)
    {
        cout << x + 1 << ") " << arr[x] << endl;
    }

    cout << endl;
    cout << "Min: " << arr[0] << endl;
    cout << "Max: " << arr[100] << endl;

    mediana(arr, 101);
    promedio(arr);

    cout << endl;
    cout << "Deviation: " << calculateSD(arr);
    cout << endl << endl;

    system("pause");

    return 0;
}