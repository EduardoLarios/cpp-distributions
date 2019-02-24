

#include <iostream>
using namespace std;

long long int linearCong(long long int x, long long int a, long long int c, long long int modulo)
{
    return ((x * a) + c) % modulo;
}

int main()
{
    long long int x, a, c, modulo, size = 0;
    cout << "Valor de la semilla: ";
    cin >> x;

    cout << "Multiplicador (a): ";
    cin >> a;

    cout << "Multiplicador (c): ";
    cin >> c;

    cout << "Valor del modulo: ";
    cin >> modulo;

    cout << "Numero de valores generados: ";
    cin >> size;

    long long int *arr = (long long int *)calloc(size, sizeof(long long int));

    arr[0] = linearCong(x, a, c, modulo);

    for (int i = 1; i < size; i++)
    {
        arr[i] = linearCong(arr[i - 1], a, c, modulo);
    }

    cout << "---- Valores Generados ----" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << i << ") " << arr[i] << endl;
    }

    free(arr);
}
