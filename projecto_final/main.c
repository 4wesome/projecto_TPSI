#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu_gestao_clientes() {// este é o menu que será apresentado ao utilizador. aqui ele ira puder gerir os clientes (adicionar, editar, remover, e listar)
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");

	printf("escolha uma das seguintes opcoes: \n");
	printf("Novo -> prima tecla 1 \n");
	printf("Editar -> prima tecla 2 \n");
	printf("Remover -> prima tecla 3 \n");
	printf("listar -> prima tecla 4 \n");
	printf("voltar atras -> prima tecla 5 \n");
	printf("======================================\n");
	do {

			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>5);
	
	switch (escolha) {
	case 1:
		system("cls");
		//novo_cliente();
		break;
	case 2:
		system("cls");
		//editar_cliente();
		break;
	case 3:
		system("cls");
		//remover_cliente();
		break;
	case 4:
		system("cls");
		//listar_cliente();
		break;
	case 5:
		system("cls");
		menu_principal();
	default:
		system("cls");
		printf("o valor introduzido não é válido!");
		break;
	}
}

while (escolha != 5);
	
}


void menu_principal () { // este vai ser o menu principal, que será apresentado ao utilizador quando ele abre o programa
	
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
		menu_gestao_clientes();
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
		printf("o valor introduzido não é válido!");
		break;
	}
}

while (escolha != 5);
		
}
int main(int argc, char *argv[]) {
	
	menu_principal();
	return 0;
}

