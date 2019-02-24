#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

long long int linearCong(long long int x, long long int a, long long int c, long long int m){

	return ((x*a)+c)%m;

}

int main(){
	long long int x,a,c,m = 0;
	cout << "Input x ->\t";
	cin >> x;
	cout << "Input a ->\t";
	cin >> a;
	cout << "Input c ->\t";
	cin >> c;
	cout << "Input m ->\t";
	cin >> m;



    long long int arr[101]={};
    arr[0]=linearCong(x,a,c,m);

    for (int i =1 ; i<101; i++){
        arr[i]=linearCong(arr[i-1],a,c,m);
    }

    int j=10;
    while(j<101){
        cout << j <<": "<<arr[j]   << endl;
        j=j+10;
    }

    sort(arr, arr + 101);
    float median = 0;

    if (101 % 2 != 0) {
    median = arr[101 / 2];
    } else {
    median = (arr[(101 - 1) / 2] + arr[101 / 2]) / 2.0;
    }

    cout << "Mediana: " << median<< endl;
    long long int s=0;
    for (int i=0; i<101;i++){
        s=s+arr[i];
    }
    double promedio=s/101;
    cout << "promedio: " << promedio<< endl;

    cout << "max: " << arr[100]<< endl;
    cout << "min: " << arr[0]<< endl;



  double acumvar = 0;
  for (int i = 0; i < 101; i++) {
    acumvar = acumvar + ((arr[i] - promedio) * (arr[i] - promedio));
  }
  double var = acumvar / 101;
  double stdd = sqrt(var);
  cout << "std: " << arr[0]<< endl;




    
    
    
	

}
