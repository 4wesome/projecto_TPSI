#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


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


int Verifica_email(char email[50]) // funcao para validar o email do cliente
{
   int posArroba = strchr(email, '@') - email + 1;
   int posPonto;
   
   if(posArroba > 3)
   {
   		posPonto = strrchr(email, '.') - email + 1;
   		if( !(strlen(email) - posPonto >= 2 && strlen(email) - posPonto <= 3) )
   		{
   			system("cls");
    		printf("o seu email e invalido!! \n\n por favor tente outra vez \n \n");
    		system("pause");
			system("cls");
			return 1;
		
			
   		}
   		else
   		{
   			if(posPonto - posArroba < 3)
   			{
   				system("cls");
    			printf("o seu email e invalido!! \n\n por favor tente outra vez \n \n");
    			system("pause");
				system("cls");
				return 1;
				
   			}
   		}
   }
   else
   {
   		system("cls");
    	printf("o seu email e invalido!! \n\n por favor tente outra vez \n \n");
    	system("pause");
		system("cls");
		return 1;
		
   
   }
   
    
}

void guardar_clientes() {
	FILE *fp;


fp = fopen("dados.bin", "w");
if(!fp)
{
           printf("Erro na abertura do ficheiro.\n");
           exit(0);
}
else
{
		fwrite(lista_clientes, sizeof(cliente), indice_cliente, fp);
		  fclose(fp); 
    printf("Gravado com sucesso.\n");
}
fclose(fp);

}

void inserir_clientes(){

	int op, i, codigo_cliente;
	
		
         
		 do {
		 	printf("_________________________________________________________________\n");
          printf("\n     ADICIONAR CLIENTE");
          printf("\n_________________________________________________________________\n");
		  printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
         if (codigo_cliente > 19215000 || codigo_cliente < 19214000) { // aqi é onde o pograma verifica de o codigo inserido é valido ou nao
          	 
			system("cls");
			printf("\n O CODIGO DO CLIENTE NAO E VALIDO!!!\n\n  por favor insira um codigo entre 19214000 e 19215000\n \n");
			system("pause");
			system("cls");
					}
			}
			while (codigo_cliente > 19215000 || codigo_cliente < 19214000);
        	  
          
         
         
          
		  
        	i = pesquisar_clientes(codigo_cliente);
				

          if (i != -1) // Verifico se o código do cliente já existe
          do {
		  {
             system("cls");
             printf("\n O CODIGO DO CLIENTE JA EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
             
          }		
          
      		}
      		while (i != -1);
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
              
            do {
			
              Verifica_email(lista_clientes[indice_cliente].email); //chama a funcao para verificar o email
          		}
          	while(Verifica_email(lista_clientes[indice_cliente].email) == 1);
              
              
             do {
			 
			 
              printf("\n Introduza o seu telemovel: ");
              scanf("%d", &lista_clientes[indice_cliente].telemovel);
              if (lista_clientes[indice_cliente].telemovel <910000000 || lista_clientes[indice_cliente].telemovel>969999999) {
              	system("cls");
             	printf("\n O NUMERO DE TELEMOVEL E INVALIDO!!!\n\n Tente novamente.\n\n ");
             	system("pause");
             	system("cls");
             	}
             }
            while(lista_clientes[indice_cliente].telemovel <910000000 || lista_clientes[indice_cliente].telemovel>969999999);
             	
              
              do {
			  
              printf("\n insira a data. \n \t primeiro insira o dia: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.dia);
              	if(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31) {
              		system("cls");
             		printf("\n O DIA DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             	}
             }
              while(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31);
            do {
			
              printf("\n \t agora insira o mes: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.mes);
              	if(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12) {
              		system("cls");
             		printf("\n O MES DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
			  		}
			  }
			  while(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12);
			  
			  do {
			  
              printf("\n \t agora insira o ano: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.ano);
              	if(lista_clientes[indice_cliente].data_nascimento.ano<1900 || lista_clientes[indice_cliente].data_nascimento.ano> 2014) {
              		system("cls");
             		printf("\n O ANO DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		}
             }
             while(lista_clientes[indice_cliente].data_nascimento.ano<1900 || lista_clientes[indice_cliente].data_nascimento.ano> 2014);
             
             do{
			 
			  printf("\n insira o seu BI: ");
				scanf("%d", &lista_clientes[indice_cliente].bi);
				if(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 ) {
              		system("cls");
             		printf("\n O SEU BI E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
        	}
        	while(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 );
        	do{
			
              printf("\n insira o numero fiscal: ");
              scanf("%d", &lista_clientes[indice_cliente].num_fiscal);
              	if(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999) {
              		system("cls");
             		printf("\n O SEU NIF E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
              }
              while(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999);
              
              
              
              
              // Incremento o número actual de clientes em +1
              indice_cliente++;
              system("cls");
              printf("\n O CLIENTE FOI ADICINADO COM SUCESSO.\n");
              system("pause");
              system("cls");
              
              
            }
		}



void remover_clientes() {
	int codigo_cliente, i, a, op, j, z,flag_remov;
      
      if (indice_cliente == 0) // Verifico se existem docentes para remover
      {
         printf("\n NAO EXISTEM CLIENTES!!!\n\n ");
         system("pause");
         system("cls");
      }
      else
      {
          printf("_________________________________________________________________\n");
          printf("\n     REMOVER CLIENTES");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          for(i = 0; i< indice_cliente ; i++)
          {
                printf("\n Codigo:%d     Numero BI:%d      Nome:%s", lista_clientes[i].codigo, lista_clientes[i].bi, lista_clientes[i].nome);
          }
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do docente: ");
          scanf("%d", &codigo_cliente);
          i = pesquisar_clientes(codigo_cliente);
          if (i == -1) // Pesquiso se o docente existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE NAO EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          else
          {
              system("cls");

			  // Removo o docente puxando os docentes seguintes 1 posição para traz
              for(a = i; a < indice_cliente - 1;a++)
              {
                    lista_clientes[a] = lista_clientes[a + 1];
              }
              // Decremento o número actual de docentes em -1
              indice_cliente--;
              system("cls");
              printf("\n O DOCENTE FOI REMOVIDO COM SUCESSO.\n");
          }
      }
	
	
}

void editar_clientes() {
	
int op, i, codigo_cliente, a;
	
		if (indice_cliente == 0) // Verifico se existem docentes para editar
      {
         printf("\n NAO EXISTEM CLIENTES!!!\n\n ");
         system("pause");
         system("cls");
      }
      else
      {
         do {
		 
		  printf("_________________________________________________________________\n");
          printf("\n     EDITAR CLIENTES");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          for(i = 0; i< indice_cliente ; i++)
          {
                printf("\n Codigo:%d     Numero BI:%d      Nome:%s", lista_clientes[i].codigo, lista_clientes[i].bi, lista_clientes[i].nome);
          }
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          i = pesquisar_clientes(codigo_cliente);
          if (i == -1) // Pesquiso se o cliente existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE NAO EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          
      	 
      	 else {
		   		for(a = i; a < indice_cliente - 1;a++) //elemina o cliente anterior
              {
                    lista_clientes[a] = lista_clientes[a + 1];
              }
              
              
          
              lista_clientes[indice_cliente].codigo = codigo_cliente;
              	system("cls");
			    printf("_________________________________________________________________\n");
          		printf("\n     EDITAR CLIENTES");
         		printf("\n_________________________________________________________________\n");
          		printf("\n_________________________________________________________________\n");
			  
              printf("\n Introduza o seu nome: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].nome);
              printf("\n Introduza a morada: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].morada);
              
			  printf("\n Introduza o seu email: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].email);
              
            do {
			
              Verifica_email(lista_clientes[indice_cliente].email); //chama a funcao para verificar o email
          		}
          	while(Verifica_email(lista_clientes[indice_cliente].email) == 1);
              
              
             do {
			 
			 
              printf("\n Introduza o seu telemovel: ");
              scanf("%d", &lista_clientes[indice_cliente].telemovel);
              if (lista_clientes[indice_cliente].telemovel <910000000 || lista_clientes[indice_cliente].telemovel>969999999) {
              	system("cls");
             	printf("\n O NUMERO DE TELEMOVEL E INVALIDO!!!\n\n Tente novamente.\n\n ");
             	system("pause");
             	system("cls");
             	}
             }
            while(lista_clientes[indice_cliente].telemovel <910000000 || lista_clientes[indice_cliente].telemovel>969999999);
             	
              
              do {
			  
              printf("\n insira a data. \n \t primeiro insira o dia: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.dia);
              	if(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31) {
              		system("cls");
             		printf("\n O DIA DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             	}
             }
              while(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31);
            do {
			
              printf("\n \t agora insira o mes: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.mes);
              	if(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12) {
              		system("cls");
             		printf("\n O MES DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
			  		}
			  }
			  while(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12);
			  
			  do {
			  
              printf("\n \t agora insira o ano: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.ano);
              	if(lista_clientes[indice_cliente].data_nascimento.ano<1900 || lista_clientes[indice_cliente].data_nascimento.ano> 2014) {
              		system("cls");
             		printf("\n O ANO DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		}
             }
             while(lista_clientes[indice_cliente].data_nascimento.ano<1900 || lista_clientes[indice_cliente].data_nascimento.ano> 2014);
             
             do{
			 
			  printf("\n insira o seu BI: ");
				scanf("%d", &lista_clientes[indice_cliente].bi);
				if(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 ) {
              		system("cls");
             		printf("\n O SEU BI E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
        	}
        	while(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 );
        	do{
			
              printf("\n insira o numero fiscal: ");
              scanf("%d", &lista_clientes[indice_cliente].num_fiscal);
              	if(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999) {
              		system("cls");
             		printf("\n O SEU NIF E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
              }
              while(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999);
              
              
              
              
              // Incremento o número actual de clientes em +1
              indice_cliente++;
              system("cls");
              printf("\n O CLIENTE FOI EDITADO COM SUCESSO.\n");
              system("pause");
              system("cls");
              
        }
  		
  	} while(i == -1);
	}
}
int main(int argc, char *argv[]) {

inserir_clientes();
guardar_clientes();
editar_clientes();
remover_clientes();


return 0;
}

