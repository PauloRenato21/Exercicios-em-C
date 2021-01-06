#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int saldo = 0;

char menu();
void direciona( char opcao);
int saque(int valor);
void saldoConta();
int deposito(int valor);


int main(int argc, char *argv[])
{
	char opcao;

    setlocale(LC_ALL,"Portuguese");

	do
	{
		opcao = menu();
		direciona(opcao);

    }while(opcao != 'd');

	return 0;
}

char menu()
{
    char opcao;

    printf("a - Consultar o saldo \n");
    printf("b - saque \n");
    printf("c - deposito \n");
    printf("d - SAIR \n\n");

    printf("Informe a operação desejada: ");
    scanf("%c",&opcao);

    fflush(stdin);

    system("cls");

    return opcao;

}

void direciona( char opcao)
{
    int valor;
    int retorno;

    switch (opcao)
    {
        case 'a':
            saldoConta();

            printf("\n");
        break;

        case 'b':
            printf("Informe o valor a ser sacado:R$ ");
            scanf("%d",&valor);

            fflush(stdin);

            retorno = saque(valor);

            if(retorno == 1)
            {
                printf("\n");
                printf("!!!! Operação realizada com SUCESSO !!!!");
                printf("\n");

            }
            else
            {
                printf("\n");
                printf("!!!! Operação inválida !!!!!");
                printf("\n");

            }

        break;

        case 'c':
            printf("Informe o valor a ser depositado:R$ ");
            scanf("%d",&valor);

            fflush(stdin);

            retorno = deposito(valor);

            if(retorno == 1)
            {
                printf("\n");
                printf("!!!! Operação realizada com SUCESSO !!!!");
                printf("\n");
            }
            else
            {
                printf("\n");
                printf("!!!! Operação inválida !!!!!");
                printf("\n");
            }

        break;

        case 'd':
            printf("Saindo...\n");

        break;

        default:
            printf("Favor digitar uma escolha valída acima\n\n");
        break;

    }

    system("pause");
    system("cls");
}

int saque(int valor)
{
    if(valor > saldo)
    {
        return 0;
    }
    else
    {
        saldo = saldo - valor;

        return 1;
    }
}

void saldoConta()
{
    printf("O saldo da sua conta é R$:%d",saldo);
    printf("\n");
}

int deposito(int valor)
{
    if(valor > 0)
    {
        saldo = saldo + valor;

        return 1;
    }
    else
    {
        return 0;
    }
}
