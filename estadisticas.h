#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
// Métodos Estadísticos
float promedio(float *nums, int length)
{
    float sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += nums[i];
    }

    return sum / length;
}

float mediana(int length, float *nums)
{
    if (length % 2 == 0)
    {
        return (nums[(length - 1) / 2] + nums[length / 2]) / 2;
    }
    return nums[length / 2];
}

float moda(int length, float *nums)
{
    float num = nums[0], moda = num;
    float cont = 1, contModa = 1;

    for (int i = 0; i < length; i++)
    {
        if (nums[i] == num)
        {
            ++cont;
        }
        else
        {
            if (cont > contModa)
            {
                contModa = cont;
                moda = cont;
            }
            cont = 1;
            num = nums[i];
        }
    }

    return moda;
}

float varianza(int length, float mean, float *nums)
{
    float sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += pow((nums[i] - mean), 2);
    }

    return sum / length;
}

float desviacion(float varianza)
{
    return sqrt(varianza);
}

float oblicuidad(int length, float mean, float s, float *nums)
{
    float sum = 0;
    float s3 = pow(s, 3);
    for (int i = 0; i < length; i++)
    {
        sum += pow((nums[i] - mean), 3);
    }

    return sum / (length * s3);
}

float curtosis(int length, float mean, float s, float *nums)
{
    float sum = 0;
    float s4 = pow(s, 4);
    for (int i = 0; i < length; i++)
    {
        sum += pow((nums[i] - mean), 4);
    }

    return (sum / (length * s4)) - 3;
}

void ordenar(float *nums, int lenght)
{
    return sort(nums, nums + lenght);
}