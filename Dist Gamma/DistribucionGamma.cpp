#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;


float aceptacion_rechazo(float a, float b, int beta){
    float r1, r2, v, x, op;
    bool bandera = false;
    do{
        r1 = rand() % 1;
        cout << "Número aleatorio R1: " << r1 << endl;
        r2 = rand() % 1;
        cout << "Número aleatorio R2: " << r2 << endl;
        v = r1/(1 - r1);
        x = beta * pow(v, a);

        op = b + (((beta * a) + 1) * log (v)) - log(pow(r1, 2) * r2);
        if(x <= op){
            bandera = true;
        }
    } while(!bandera);

    return x;
}
int main(){
    int beta, th;

    cout << "Introduce el valor de Beta: ";
    cin >> beta;

    cout << "\nIntroduce el valor de Theta: ";
    cin >> th;

    float a = 1 / pow((2 * beta - 1), 1/2);
    float b = beta - log(4);

    float x = aceptacion_rechazo(a, b, beta);

    cout << "Media = " << 1/th << endl;
    cout << "Varianza = " << 1/(beta * pow(th, 2)) << endl;

    cout << "x = " << x << endl;
    cout << "x/(beta * theta) = " << (x/(beta * th)) << endl << endl;
}