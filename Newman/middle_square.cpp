#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*Generating Random Number of desired digit*/
unsigned long long int randm(int digits)

{
    double seed;
    unsigned long long int y;

    srand(time(NULL));
    seed = rand() / (double)RAND_MAX;
    y = (unsigned long long int)(seed * pow(10.0, digits * 1.0));

    return y;
}

/*Calculating Random Number By Von Neumann Middle Square method*/
unsigned long long int middle_square(unsigned long long int seed, int digits)
{
    unsigned long long int y;
    int k;

    k = digits / 2;
    y = (unsigned long long int)((seed / pow(10.0, k * 1.0)) * seed) % (unsigned long long int)(pow(10.0, digits * 1.0));

    return y;
}

int main(void)
{
    unsigned long long int seed, val;
    int digits, i, iterations;

    printf("Input seed: ");
    scanf("%lld", &seed);

    printf("Digits in the seed value: ");
    scanf("%d", &digits);

    printf("Numbers to be generated: ");
    scanf("%d", &iterations);
    printf("\n");

    if (digits > 11)
    {
        printf("The seed is too big");
        exit(0);
    }

    for (i = 0; i < iterations; i++)
    {
        val = middle_square(seed, digits);
        seed = val;
        printf("%i): %lld\n",i, val);
    }

    return 0;
}
