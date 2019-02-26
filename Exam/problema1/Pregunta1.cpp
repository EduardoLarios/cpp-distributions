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

float mediana(float data[], int length)
{
    int m, imp;
    float prom;

    if (length % 2 == 1)
    {
        m = (length / 2) + .5;
        return data[m];
    }

    else
    {
        imp = (length / 2);
        prom = (data[imp] + data[imp + 1]) / 2;
        return prom;
    }
}

float promedio(float data[], int length)
{
    float sum = 0.0, avg;
    
    for (int i = 0; i < length; i++)
        sum += data[i];
    avg = sum / length;

    return avg;
}

float varianza(float mean, float data[], int length)
{
    float sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += pow((data[i] - mean), 2);
    }

    return sum / length;
}

float desviacion(float data[], int length)
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    for (int i = 0; i < length; ++i)
    {
        sum += data[i];
    }

    mean = sum / length;

    for (int i = 0; i < length; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / length);
}

int main(int argc, char *argv[])
{
    float data[101], avg, med;
    int seed, a, c, mod, n;

    cout << endl
         << "Linear Congruence:" << endl
         << "==================" << endl;
         
    cout << "Ingresa el valor de la semilla: ";
    cin >> seed;

    cout << "Ingresa el valor de (a): ";
    cin >> a;

    cout << "Ingresa el valor de (c): ";
    cin >> c;

    cout << "Ingresa el valor de modulo: ";
    cin >> mod;

    cout << "Ingresa el numero de elementos: ";
    cin >> n;

    linearGen generator(seed, a, c, mod);

    for (int i = 0; i < n; i++)
    {
        data[i] = generator.rnd();
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = data[i] / 32768;
    }

    sort(data, data + n);
    cout << endl; 
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") " << data[i] << endl;
    }

    cout << endl;
    cout << "Min: " << data[0] << endl;
    cout << "Max: " << data[n-1] << endl;

    med = mediana(data, n);
    avg = promedio(data, n);

    cout << endl;
    cout << "Promedio: " << avg << endl;
    cout << "Mediana: " << med << endl;
    cout << "Varianza: " << varianza(avg, data, n) << endl;
    cout << "Desviacion: " << desviacion(data, n) << endl;
    cout << endl << endl;

    system("pause");

    return 0;
}