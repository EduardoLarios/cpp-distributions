#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float r[5] = {0.3, 0.12, 0.37, 0.09, 0.05}, values[5] = {0.05, 0.09, 0.30, 0.37, 0.12}, fx[5], iN[5], iN_fx[5], i_1n[5], fx_i_1n[5], max1 = 0, max2 = 0, valTab = 0, vals = 5;
	int i = 0;

	printf("Inserta el valor critico de la tabla de Kolmogorov-Smirnov con el que vas a comparar los resultados: ");
	scanf("%f", &valTab);
	
	fx[i] = values[i];
	iN[i] = (i + 1) / vals;

	// Esta es la primera funcion de la que debes obtener el valor max
	// [D+ = MAX[(i/N) - F(Xi)]
	iN_fx[i] = iN[i] - fx[i];
	max1 = iN_fx[i];

	i_1n[i] = 0;

	// Esta es la segunda funcion de la que debes obtener el valor max
	// [D- = MAX[F(Xi) - ((i-1)/N)]
	fx_i_1n[i] = fx[i] - i_1n[i];
	max2 = fx_i_1n[i];

	for (i = 1; i < vals; i++)
	{
		fx[i] = fx[i - 1] + values[i];
		iN[i] = (i + 1) / vals;

		iN_fx[i] = iN[i] - fx[i];
		if (iN_fx[i] > max1)
		{
			max1 = iN_fx[i];
		}

		i_1n[i] = iN[i - 1];

		fx_i_1n[i] = fx[i] - i_1n[i];
		if (fx_i_1n[i] > max1)
		{
			max2 = iN_fx[i];
		}
	}

	// Se comparan los valores maximos de ambas funciones y se guarda el mayor en la variable max1
	if (max2 > max1)
	{
		max1 = max2;
	}

	// Se evalua si max1 es mayor que el valor critico de la tabla de Kolmogorov-Smirnov
	if (max1 < valTab)
	{
		printf("%.3f\n", max1);
		printf("La hipotesis es valida, hay un buen ajuste\n");
	}
	else
	{
		printf("%.3f\n", max1);
		printf("La hipotesis no es valida, no hay un buen ajuste\n");
	}
	return 0;
}
