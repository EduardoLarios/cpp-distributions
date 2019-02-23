/*

    Copyright 2019 
    © Ramón Romero @ramonromeroqro
    © Eduardo Larios @EduardoLarios
    A01700318 | A00569364 for ITESM CQ
    C++ - Random Integer Generator - Linear Congruence
    V050220191400

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

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
