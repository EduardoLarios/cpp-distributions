#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>       // std::vector
#include <unordered_map>
#include <cmath>
//--------------------------------------------------------------------------------------------------
using namespace std;
 
//--------------------------------------------------------------------------------------------------
class mRND
{
public:
    void seed( unsigned int s ) { _seed = s; }
 
protected:
    mRND() : _seed( 1260 ), _a( 15245 ), _c( 27893 ), _m( 32768 ) {}
    int rnd() { return( _seed = ( _a * _seed + _c ) % _m ); }
 
    int _a, _c;
    unsigned int _m, _seed;
};
//--------------------------------------------------------------------------------------------------
class MS_RND : public mRND
{
public:
    MS_RND()  { _a = 15245; _c = 27893; }
    int rnd() { return mRND::rnd() >> 16; }
};
//--------------------------------------------------------------------------------------------------
class BSD_RND : public mRND
{
public:
    BSD_RND() { _a = 15245; _c = 27893; }
    int rnd() { return mRND::rnd(); }
};
//--------------------------------------------------------------------------------------------------
void swap(float *xp, float *yp) { 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(float arr[], int n) { 
   int i, j; 
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
               swap(&arr[j], &arr[j+1]); 
           }               
       }   
   }           
} 
void mediana(float arr[], int size){
    int m,imp;
    float prom;

    if (size%2==1){
        m = (size/2)+.5;
        printf("\nMediana: %.1f",arr[m]);

    }else{
        imp= (size/2);
        prom = (arr[imp] + arr[imp+1])/2;
        printf("\nMediana: %.1f\n", prom);    
    }
}
void promedio(float num[]){
    int n, i;
    float sum = 0.0, avg;
    
    n = 101;
    for(i = 0; i < n; i++)
        sum += num[i];
    avg = sum / n;
    cout<<"\nPromedio: "<<avg;
}
float calculateSD(float data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < 101; ++i)
    {
        sum += data[i];
    }

    mean = sum/101;

    for(i = 0; i < 101; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 101);
}

int main( int argc, char* argv[] )
{
    BSD_RND bsd_rnd;
    MS_RND ms_rnd;
    float arr[101];

 
    cout << endl  << "BSD RAND:" << endl << "=========" << endl;
    for( int x = 0; x < 101; x++ ){
        arr[x]=bsd_rnd.rnd();
    }
    for( int x = 0; x < 101; x++ ){
        arr[x]=arr[x]/32768;
    }
    bubbleSort(arr,101);
    for( int x = 0; x < 101; x++ ){
	    cout << x+1 << " "<<arr[x] << endl;
    
    }
    cout<< endl;
    cout<<"Min: "<<arr[0]<<endl;
    cout<<"Max: "<<arr[100]<< endl;
    mediana(arr,101);
    promedio(arr);
    cout<< endl;
    cout<<"SD:"<< calculateSD(arr);
    cout << endl << endl;
    system( "pause" );
    return 0;
}