#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;
float* val;

void llenar_clases(float *d, int *oi, int num, int n){
    int count, j = 0;
    float paso = 1/(float)n, start = 0.0, end = paso;
    for(int i = 0; i < n; i++){
        count = 0;

        while(d[j] >= start && d[j] < end && j <= num){
            count++;
            j++;
        }

        oi[i] = count;
        start = end;
        end += paso;
    }
}

float calculo_chi(int *oi, int n, int ei){
    float x;
    for(int i = 0; i < n; i++){
        x += pow((oi[i] - ei), 2)/ ei;
    }
    return x;
}

void congruencia(){
    //--------------------------------------------------------------------------------------------------
    int semilla, a, c, n, m, x, i = 0;
    float r;

    cout << "Introduce el numero de valores: ";
    cin >> n;

    cout << "Introduce la semilla: ";
    cin >> semilla;

    cout << "Introduce el valor del multiplicador (a): ";
    cin >> a;

    cout << "Introduce el valor del incremento (c): ";
    cin >> c;

    cout << "Introduce el valor del modulo (m): ";
    cin >> m;

    cout << endl;

    x = semilla;

    val = new float[n];

    for (int i = 0; i < n; i++){
        x = ((a * x) + c) % m;
        r = (float)x/(float)m;

        cout << "[ X_" << i + 1 << ": " << x << ". R_" << i + 1 << ": " << r << " ]." << endl;
        val[i] = r;
    }

    cout << endl;
//--------------------------------------------------------------------------------------------------
}

int main(){
    int num, n, ei, gl, count;
    int* oi;
    float a, x, chi;
    printf("\nLLENAR VALORES DE CONGRUENCIA\n");
    congruencia();
    cout << "Introduce el numero de datos: ";
    cin >> num;

    cout << "Introduce el nivel de confianza: ";
    cin >> a;
    
    n = sqrt(num);

    oi = new int[n];

    ei = num/n;
    gl = n - 1;

    sort(val, val + num);

    llenar_clases(val, oi, num, n);

    chi = calculo_chi(oi, n, ei);

    cout << endl << "Clases:\n[ ";
    for(int i = 0; i < n; i++){
        cout << oi[i] << " ";
    }
    cout << "]" << endl;

    cout << endl << "Chi cuadrada: " << chi << "." << endl;
    cout << "Nivel de confianza: " << a << "." << endl;
    cout << "Grados de libertad: " << gl << "." << endl << endl;

    delete [] oi;
    return 0;
}