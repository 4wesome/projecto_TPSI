#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */




void menu_ficheiros() {// este é o menu que será apresentado ao utilizador. aqui ele ira ler e gravar dados na base de dados
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu Consultas da Base de Dados\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Ler Base de Dados \n");
	printf(" 2 - Gravar Alteracoes \n");
	printf(" 3 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>3);
	
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

		break;
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 3");
		break;
	}
}

while (escolha != 3);
	
}

void menu_pesquisas() {// este é o menu que será apresentado ao utilizador. aqui ele ira pesquisar por varios parametros
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu Consultas\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Pesquisar Cliente por Codigo \n");
	printf(" 2 - Pesquisar Cliente por Nome \n");
	printf(" 3 - Pesquisar Consumo por Codigo \n");
	printf(" 4 - Pesquisar Consumo por Codigo de Cliente \n");
	printf(" 5 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
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
		//editar_cliente();
		break;
	case 4:
		system("cls");
		//editar_cliente();
		break;
	case 5:
		system("cls");

		break;
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 5");
		break;
	}
}

while (escolha != 5);
	
}

void menu_consultas() {// este é o menu que será apresentado ao utilizador. aqui consulta clientes por consumo e os que nao pagaram
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu Consultas\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Listar Clientes por Consumo \n");
	printf(" 2 - Listar Clientes que nao pagaram \n");
	printf(" 3 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>3);
	
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

		break;
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 3");
		break;
	}
}

while (escolha != 3);
	
}

void menu_consultas_bd() {// este é o menu que será apresentado ao utilizador. aqui faz as consultas a BD (consulta e pesquisa)
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu Consultas da Base de Dados\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Consulta \n");
	printf(" 2 - Pesquisa \n");
	printf(" 3 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>3);
	
	switch (escolha) {
	case 1:
		system("cls");
		menu_consultas();;
		break;
	case 2:
		system("cls");
		menu_pesquisas();
		break;
	case 3:
		system("cls");

		break;
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 3");
		break;
	}
}

while (escolha != 3);
	
}

void menu_gestao_consumos() {// este é o menu que será apresentado ao utilizador. aqui ele ira puder gerir os consumos (adicionar, editar, remover, e listar)
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu de Gestao de Consumos\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Novo \n");
	printf(" 2 - Editar \n");
	printf(" 3 - Remover \n");
	printf(" 4 - Listar \n");
	printf(" 5 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
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
		
		break;		
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 5");
		break;
	}
}

while (escolha != 5);
	
}

void menu_gestao_clientes() {// este é o menu que será apresentado ao utilizador. aqui ele ira puder gerir os clientes (adicionar, editar, remover, e listar)
	int escolha;

do 
{
	system("cls");
	printf("======================================\n");
	printf(" Menu de Gestao de Clientes\n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Novo \n");
	printf(" 2 - Editar \n");
	printf(" 3 - Remover \n");
	printf(" 4 - Listar \n");
	printf(" 5 - Voltar Atras \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
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
		
		break;	
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 5");
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
	printf("---------------Bem Vindo-------------- \n");
	printf("\n");
	printf(" Escolha uma das seguintes opcoes: \n");
	printf("\n");
	printf(" 1 - Gestao clientes \n");
	printf(" 2 - Gestao consumos  \n");
	printf(" 3 - Consultar base de dados \n");
	printf(" 4 - Alterar base de dados \n");
	printf(" 5 - Sair \n");
	printf("\n");
	printf("======================================\n");
	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>5);
	
	switch (escolha) {
	case 1:
		system("cls");
		menu_gestao_clientes();
		break;
	case 2:
		system("cls");
		menu_gestao_consumos();
		break;
	case 3:
		system("cls");
		menu_consultas_bd();
		break;
	case 4:
		system("cls");
		menu_ficheiros();
		break;
	case 5:
		system("cls");
	
		break;
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 5");
		break;
	}
}

while (escolha != 5);
		
}

int main(int argc, char *argv[]) {
	
	menu_principal();
	return 0;
}

