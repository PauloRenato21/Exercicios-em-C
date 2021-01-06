//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //setlocale
#include <string.h> //strcmp -> compara duas strings

//variáveis Globais
//Constantes
#define CADASTRAR 1
#define QUANTCLIENTES 2
#define LISTRAR 3
#define ATUALIZAR 4
#define PESQUISAR 5
#define EXCLUIR 6
#define SAIR 7

#define MAX_CLIENTES 5

//Variáveis
//5 clientes
char nome[MAX_CLIENTES][50];
int idade[MAX_CLIENTES];

//Controla a quantidade de clientes
//cadastrados.
int contClientes = 0;

//Protótipo das funções
int menu();
void direciona(int opcao);
void cadastrar();
void imprime(int posicao);
void listar();
int pesquisar(char nomePesquisa[]);

/*
   ************ função Principal************
No main não teremos processamento nenhum.... Apenas manter o
programa funcionando
*/
int main()
{
    int opcao;

    //Permitir o uso de asento e cedilha
    setlocale(LC_ALL, "portuguese");


    do
    {
        /*Chamando a função menu
        e armazenando o retorno */
        opcao = menu();
        direciona(opcao);

    }while(opcao != SAIR);


    return 0;
}

/*
    *****DIRECIONA*****
Receber a opção desejada do usuario e
direcionar ele para a funcionalidade
*/

void direciona(int opcao)
{
    char nomePesquisa[50];
    int posicao;

    //Analisando opção desejada
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
                printf("\n!!!Quantidade máxima de clientes atingida!!!\n\n");
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

                //Verificar se o nome foi encontrado ou não
                //if(pesquisar(nomePesquisa) != -1)
                //Preciso armazenar o retorno da função pesquisar
                //porquê preciso da posição para imprimir os dados
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
                    printf("\n\nNão foi possível localizar o nome\n\n");

                }
            break;

        case EXCLUIR:

            break;

        case SAIR:
            printf("Sair do Programa!! \n");

            break;

        default:
            printf("Opção Inválida!! \n");
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

    //Pedir confirmação se os dados
    //estão corretos e realmente deseja
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
Função responsavél por receber como pârametro a posição
do vetor que deverá ter os dados impresso. Não receberá nada.
*/
void imprime(int posicao)
 {
     printf("Nome: %s\n",nome[posicao]);
     printf("Idade: %d\n\n",idade[posicao]);
 }

 /*
    ****Listrar****
Não recebe pârametro,não tem retorno
Função utilizada apenas para listrar todos
os dados de todos os clientes.
 */
void listar()
{
    int cont;

    for(cont = 0;cont < contClientes;cont++)
    {
        //Chamndo a função imprime
        //passando qual a posição que
        //deve ser impressa
        imprime(cont);
    }
}

/*
    ****Atualizar****
*/


/*
    ****Pesquisar****
Recebe por pârametro o nome do cliente a ser
pesquisado e retorna a posição que o registro
foi encontrado, ou não
*/
int pesquisar(char nomePesquisa[])
{
    int cont;

    for(cont = 0;cont < contClientes;cont++)
    {
        //Verificar se o cliente na posição
        //percorrida é aquele que estamos procurando
        //ISSO NÃO FUNCIONA
        //if(nome[cont] == nomePesquisa)
        if(strcmp(nome[cont],nomePesquisa) == 0)
        {
            //Retornar a posição encontrada
            return cont;
        }
    }

    //Não encontrou...retorno -1
    return -1;
}


/*
    ****** Menu ******
A função menu irá exibir as opções
pegar a opção desejada e retornar
a opção desejada
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

    //Pedir e receber a opção do usuário
    printf("\nOpção:");
    scanf("%d",&opcao);

    //Limpar o buffer do teclado
    fflush(stdin);

    //limpar a tela
    system("CLS");

    //Retorna a opção escolhida
    return opcao;

}
