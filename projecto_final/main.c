#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu_gestao_consumos () { // este vai ser o menu principal, que ser� apresentado ao utilizador quando ele abre o programa
	
int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf("Menu Gest�o de Consumos: \n");
	printf("Escolha uma das seguintes opcoes: \n");
	printf("Gestao clientes -> prima tecla 1 \n");
	printf("Gestao consumos -> prima tecla 2 \n");
	printf("consultar base de dados -> prima tecla 3 \n");
	printf("alterar base de dados -> prima tecla 4 \n");
	printf("Sair -> prima tecla 5 \n");
	printf("======================================\n");
	do {

			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>4);
	
	switch (escolha) {
	case 1:
		system("cls");
		//menu_gestao_clientes();
		break;
	case 2:
		system("cls");
		//menu_gestao_consumos();
		break;
	case 3:
		system("cls");
		//menu_consultas_bd();
		break;
	case 4:
		system("cls");
		//menu_ficheiros();
		break;
	default:
		system("cls");
		printf("o valor introduzido n�o � v�lido!");
		break;
	}
}

while (escolha != 5);


	
	
}


void menu_principal () { // este vai ser o menu principal, que ser� apresentado ao utilizador quando ele abre o programa
	
int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf("bem vindo: \n");
	printf("escolha uma das seguintes opcoes: \n");
	printf("Gestao clientes -> prima tecla 1 \n");
	printf("Gestao consumos -> prima tecla 2 \n");
	printf("consultar base de dados -> prima tecla 3 \n");
	printf("alterar base de dados -> prima tecla 4 \n");
	printf("Sair -> prima tecla 5 \n");
	printf("======================================\n");
	do {

			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>4);
	
	switch (escolha) {
	case 1:
		system("cls");
		//menu_gestao_clientes();
		break;
	case 2:
		system("cls");
		//menu_gestao_consumos();
		break;
	case 3:
		system("cls");
		//menu_consultas_bd();
		break;
	case 4:
		system("cls");
		//menu_ficheiros();
		break;
	default:
		system("cls");
		printf("o valor introduzido n�o � v�lido!");
		break;
	}
}

while (escolha != 5);


	
	
}
int main(int argc, char *argv[]) {
	
	menu_principal();
	return 0;
}

