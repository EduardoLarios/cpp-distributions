/*

    Copyright 2019 © Ramón Romero @ramonromeroqro
    A01700318 for ITESM
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
#include <unordered_map>
#include <algorithm>
#include <math.h>


long long int linearCong(long long int x, long long int a, long long int c, long long int m){

	//cout << ((x*a)+c) << "/" << m << endl;
    //x = lambda a: -1*(math.log(1-a))/(1) #-ln(1-Ri)/lambda(1) For exponencial distribution values
    //X= a + Ri (b-a)
    // Falta distribucion de Weibull
    //print(x(it))
	return ((x*a)+c)%m;

}

int main(){
	long long int x,a,c,m,s = 0;
	cout << "Input x ->\t";
	cin >> x;
	cout << "Input a ->\t";
	cin >> a;
	cout << "Input c ->\t";
	cin >> c;
	cout << "Input m ->\t";
	cin >> m;
    cout << "Size Array m ->\t";
	cin >> s;
    long long int* arr = (long long int *)calloc(s, sizeof(long long int)); 

    arr[0]=linearCong(x,a,c,m);

    for (int i =1 ; i<s; i++){
        arr[i]=linearCong(arr[i-1],a,c,m);
    }
    for(size_t i = 0; i < s; i++)
    {
        cout<< "Element " << i << " -> " << arr[i] << endl;
        /* code */
    }

    free(arr);
    




    
    
    
	

}
