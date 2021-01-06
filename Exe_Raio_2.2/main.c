#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float raio;

    printf("Informe o raio da esfera:");
    scanf("%f",&raio);

    raio = pow(raio,2)* (4 * 3.14);

    printf("A sua area e: %f",raio);
    printf("\n");

    raio = (4 / 3) * 3.14 * pow(raio,2);

    printf("O seu volume da esfera e: %f",raio);
    printf("\n");

    return 0;
}
