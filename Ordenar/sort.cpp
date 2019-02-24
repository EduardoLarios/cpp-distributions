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
