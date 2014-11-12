#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRECO_GB 0.5
#define IVA 0.23

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
	
	typedef struct { // registo para os consumos
		int codigo;
		char nome[100];
		char morada[250];
		char email[50];
		int telemovel;
		data data_nascimento;
		int bi;
		int num_fiscal;
		consumo consumo[100];
		int indice_consumo;
		int estado;
	}cliente;
	
	cliente lista_clientes[30]; 
	int indice_cliente=0;
	
int pesquisar_consumos(int codigo_consumo, int indiceCliente) {
			int l,u,i;
		      l = 0;
		      u = indice_cliente - 1;
		      i = (l + u) / 2;
		
		      while ((l <= u) && (lista_clientes[indiceCliente].consumo[i].cod_consumo != codigo_consumo))
		      {
		            if(codigo_consumo < lista_clientes[indiceCliente].consumo[i].cod_consumo)
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

void inserir_consumos(){

	int op, i, a, m, cod_consumo, codigo_cliente, existe = 0;

	float preco_total;
	
		  printf("_________________________________________________________________\n");
          printf("\n     ADICIONAR Consumo");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          i = pesquisar_clientes(codigo_cliente);

          if (lista_clientes[i].indice_consumo < 100)
          {
          
          	//Final aqui fica i != -1
			  if (i == -1) // Verifico se o código do cliente já existe
		      {
		         system("cls");
		         
		         
		         
		         
		         do
		         {
		         	printf("\n Introduza o codigo do consumo: ");
		         	scanf("%d", &cod_consumo);
		         	if (cod_consumo > 2921000 || cod_consumo < 2920000) 
					{ // aqi é onde o pograma verifica de o codigo inserido é valido ou nao
						printf("\n O CODIGO DO CONSUMO NAO E VALIDO!!!\n\n  por favor insira um codigo entre 2920000 e 2921000\n \n");
          			}
		         }while(cod_consumo > 2921000 || cod_consumo < 2920000);
		         
		         
		         
		         
		      	 
		      	 
		    
		      	 
		      	 a = pesquisar_consumos(lista_clientes[i].indice_consumo, cod_consumo);
		      	 
		      	 if(lista_clientes[i].estado == 1){ //1 e ativo 0 e inativo
		      	 		
						if (a != -1) // Verifica-se se o código do consumo já existe
						{
						system("cls");
						printf("\n O CODIGO DO CONSUMO JA EXISTE!!!\n\n Tente novamente.\n\n ");
						system("pause");
						system("cls");
						}
		      
						else // se o codigo do consumo ainda nao existir o utilizador pode inserir o resto dos campos
						{
						lista_clientes[i].consumo[lista_clientes[i].indice_consumo].cod_consumo = cod_consumo;
						
						printf("\n Introduza o mes: ");
						fflush(stdin);
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes);
						
							
						printf("\n Introduza o ano: ");
						fflush(stdin);
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano);
						
						existe = 0;
						for(m=0; m <= lista_clientes[i].indice_consumo; m++)
							{
								if(lista_clientes[i].consumo[m].mes == lista_clientes[m].consumo[lista_clientes[m].indice_consumo].mes && lista_clientes[i].consumo[m].ano == lista_clientes[m].consumo[lista_clientes[m].indice_consumo].ano ){
									
									printf("\n Ja foi inserido um consumo para o mes e ano selecionados ");
									existe = 1;
								}
							}
							if(existe == 0)
							{
							
						
						printf("\n Introduza o consumo: ");
						scanf("%f", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].consumo);
						
						//calcular o preco a pagar
						preco_total = lista_clientes[i].consumo[lista_clientes[i].indice_consumo].consumo * PRECO_GB;
						preco_total = preco_total + preco_total * IVA;
						
						lista_clientes[i].consumo[lista_clientes[i].indice_consumo].preco = preco_total;
						
						printf("O preco total a pagar e de : %f \n", preco_total);
						
						// Incremento o número actual de consumo em +1
						lista_clientes[i].indice_consumo++;
						system("cls");
						printf("\n O CONSUMO FOI ADICINADO COM SUCESSO.\n");
						
						}
					}
				   
				   } else {
				   		system("cls");
						printf("\n Nao podem ser adicionados consumos ao cliente caloteiro :D .\n");
				   }
		   	 					   
		      } else {
		      	printf("\n  ERRO!! O Codigo de Cliente nao existe");
		      }
          
          } else {
          		printf("\n  O cliente selecionado ja atingiu o limite de consumos");          	
          }
          
          

          
	
}
int main(int argc, char *argv[]) {
	
inserir_consumos();

return 0;

}
