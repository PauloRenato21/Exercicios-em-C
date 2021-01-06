//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //setlocale
#include <string.h> //strcmp -> compara duas strings

//vari�veis Globais
//Constantes
#define CADASTRAR 1
#define QUANTCLIENTES 2
#define LISTRAR 3
#define ATUALIZAR 4
#define PESQUISAR 5
#define EXCLUIR 6
#define SAIR 7

#define MAX_CLIENTES 5

//Vari�veis
//5 clientes
char nome[MAX_CLIENTES][50];
int idade[MAX_CLIENTES];

//Controla a quantidade de clientes
//cadastrados.
int contClientes = 0;

//Prot�tipo das fun��es
int menu();
void direciona(int opcao);
void cadastrar();
void imprime(int posicao);
void listar();
int pesquisar(char nomePesquisa[]);

/*
   ************ fun��o Principal************
No main n�o teremos processamento nenhum.... Apenas manter o
programa funcionando
*/
int main()
{
    int opcao;

    //Permitir o uso de asento e cedilha
    setlocale(LC_ALL, "portuguese");


    do
    {
        /*Chamando a fun��o menu
        e armazenando o retorno */
        opcao = menu();
        direciona(opcao);

    }while(opcao != SAIR);


    return 0;
}

/*
    *****DIRECIONA*****
Receber a op��o desejada do usuario e
direcionar ele para a funcionalidade
*/

void direciona(int opcao)
{
    char nomePesquisa[50];
    int posicao;

    //Analisando op��o desejada
    switch(opcao)
    {
        case CADASTRAR:
            printf("================Cadastrar================\n");

            //Limitar a quantidade de clientes
            //que podem ser cadastrados
            if(contClientes < MAX_CLIENTES)
            {
                cadastrar();
            }
            else
            {
                printf("\n!!!Quantidade m�xima de clientes atingida!!!\n\n");
            }
            break;

        case QUANTCLIENTES:

            break;

        case LISTRAR:
                printf("================ Listar ================\n");
                listar();
            break;

        case ATUALIZAR:

            break;

        case PESQUISAR:
                printf("================ Pesquisar ================\n");

                //Pedindo o nome a ser pesquisado
                printf("Digite um nome:");
                scanf("%s",&nomePesquisa);

                //Verificar se o nome foi encontrado ou n�o
                //if(pesquisar(nomePesquisa) != -1)
                //Preciso armazenar o retorno da fun��o pesquisar
                //porqu� preciso da posi��o para imprimir os dados
                //do cliente caso ele tenha sido encontrado
                posicao = pesquisar(nomePesquisa);
                if(posicao != -1)
                {
                    //Encontrou
                    system("CLS");

                    //Imprimir todos os dados
                    imprime(posicao);
                }
                else
                {
                    printf("\n\nN�o foi poss�vel localizar o nome\n\n");

                }
            break;

        case EXCLUIR:

            break;

        case SAIR:
            printf("Sair do Programa!! \n");

            break;

        default:
            printf("Op��o Inv�lida!! \n");
            break;
    }

    //Pausar a Tela
    system("pause");
}

/*
    ****Cadastrar****
-> Nome
-> Idade
*/
void cadastrar()
{
    char resposta;

    //Pedir e receber todos os dados
    printf("\nNome:");
    scanf("%s",&nome[contClientes]);

    fflush(stdin);

    printf("\nIdade:");
    scanf("%d",&idade[contClientes]);

    fflush(stdin);

    //Limpar a tela
    system("CLS");

    //Imprime todos os dados digitados
    imprime(contClientes);

    //Pedir confirma��o se os dados
    //est�o corretos e realmente deseja
    //cadastrar
    printf("Dados corretos ? (S/N)");
    scanf("%c",&resposta);

    //Verificar se realmente ele deseja
    //cadastrar
    if((resposta == 's') || (resposta == 'S'))
    {
        //Um cliente a mais Cadastrado
        contClientes++;
    }
}
/*
    ****iMPRIME****
Fun��o responsav�l por receber como p�rametro a posi��o
do vetor que dever� ter os dados impresso. N�o receber� nada.
*/
void imprime(int posicao)
 {
     printf("Nome: %s\n",nome[posicao]);
     printf("Idade: %d\n\n",idade[posicao]);
 }

 /*
    ****Listrar****
N�o recebe p�rametro,n�o tem retorno
Fun��o utilizada apenas para listrar todos
os dados de todos os clientes.
 */
void listar()
{
    int cont;

    for(cont = 0;cont < contClientes;cont++)
    {
        //Chamndo a fun��o imprime
        //passando qual a posi��o que
        //deve ser impressa
        imprime(cont);
    }
}

/*
    ****Atualizar****
*/


/*
    ****Pesquisar****
Recebe por p�rametro o nome do cliente a ser
pesquisado e retorna a posi��o que o registro
foi encontrado, ou n�o
*/
int pesquisar(char nomePesquisa[])
{
    int cont;

    for(cont = 0;cont < contClientes;cont++)
    {
        //Verificar se o cliente na posi��o
        //percorrida � aquele que estamos procurando
        //ISSO N�O FUNCIONA
        //if(nome[cont] == nomePesquisa)
        if(strcmp(nome[cont],nomePesquisa) == 0)
        {
            //Retornar a posi��o encontrada
            return cont;
        }
    }

    //N�o encontrou...retorno -1
    return -1;
}


/*
    ****** Menu ******
A fun��o menu ir� exibir as op��es
pegar a op��o desejada e retornar
a op��o desejada
 */

int menu()
{
    int opcao;

    //limpar a tela
    system("CLS");

    printf("%d - Cadastrar Clientes \n", CADASTRAR);
    printf("%d - Exibir quantidade de Clientes \n", QUANTCLIENTES);
    printf("%d - Listrar Clientes \n", LISTRAR);
    printf("%d - Atualizar \n", ATUALIZAR);
    printf("%d - Pesquisar Clientes \n",PESQUISAR);
    printf("%d - Excluir Clintes \n", EXCLUIR);
    printf("%d - Sair do Programa \n", SAIR);

    //Pedir e receber a op��o do usu�rio
    printf("\nOp��o:");
    scanf("%d",&opcao);

    //Limpar o buffer do teclado
    fflush(stdin);

    //limpar a tela
    system("CLS");

    //Retorna a op��o escolhida
    return opcao;

}
