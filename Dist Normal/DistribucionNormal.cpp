#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;
#define PI 3.14159265


void transformacion(int m, int sigma, float z1, float z2){
    float x1, x2;

    x1 = m + (sigma * z1);
    x2 = m + (sigma * z2);

    cout << "X1 = " << x1 << endl;
    cout << "X2 = " << x2 << endl;
}

void dist_normal(int m, int sigma, float r1, float r2){
    float ln, cs, z1, z2;

    ln = -2 * log(r1);
    cs = cos(2 * PI * (r2 * PI / 180));

    z1 = (pow(ln, 1/2)) * cs;
    z2 = (pow(ln, 1/2)) * cs;

    transformacion(m, sigma, z1, z2);
}

int main(){
    int m, sigma;

    cout << "\nIntroduce el valor medio (m): ";
    cin >> m;

    cout << "\nIntroduce el valor de sigma (sigma): ";
    cin >> sigma;

    float r1 = rand() % 1;
    cout << "\nNúmero aleatorio R1: " << r1 << endl;
    float r2 = rand() % 1;
    cout << "Número aleatorio R2: " << r2 << endl;

    dist_normal(m, sigma, r1, r2);
}