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
    printf("Valor da variável: %d \n",valor);
    printf("Endereço da variável valor: %x \n",&valor);
    printf("Conteudo da variável ponteiro ptr: %x \n",ptr);

    getch();


    return 0;
}
