#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	typedef struct { // registo para a data
		int dia;
		int mes;
		int ano;
	}data;

	typedef struct{ // registo para os consumos
		int cod_consumo;
		int mes;
		int ano;
		float consumo;
		float preco;
		int estado;
		
	}consumo;
	
	typedef struct { // registo para os clientes
		int codigo;
		char nome[100];
		char morada[250];
		char email[50];
		int telemovel;
		data data_nascimento;
		int bi;
		int num_fiscal;
		consumo consumo[100];
		int estado;
	}cliente;
	
	cliente lista_clientes[30]; 
	int indice_cliente=0;
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
		//novo_consumo();
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

int pesquisar_clientes(int codigo_cliente) {
	int l,u,i;
      l = 0;
      u = indice_cliente - 1;
      i = (l + u) / 2;

      while ((l <= u) && (lista_clientes[i].codigo != codigo_cliente))
      {
            if(codigo_cliente < lista_clientes[i].codigo)
            {
                  u = i - 1;
            }
            else
            {
                  l = i + 1;
            }
            i = (l + u) / 2;
      }

      if(l <= u)
      {
            return i;
      }
      else
      {
            return -1;
      }
	
	
}
void inserir_clientes(){

	int op, i, codigo_cliente;
	
		printf("_________________________________________________________________\n");
          printf("\n     ADICIONAR CLIENTE");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          i = pesquisar_clientes(codigo_cliente);

          if (i != -1) // Verifico se o código do cliente já existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE JA EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          else
          {
              lista_clientes[indice_cliente].codigo = codigo_cliente;
              
			  
			  
              printf("\n Introduza o seu nome: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].nome);
              printf("\n Introduza a morada: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].morada);
              printf("\n Introduza o seu email: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].email);
              printf("\n Introduza o seu telemovel: ");
              scanf("%d", &lista_clientes[indice_cliente].telemovel);
              printf("\n Introduza a Data de Nascimento: \n ");
              printf("		Introduza  o dia: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.dia);
              printf("\n		Introduza o mes:  ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.mes);
              printf("\n		Introuza o ano: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.ano);
              printf("\n Introduza o seu BI: ");
              scanf("%d", &lista_clientes[indice_cliente].bi);
              printf("\n Introduza o numero fiscal: ");
              scanf("%d", &lista_clientes[indice_cliente].num_fiscal);
              
              
              
              
              // Incremento o número actual de clientes em +1
              indice_cliente++;
              system("cls");
              printf("\n O CLIENTE FOI ADICINADO COM SUCESSO.\n");
              
            }
	
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
		inserir_clientes();
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

