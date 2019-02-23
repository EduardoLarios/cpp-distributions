#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

void bayes(float pa, float paa,  float pab,  float pb, float pba, float pbb, string pa_name, string pb_name, string c1_name, string c2_name){
	float pa_aa = pa * paa, pa_ab = pa * pab;
	float pb_ba = pb * pba, pb_bb = pb * pbb;
	float pA = pa_aa + pb_ba, pB = pa_ab + pb_bb;

	cout << "\nResultados:" << endl;
	// Primer categoría
	cout << "Porcentaje de [ P(A) * P(Aa/A) ]: " << pa_aa << "." << endl;
	cout << "Porcentaje de [ P(A) * P(Ab/A) ]: " << pa_ab << "." << endl;
	cout << "Porcentaje total de " << pa_name << "[ P(A) ]: " << pA << "." << endl;

	// Segunda categoría
	cout << "Porcentaje de [ P(B) * P(Ba/B) ]: " << pb_ba << "." << endl;
	cout << "Porcentaje de [ P(B) * P(Bb/B) ]: " << pb_bb << "." << endl;
	cout << "Porcentaje total de " << pb_name << "[ P(B) ]: " << pB << "." << endl << endl;

	// Teorema de Bayes
	cout << "Porcentaje de " <<  pa_name << "/" << c1_name << " [ P(A/Aa) ]: " << pa_aa / pA << "." << endl;
	cout << "Porcentaje de " <<  pa_name << "/" << c2_name << " [ P(A/Ab) ]: " << pa_ab / pB << "." << endl;
	cout << "Porcentaje de " <<  pb_name << "/" << c1_name << " [ P(B/Ba) ]: " << pb_ba / pA << "." << endl;
	cout << "Porcentaje de " <<  pb_name << "/" << c2_name << " [ P(B/Bb) ]: " << pb_bb / pB << "." << endl;

	cout << endl;
}


int main(){
    float pa, paa, pab;
    float pb, pba, pbb;
    string pa_name, pb_name, c1_name, c2_name;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

    cout << "Nombres:" << endl;

    cout << "Introduce el nombre de la primer categoría [ P(A) ]: ";
    getline(cin, pa_name);

    cout << "\nIntroduce el nombre de la segunda categoría [ P(B) ]: ";
    getline(cin, pb_name);

    cout << "\nIntroduce el nombre de la primer característica [ P(Xa/X) ]: ";
    getline(cin, c1_name);

    cout << "\nIntroduce el nombre de la segunda característica [ P(Xb/X) ]: ";
    getline(cin, c2_name);


    cout << "\nPorcentajes:" << endl;
    cout << "Introduce el porcentaje de " << pa_name << " [ P(A)] : ";
    cin >> pa;
    cout << "\nIntroduce el porcentaje de " <<  c1_name << "/" << pa_name << " [ P(Aa/A) ]: ";
    cin >> paa;
    cout << "\nIntroduce el porcentaje de " << c2_name << "/" <<  pa_name  << " [ P(Ab/A) ]: ";
    cin >> pab;

    cout << "\nIntroduce el porcentaje de " << pb_name << " [ P(B)] : ";
    cin >> pb;
    cout << "\nIntroduce el porcentaje de " << c1_name << "/" << pb_name << " [ P(Ba/B) ]: ";
    cin >> pba;
    cout << "\nIntroduce el porcentaje de " << c2_name << "/" << pb_name << " [ P(Bb/B) ]: ";
    cin >> pbb;

    bayes(pa, paa, pab, pb, pba, pbb, pa_name, pb_name, c1_name, c2_name);
    return 0;
}