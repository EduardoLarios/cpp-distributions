

/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* sqrt */
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <math.h>


double genRandomTriangular(double min, double mode, double max){
    double lower = mode - min;
    double higher = max - min;
    double total = max - min;
    double acumProb=0;
    double randTriang=0; 
    srand (time(NULL));
    acumProb  = ((double) rand() / (RAND_MAX));
    if (acumProb < (lower / total)){
        randTriang = min + sqrt(acumProb * lower * total);
    }else{
        randTriang = max - sqrt((1 - acumProb) * higher * total);

    }
    return randTriang;

}

int main(){

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
    //cout << "K(Element): " << it->first << " V(Appearance): " << it->second << " Relative Frec: " << f << endl;

    mean = mean + (((it->first)) * ((it->second)));
  }

  mean = mean / size;
  sort(arrx, arrx + size);
  float median = 0;


  int matches = 0;
  for (it = counter.begin(); it != counter.end(); it++)
  {
    if (it->second == maxq)
    {
      matches = matches + 1;
    }
  }

double modevalue=0;
  if (matches == size)
  {
      
    // cout << "\nMode: 0" << endl;
    // cout << "If the frecuence is the same for all the elements, the mode is 0\n"
    //      << endl;
    modevalue=0;
  }else{
    //cout << "\nMode: " << elq << " with an amount of " << maxq << endl;
    modevalue=maxq;
  }

  cout << "Numero gen por distribucion triangular: " << genRandomTriangular(arrx[0], modevalue, arrx[size-1]) << endl;

    
  free(arrx);
  // https://www.mrexcel.com/forum/excel-questions/980241-how-produce-random-number-triangular-distribution.html


}
