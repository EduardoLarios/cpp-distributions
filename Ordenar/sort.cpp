/*
    Copyright 2019 © Ramón Romero @ramonromeroqro
    Description: Starter Template: Numeric and Qualitative Methods, ITESM.
    A01700318 for ITESM
    V210120192300


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
#include <unordered_map>
#include <algorithm>
#include <math.h>

int main(int argc, char **argv)
{
  //	Variables definition ex:10

  int size = 0;

  cout << "Size for array: \n";
  cin >> size;

  float *arrx = (float *)calloc(size, sizeof(int));

  for (int i = 0; i < size; i++)
  {
    cout << "Value for array: \n";
    cin >> arrx[i];
  }

  sort(arrx, arrx + size);

  cout << "Sorted : ";
  for (int i = 0; i < size; i++)
  {
    cout << arrx[i] << " ";
  }
  cout << endl;

  free(arrx);
}
