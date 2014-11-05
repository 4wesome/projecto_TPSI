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
	int indice_cliente=0;

int pesquisar_clientes(codigo_cliente) {
	int l,u,i;
      l = 0;
      u = indice_cliente - 1;
      i = (l + u) / 2;

      while ((l <= u) && (cliente[i].codigo_cliente != codigo_cliente))
      {
            if(codigo_cliente < cliente[i].codigo_cliente)
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

	int op, i;
	
		printf("_________________________________________________________________\n");
          printf("\n     ADICIONAR CLIENTE");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &lista_clientes[indice_cliente].codigo);
          i = pesquisar_cliente(cliente[indice_cliente].codigo);

          if (i != -1) // Verifico se o código do cliente já existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE JA EXISTE!!!\n\n Tente novamente.\n\n ");
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
	
inserir_clientes();

return 0;

}
