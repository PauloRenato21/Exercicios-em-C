#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int valor = 100;

    int *ptr;

    ptr = &valor;

    setlocale(LC_ALL,"portuguese");

    printf("Ponteiros\n\n");
    printf("Valor da vari�vel: %d \n",valor);
    printf("Endere�o da vari�vel valor: %x \n",&valor);
    printf("Conteudo da vari�vel ponteiro ptr: %x \n",ptr);

    getch();


    return 0;
}
