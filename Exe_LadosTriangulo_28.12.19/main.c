#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char menu();
void direciona();
void somaPerimetro();
void somaArea();

int main(int argc, char *argv[]) 
{
	char op;
	
	op = menu();
	direciona(op);
	
	return 0;
}

char menu()
{
	char op;
	
	setlocale(LC_ALL,"portuguese"); 
	
	printf("Escolha a opção abaixo para calcular \n\n");
	printf("A> área \n");
	printf("B> perímetro \n\n");
	printf("-> : ");
	scanf("%c",& op);
	
	return op;
}

void direciona(op)
{ 	
	switch(op)
	{
		case 'a':
			somaPerimetro();
		break;
		
		case 'b':
			somaArea();
		break;
	}
	
	return 0;
}

void somaPerimetro()
{
	int cont,lados[3];
	int perimetro;
	
	for(cont=0;cont<=2;cont++)
	{
		printf("\n\n Informe os lados do Triangulo: ");
		scanf("%d",& lados[cont]);
	}
	
	perimetro = lados[0] + lados[1] + lados[2];
	
	printf("\n");
	printf("O perimetro é: %d",perimetro);
}

void somaArea()
{
	int altura,base,area;
	
	setlocale(LC_ALL,"portuguese");
	
	printf("\n Informe a altura do triangulo: ");
	scanf("%d",&altura);
	
	printf("\n Informe a base do triangulo: ");
	scanf("%d",&base);
	
	area = (altura + base) / 2;
	
	printf("\n");
	printf("A area do triangulo é: %d",area);
}
