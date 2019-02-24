
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

  unordered_map<float, int> counter;

  // To Counter Map

  unordered_map<float, int>::iterator it;
  for (int i = 0; i < size; i++)
  {
    it = counter.find(arrx[i]);
    if (it != counter.end())
    {
      counter[arrx[i]]++;
    }
    else
    {
      counter.insert(pair<float, int>(arrx[i], 1));
    }
  }

  // return pair

  int amount = 0;
  float mean = 0;
  float maxq = -1;
  float elq = -1;

  cout << endl;

  for (it = counter.begin(); it != counter.end(); it++)
  {
    if (it->second > maxq)
    {
      elq = it->first;
      maxq = it->second;
    }
    float f = (float)(it->second) / (float)size;
    cout << "K(Element): " << it->first << " V(Appearance): " << it->second
         << " Relative Frec: " << f << endl;

    mean = mean + (((it->first)) * ((it->second)));
  }

  mean = mean / size;
  sort(arrx, arrx + size);
  float median = 0;

  if (size % 2 != 0)
  {
    median = arrx[size / 2];
  }

  else
  {
    median = (arrx[(size - 1) / 2] + arrx[size / 2]) / 2.0;
  }

  float acumvar = 0;
  for (int i = 0; i < size; i++)
  {
    acumvar = acumvar + ((arrx[i] - mean) * (arrx[i] - mean));
  }

  float var = acumvar / size;
  float stdd = sqrt(var);

  // Kurtosis
  float akur = 0;
  for (int i = 0; i < size; i++)
  {
    akur = akur + (pow((arrx[i] - mean), 4)) / size;
  }

  float k = (akur / (pow(stdd, 4))) - 3;

  // Fisher Pearson
  float askw = 0;
  for (int i = 0; i < size; i++)
  {
    askw = askw + (pow((arrx[i] - mean), 3));
  }

  float skewness = askw / (size * (pow(stdd, 3)));

  int matches = 0;
  for (it = counter.begin(); it != counter.end(); it++)
  {
    if (it->second == maxq)
    {
      matches = matches + 1;
    }
  }

  if (matches == size)
  {
    cout << "\nMode: 0" << endl;
    cout << "If the frecuence is the same for all the elements, the mode is 0\n"
         << endl;
  }

  else
  {
    cout << "\nMode: " << elq << " with an amount of " << maxq << endl;
  }

  cout << "Mean: " << mean << endl;
  cout << "Median: " << median << endl;
  cout << "Variance: " << var << endl;
  cout << "Standard Desviation: " << stdd << endl;
  cout << "Kurtosis : " << k << endl;
  cout << "Skewness : " << skewness << endl;
  cout << "Sorted : ";

  for (int i = 0; i < size; i++)
  {
    cout << arrx[i] << " ";
  }

  cout << endl;
  free(arrx);
}
