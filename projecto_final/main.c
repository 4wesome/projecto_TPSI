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
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Funcoes declaradas no topo 

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

//fim funcoes

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
		//ler_ficheiro();
		break;
	case 2:
		system("cls");
		guardar_clientes();
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
		inserir_consumos();
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
              system("pause");
          }
      }
	
	
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


void editar_clientes() {
	
int op, i, codigo_cliente;
	
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
		editar_clientes();
		break;
	case 3:
		system("cls");
		remover_clientes();
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

