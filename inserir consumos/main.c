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
		char nome;
		char morada;
		char email;
		int telemovel;
		data data_nascimento;
		int bi;
		int num_fiscal;
		consumo consumo[100];
		int estado;
	}cliente;
	
	cliente lista_clientes[30];
	consumos lista_consumos[100]; 
	int indice_cliente=0, indice_consumos = 0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void novo_consumo(){

	int op, i;
	
		printf("_________________________________________________________________\n");
          printf("\n     Introduzir Novo Consumo");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo de Consumo: ");
          scanf("%d", &lista_consumos[indice_consumos].codigo);
          i = pesquisarConsumo(consumo[indice_consumos].codigo);

          if (i != -1) // Verifico se o código do consumo já existe
          {
             system("cls");
             printf("\n O CODIGO DO CONSUMO JA EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          else
          {
              cliente[indice_cliente].codigo = codigo_cliente;
              
			  
			  
              printf("\n Introduza o seu nome: ");
              fflush(stdin);
              gets(cliente[indice_cliente].nome);
              printf("\n Introduza a morada: ");
              fflush(stdin);
              gets(cliente[indice_cliente].morada);
              printf("\n Introduza o seu email: ");
              fflush(stdin);
              gets(cliente[indice_cliente].email);
              printf("\n Introduza o seu telemovel: ");
              scanf("%d", &cliente[indice_cliente].telemovel);
              printf("insira a data. primeiro insira o dia: ");
              scanf("%d", &data[indice_cliente].dia);
              printf("\n agora insira o mes: ");
              scanf("%d", &data[indice_cliente].mes);
              printf("\n agora insira o ano: ");
              scanf("%d", &data[indice_cliente].ano);
              printf("\n insira o seu BI: ");
              scanf("%d", &cliente[indice_cliente].bi);
              printf("\n insira o numero fiscal: ");
              scanf("%d", &cliente[indice_cliente].num_fiscal);
              
              
              
              
              // Incremento o número actual de clientes em +1
              indice_cliente++;
              system("cls");
              printf("\n O CLIENTE FOI ADICINADO COM SUCESSO.\n");
              
            }
	
}
int main(int argc, char *argv[]) {
	
novo_consumo();

return 0;

}
