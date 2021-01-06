//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //setlocale("portuguese") e ("C")

//Vari�veis Globais
//Constante
//Define para controlar a quantidade de alunos que seram inseridas
#define QUANTI_ALUNO 1


// struct para defini��o da disciplina
typedef struct
{
	// Quantidade de caracteres para os nomes
	//das mat�rias
	char nome[50];
	 
	//Quantidades de notas 
	//a serem armazenadas 
	int notas[4];  
	
} disciplina; //nome do tipo da struct 


//struct para defini��o do aluno 
typedef struct
{
	// Quantidade de caracteres para os nomes
	//dos alunos
	char nome[50];
	
	//Quantidade de disciplinas a serem cadastradas
	// Disciplinas recebe a struct Disciplina
	disciplina disciplinas[2];
	
} aluno; //nome do tipo da struct


//Vari�vel para o tipo da struct
//no caso a struct aluno 
aluno alunos[QUANTI_ALUNO];


//Prototipos
int menu();
void direciona(int opcao);
void operacao();
void soma();


int main(int argc, char *argv[]) 
{
	int opcao;
	
	setlocale(LC_ALL, "portuguese");
	
	do
	{
		//Para mudar a cor das letras na tela de comando
		//no caso para um branco mais forte.
		system("color 0F");
		
		
		opcao = menu();
		direciona(opcao);
			
	}while(opcao != 3);
	
	return 0;
}

/*
	****Menu****
Fun��o que mostra as op��es e pede
a op��o desejada
*/
int menu()
{
	int op;
	

	
	//Limpa tela
	system("CLS");
	
	printf(" ####################################\n");
	printf("# 1 - Cadastrar alunos e as mat�rias #\n");
	printf("# 2 - Resultado das notas            #\n");
	printf("# 3 - Sair                           #\n");
	printf(" ####################################\n\n");
	
	printf("-> Op��o desejada: ");
	scanf("%d",&op);
	
	fflush(stdin);
	
	system("CLS");
	
	//retorna a op��o que foi escolhida
	return op;
}


/*
	****Direciona****
Fun��o para direcionar a op��o em que 
o usu�rio escolheu na fun�a� anterior
*/
void direciona(int opcao)
{
	setlocale(LC_ALL, "portuguese");
	
	switch(opcao)
	{
		case 1:
			operacao();
		break;
		
		case 2:
			 soma();
			 system("pause");
		break;
		
		case 3:
			printf(" #####################\n");
			printf("# Obrigado at� logo!! #\n");
			printf(" ##################### \n");
		break;
		
		//Caso nenhuma das op��es do menu seja
		//escolhida
		default:
			printf(" ################################### \n");
			printf("# Favor selecionar uma Op��o Val�da # \n");
			printf(" ################################### \n\n");
			system("pause");
		break;
		
	}
}

/*
	******Opera��o******
Pede o nome do aluno e a mat�ria a ser cadastrada e armazena na
struct aluno.
E faz a valida��o da nota.
*/
void operacao()
{	

	int contAluno,contDisciplina,contNota,nota;
	
		
	printf(" ######################################################\n");
	printf("# Informe o nome do aluno e as notas de cada Bimestre  #\n");
	printf(" ######################################################\n\n");
	
	//La�o para armazenar o nome do aluno 
	//na struct aluno		
	for(contAluno=0;contAluno <= QUANTI_ALUNO;contAluno++)
	{
				
		printf("> Nome do aluno.....: ");
		
		/* Chama a vari�vel alunos do tipo aluno
		pelo variav�l, o n�mero de caracteres
		e por onde est� vindo esse comando no 
		caso o teclado(stdin) */
		fgets(alunos[contAluno].nome,50,stdin);
		
		
		//Limpar o buffer do teclado
		fflush(stdin);
	
	
		printf("\n");
		
		//la�o para armazenar a materia e a nota 
		//na struct aluno na vari�vel disciplinas
		for(contDisciplina=0;contDisciplina <=1;contDisciplina++)
		{
			
			printf("> Informe a materia....: ");
			
			//Armazena a mat�ria digitada
			fgets(alunos[contAluno].disciplinas[contDisciplina].nome,50,stdin);
			
			fflush(stdin);
			
			//Limpar a Tela
			system("CLS");
			
			for(contNota=0;contNota <=3;contNota++)
			{
				//Validando a nota digitada
				do 
				{ 
					setlocale(LC_ALL, "Portuguese");
					
					printf("-> Informe as notas do %d� Bimestre....: ",contNota+1);	
					scanf("%d",&nota);
					
					fflush(stdin);
					
					system("ClS");
				
					if(nota < 0 || nota > 25 )
					{
						printf(" ###############################################\n");
						printf("# !!!!! Favor informar notas entre 0 e 25 !!!!! # \n");
						printf(" ############################################### \n\n");
					} 
					
				
				}while(nota < 0 || nota > 25 );
				
				//A nota passa para a vari�vel alunos que � do tipo aluno
				//e armazena as notas nas posi��es do vetor notas com o la�o
				//de repeti��o
				alunos[contAluno].disciplinas[contDisciplina].notas[contNota] = nota;
			}
		}
	}
}

//Fun��o para somar todas as notas da materia escolhida e aparecer na tela
void soma()
{
	
	int totalFinal,contAlunos,contDisciplina;
	
	//La�o para imprimir os nomes dos alunos em suas posi��es
	//no vetor.
	for(contAlunos=0;contAlunos <= QUANTI_ALUNO;contAlunos++)
	{	
		//la�o para imprimir os nomes das mat�rias
		for(contDisciplina=0;contDisciplina <=1;contDisciplina++)
		{	
			
			 //Escrito o conte�do de uma vari�vel com caracteres especiais 
			setlocale(LC_ALL, "C");
			
			printf("\n");
			printf("-> Aluno....: %s",alunos[contAlunos].nome);
			
			//Opera��o para juntar as notas de todos os bimestres
			//e passar para a vari�vel.
			totalFinal = (alunos[contAlunos].disciplinas[contDisciplina].notas[0] + alunos[contAlunos].disciplinas[contDisciplina].notas[1] + alunos[contAlunos].disciplinas[contDisciplina].notas[2] + alunos[contAlunos].disciplinas[contDisciplina].notas[3]);
			
			
			setlocale(LC_ALL, "C");
			
			//Condi��es para saber se o aluno est� de Recupera��o,
			//Reprovado ou Aprovado.
			if(totalFinal >= 60)
			{
				printf("O seu total em %sfoi de: %d pontos.",alunos[contAlunos].disciplinas[contDisciplina].nome,totalFinal);
				
				setlocale(LC_ALL, "Portuguese");
				
				printf("Voc� est� APROVADO!!! \n\n");
				
				printf(">----------------------------------------------");
				printf("\n");
			}
			
			else if(totalFinal >=45 && totalFinal < 60)
			{
				printf("O seu total em %sfoi de: %d pontos.",alunos[contAlunos].disciplinas[contDisciplina].nome,totalFinal);
				
				setlocale(LC_ALL, "Portuguese");
				
				printf("Voc� est� de RECUPERA��O!!! \n\n");
				
				printf(">----------------------------------------------");
				printf("\n");
			}
			
			else
			{	
				printf("O seu total em %sfoi de: %d pontos.",alunos[contAlunos].disciplinas[contDisciplina].nome,totalFinal);
				
				setlocale(LC_ALL, "Portuguese");
				
				printf("Voc� foi REPROVADO!!! \n\n");
				
				printf(">----------------------------------------------");
				printf("\n");
			}
		}
	}
}
