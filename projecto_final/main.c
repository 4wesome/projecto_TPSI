#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
FILE *fp;
//Funcoes declaradas no topo 
void ler_ficheiro() {
     
     fp = fopen("dados.bin","r"); // Abre o ficheiro binário dados.bin em modo de leitura

      if(!fp) // Se o apontador devolvido for inválido ocorreu um erro na leitura
      {
            printf("\n IMPOSSIVEL ABRIR O FICHEIRO.");
            printf("\n\n ");
            system("pause");
            system("cls");
      }
      else
      {
            indice_cliente = fread(lista_clientes, sizeof(cliente), indice_cliente, fp); // Lê a informação do ficheiro e armazena no array de docentes
            fclose(fp); // Fecha o ficheiro
            system("cls");
            printf("\n O FICHEIRO FOI LIDO COM SUCESSO.\n\n ");
            system("pause");
            system("cls");
      }
      }
void guardar_clientes() {
	


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
    system("pause");
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
			return 1;
   		}
   		else
   		{
   			if(posPonto - posArroba < 3)
   			{
				return 1;	
   			}
   			else
   			{
   				return 0;
   			}
   		}
   }
   else
   {
		return 1;
   }
    
}

//fim funcoes

void menu_ficheiros() {// este é o menu que será apresentado ao utilizador. aqui ele ira ler e gravar dados na base de dados
	int escolha;

do 
{
	
	system("cls");
	
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c Consultas da Base de Dados  %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Ler Base de Dados                                %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Gravar Alteracoes                                %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>3);
	
	switch (escolha) {
	case 1:
		system("cls");
		ler_ficheiro();
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

void pesquisa_codigo(){ 

int x,cod_cliente_procura,i;
printf("_________________________________________________________________\n");
          printf("\n     Pesquisa por codigo");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &cod_cliente_procura);
          
	for (x = 0; x <= indice_cliente ; x++)
	{
       if (cod_cliente_procura == lista_clientes[x].codigo)
       {
                               printf("Nome:%s \n",lista_clientes[x].nome);
                               printf("Codigo de cliente: %d\n",lista_clientes[x].codigo);
                               printf("Morada: %s \n",lista_clientes[x].morada);
                               printf("Email: %s \n",lista_clientes[x].email);
                               printf("Telemovel: %d \n",lista_clientes[x].telemovel);
                               printf("Data de nascimento: %d/%d/%d \n",lista_clientes[x].data_nascimento.dia,lista_clientes[x].data_nascimento.mes,lista_clientes[x].data_nascimento.ano);
                               printf("Cartao de cidadao: %d \n",lista_clientes[x].bi);
                               printf("Nif: %d \n",lista_clientes[x].num_fiscal);
                               printf("Consumos");
                               printf("Codigo de consumos   Mes    Ano     Consumo");
                               for(i=0;i<lista_clientes[x].indice_consumo;i++){
                               printf("%d              %d      %d       %f",lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].consumo[i].mes,lista_clientes[x].consumo[i].ano,lista_clientes[x].consumo[i].consumo);
                                                             }
                                }                                                
                               }
                               system("pause");
                               }



void pesquisa_nome(){ 

int x,a,i;
char nome_cliente_procura[100];

printf("_________________________________________________________________\n");
          printf("\n     Pesquisa por Nome");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o nome do cliente: ");
          fflush(stdin);
          gets(nome_cliente_procura);
          
	for (x = 0; x < indice_cliente ; x++)
	{
        a = strcmp(nome_cliente_procura,lista_clientes[x].nome);

       if (a == 0)
       {
                               printf("Nome:%s \n",lista_clientes[x].nome);
                               printf("Codigo de Cliente: %d\n",lista_clientes[x].codigo);
                               printf("Morada: %s \n",lista_clientes[x].morada);
                               printf("Email: %s \n",lista_clientes[x].email);
                               printf("Telemovel: %d \n",lista_clientes[x].telemovel);
                               printf("Data de nascimento: %d/%d/%d \n",lista_clientes[x].data_nascimento.dia,lista_clientes[x].data_nascimento.mes,lista_clientes[x].data_nascimento.ano);
                               printf("Cartao de cidadao: %d \n",lista_clientes[x].bi);
                               printf("Nif: %d \n",lista_clientes[x].num_fiscal);
                               printf("Consumos:\n");
                               printf("Codigo de consumos   Mes    Ano     Consumo \n");
                               for(i=0;i<lista_clientes[x].indice_consumo;i++){
                               printf("%d              %d      %d       %f",lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].consumo[i].mes,lista_clientes[x].consumo[i].ano,lista_clientes[x].consumo[i].consumo); 
                                
                                }             
                                }
                                                   else {
                                     printf("Nome de cliente nao existe ou nome de cliente mal escrito");
                                     }                                   
                               }
                                                              system("pause"); 
                               }
                               


void pesquisa_consumo_por_codigo() //Esta funcao vai pesquisar um consumo pelo seu codigo e retornar a informacao especifica a esse consumo
{
 int n = 1; // variavel de saida da funcao
 //do
  // {
   	int pesquisa_codigo; // variavel para pesquisa
   	int x, i, s = 0,a; //a variavel S retorna uma mensagem de erro caso o nome pesquisado nao corresponder a nenhum nome da base de dados
   	
	  printf("_________________________________________________________________\n");
      printf("\n     Insira Codigo do Consumo a Pesquisar");
      printf("\n_______________________________________________________________\n");
      scanf("%d", &pesquisa_codigo);
 	       		  
		  for (x = 0; x < indice_cliente;x++) 
		  {
              
		  	for (i = 0; i < lista_clientes[x].indice_consumo;i++)
		  	{
		  	    
		  		if (pesquisa_codigo == lista_clientes[x].consumo[i].cod_consumo) //comapara-se o codigo inserido com todos os codigos de consumos dos clientes
 					{
                                    
			   		 printf("_________________________________________\n");
			   		 printf("\n      Consumo %d do cliente %s\n", lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].nome);
			   		 printf("_________________________________________\n");
			   		 s = 1; //caso u0m consumo com o codigo pesquisado seja encontrado, s torna-se 1
         			 printf("Nome:%s \n",lista_clientes[x].nome);
                     printf("Codigo de Cliente: %d\n",lista_clientes[x].codigo);
                     printf("Consumos:\n");
                     printf("Codigo de consumos   Mes    Ano     Consumo \n");
                     
                     printf("%d              %d      %d      %f\n",lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].consumo[i].mes,lista_clientes[x].consumo[i].ano,lista_clientes[x].consumo[i].consumo); 
                                
                                            
   	   	  			 
					  x = indice_cliente; // uma vez encontrado o cliente a pesquisar, alteram-se as variaveis dos FOR para forcar uma saida 
   	   	  			  i = lista_clientes[x].indice_consumo;
 			   	   
 				   	}
 			   }
		 }
		 if (s == 0) //se s =0, é porque os FOR's não encontraram nenhum consumo com o codigo pesquisado. Logo retorna uma mensagem de erro
		  {
		  	printf("O codigo de consumo que pesquisou esta errado ou nao se encontra na lista.\n");
		  }
		  
	//printf("Prima 0 para voltar ao menu anterior.");
	//scanf("%d", &n);
	//}while (n != 0);
    system("pause"); 
}
	



void menu_pesquisas() {// este é o menu que será apresentado ao utilizador. aqui ele ira pesquisar por varios parametros
	int escolha;

do 
{
	
	system("cls");
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c          Pesquisas          %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Pesquisar Cliente por Codigo                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Pesquisar Cliente por Nome                       %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Pesquisar Consumo por Nome de Cliente            %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 4 - Pesquisar Consumo por Codigo de Consumo          %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 5 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>5);
	
	switch (escolha) {
	case 1:
		system("cls");
		pesquisa_codigo();
		break;
	case 2:
		system("cls");
		pesquisa_nome();
		break;
	case 3:
		system("cls");
		pesquisa_nome();
		break;
	case 4:
		system("cls");
		pesquisa_consumo_por_codigo();
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






void consulta_consumos(){

int x, i, n=1, soma_consumos; // soma_consumos é a soma de todos os consumos de um cliente
float tab_cliente_totconsumo[30][2]; //tabela temporaria com os valores <codigo cliente> e <soma de consumos>
float swap_consulta;
float swap_cod_cliente;
int h;
for (x = 0;x <= indice_cliente; x++) // Esta funcao vai percorrer todos os clientes, desde 0 ate ao número actual de clientes na base de dados
	{
		
	soma_consumos = 0;	
		
	tab_cliente_totconsumo[x][0] = (float)lista_clientes[x].codigo;
	

	for (i=0; i <= lista_clientes[x].indice_consumo; i++) // Esta funcao vai calcular a soma de todos os consumos de um cliente especifico (x)
		{
			for(h=0;h<=lista_clientes[x].indice_consumo;h++);
			{
			
			soma_consumos = soma_consumos + lista_clientes[x].consumo[i].consumo;
        }
		}
		
	tab_cliente_totconsumo[x][1] = soma_consumos;
	
	} // no final deste FOR, o ARRAY tab_cliente_totconsumo[30][2] vai estar totalmente preenchido, com a primeira coluna mostrando o código de cliente e a segunda o somatório de todos os consumos.
	
	//////////////////////////////////////
	
	for(x = 0; x < indice_cliente - 2 ; x++) // função para ordenar os valores do ARRAY tab_cliente_totconsumo[30][2], de forma decrescente.
		{
			for(i = 0; i < indice_cliente - 2 - i; i--)
				{		
					if (tab_cliente_totconsumo[0][1] < tab_cliente_totconsumo[x+1][1])
						{
							swap_consulta = tab_cliente_totconsumo[0][1];
							swap_cod_cliente = tab_cliente_totconsumo[0][0];
							
							tab_cliente_totconsumo[0][1] = tab_cliente_totconsumo[x+1][1];
							tab_cliente_totconsumo[0][0] = tab_cliente_totconsumo[x+1][0];
							
							tab_cliente_totconsumo[x+1][1] = swap_consulta;
							tab_cliente_totconsumo[x+1][0] = swap_cod_cliente;
							
							
					}
				}
		}

	//////////////////////////////

	printf("Codigo Cliente | Consumos \n");
	printf("\n");	

		for (x = 0; x < indice_cliente; x++) // Imprime tab_cliente_totconsumo - lista de clientes por consumo.
		{
				printf("%f | %f \n", tab_cliente_totconsumo[x][0],tab_cliente_totconsumo[x][1]);
		}

	system("pause");
}


void consulta_inativos(){ // Esta função vai listar todos os clientes que tenham pelo menos 1 consumo não pago.
int n = 1;
int x, i;
system("cls");
			   		 printf("_________________________________________\n");
			   		 printf("\n      Clientes inativos\n");
			   		 printf("_________________________________________\n");
//do{


		// A função que se segue vai correr cada cliente, e, por cada um, vai analisar os seus consumos.
		// Assim que identificar um consumo não pago, imprime uma msg e deixa de analisar mais consumos desse cliente, e passa para o próximo cliente.
		for (x = 0; x < indice_cliente; x++) 
		{
		
			for (i = 0; i < lista_clientes[x].indice_consumo; i++)
			{
                
				if (lista_clientes[x].consumo[i].estado == 0);
					{
                                                        
						printf("%d  |  %s\n",lista_clientes[x].codigo, lista_clientes[x].nome);	
					
						
					}
			}
		}
		
	//	printf("Prima 0 para voltar ao menu anterior.");
	//	scanf("%", &n);
	
		
//}while (n != 0);
system("pause");
}


void menu_consultas() {// este é o menu que será apresentado ao utilizador. aqui consulta clientes por consumo e os que nao pagaram
	int escolha;

do 
{
		system("cls");
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c          Consultas          %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Listar Clientes por Consumo                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Listar Clientes que nao pagaram                  %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

	do {
			printf(" Opcao escolhida: ");
			scanf("%d", &escolha);
		}
	while (escolha<0 || escolha>3);
	
	switch (escolha) {
	case 1:
		system("cls");
		consulta_consumos();
		break;
	case 2:
		system("cls");
		consulta_inativos();
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
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c  Consultas da Base de Dados %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Consulta                                         %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Pesquisa                                         %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

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

void remover_consumos() {
	int cod_consumo, u, i = 0, a, op, j, z,flag_remov, codigo_cliente;
	int t = 0;
	int indice_consumo;
	printf("antesdisto");
	

     
     printf("depois doadus sdisto"); 
      if (indice_consumo == 0) // Verifico se existem docentes para remover
      {
         printf("\n NAO EXISTEM CONSUMOS!!!\n\n ");
         system("pause");
         system("cls");
      }
      else
      {
          do {

		  printf("_________________________________________________________________\n");
          printf("\n     CONSUMOS DO CLIENTE ");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");

		printf("\n Insira codigo cliente: \n");     
		scanf("%d", &codigo_cliente);
        i = pesquisar_clientes(codigo_cliente); 
       	indice_consumo = lista_clientes[i].indice_consumo;   
                printf("\n Codigo: %d 		\n Nome: %s ",lista_clientes[i].codigo, lista_clientes[i].nome);
          		for(j = 0; j < lista_clientes[i].indice_consumo; j++)
          		{
          			//lista consumos do cliente selecionado

                    printf("\n Codigo Consumo: %d      ", lista_clientes[i].consumo[j].cod_consumo);
                    printf("\n Mes: %d      ", lista_clientes[i].consumo[j].mes);
					printf("\n Ano: %d      ", lista_clientes[i].consumo[j].ano);
                	printf("\n Consumo: %f      ", lista_clientes[i].consumo[j].consumo);
                	
          
          		}
          printf("\n_________________________________________________________________\n");
          
		  printf("\n\n \t para selecionar o consumo a eliminar prima a tecla 5.\n");
          scanf("%d", &op);
    	  }while(op!=5);
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do Consumo: ");
          scanf("%d", &cod_consumo);
          u = pesquisar_consumos(cod_consumo, indice_cliente);
          if (i == -1) // Pesquiso se o codigo de consumo existe
          {
             system("cls");
             printf("\n O CODIGO DO CONSUMO NAO EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          else
          {
              system("cls");

			  // Removo o consumo puxando os consumos seguintes 1 posição para traz
              
              for(a = 0; a < indice_consumo - 1;a++)
              {
                    
                    lista_clientes[i].consumo[u] = lista_clientes[i].consumo[u + 1];
              }
              
              // Decremento o número actual de docentes em -1
              
			  lista_clientes[i].indice_consumo --;
			  
              system("cls");
              printf("\n O CONSUMO FOI REMOVIDO COM SUCESSO.\n");
              system("pause");
          }
      }
	
	
}

/*
void listar_consumos() {
int i, op, a;

do {

		  printf("_________________________________________________________________\n");
          printf("\n     Consumos");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          for(i = 0; i< lista_clientes[i].indice_consumo ; i++)
          {
          	   
                printf("\nCodigo: %d   Consumo: %d   Estado: %s\n",lista_clientes[i].consumo[a].cod_consumo, lista_clientes[i].consumo[a].consumo, lista_clientes[i].consumo[a].estado);
                
                printf("\n_________________________________________________________________\n");
          }
          printf("\n\n para sair prima a tecla 5.\n");
          scanf("%d", &op);
    }
    while(op!=5);
}
*/

void editar_consumos() {
	
int op, i, a, m, cod_consumo, codigo_cliente, existe = 0, j;
	

	float preco_total;
	
		  printf("_________________________________________________________________\n");
          printf("\n     Editar Consumos");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          fflush(stdin);
          i = pesquisar_clientes(codigo_cliente);
          
          do {

		  printf("_________________________________________________________________\n");
          printf("\n     CONSUMOS DO CLIENTE %d", codigo_cliente);
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          
                printf("\n Codigo: %d 		\n Nome: %s",lista_clientes[i].codigo, lista_clientes[i].nome);
          		for(j = 0; j < lista_clientes[i].indice_consumo; j++)
          		{
          			//lista consumos do cliente selecionado

					printf("\n Mes: %d      ", lista_clientes[i].consumo[j].mes);
					printf("\n Ano: %d      ", lista_clientes[i].consumo[j].ano);
                	printf("\n Consumo: %f      ", lista_clientes[i].consumo[j].consumo);
                	printf("\n");
          
          		}
          printf("\n_________________________________________________________________\n");
          
		  printf("\n\n \t para editar prima a tecla 5.\n");
          scanf("%d", &op);
          fflush(stdin);
    	  }while(op!=5);

          
		  
          
          	//Final aqui fica i != -1
			  if (i != -1) // Verifico se o código do cliente já existe
		      {
		      	
		         system("cls");		         
		         do
		         {
		         	printf("\n Introduza o codigo do consumo: ");
		         	scanf("%d", &cod_consumo);
		         	fflush(stdin);
		         	if (cod_consumo > 2921000 || cod_consumo < 2920000) 
					{ // aqi é onde o pograma verifica de o codigo inserido é valido ou nao
						printf("\n O CODIGO DO CONSUMO NAO E VALIDO!!!\n\n  por favor insira um codigo entre 2920000 e 2921000\n \n");
          			}
		         }while(cod_consumo > 2921000 || cod_consumo < 2920000);
		      	 
		      	 a = pesquisar_consumos(cod_consumo, lista_clientes[i].indice_consumo);
		      	 
		    
		      	 		
						if (a != -1) // Verifica-se se o código do consumo já existe
						{
						system("cls");
						printf("\n O CODIGO DO CONSUMO JA EXISTE!!!\n\n Tente novamente.\n\n ");
						system("pause");
						system("cls");
						
						printf("\n Introduza o mes: ");
						fflush(stdin);
						scanf("%d", &lista_clientes[i].consumo[a].mes);
						
							
						do
						{
							
							printf("\n Introduza o ano: ");
							fflush(stdin);
							scanf("%d", &lista_clientes[i].consumo[a].ano);
							existe = 0;
							for(m=0; m < lista_clientes[i].indice_consumo; m++)
							{
								if(lista_clientes[i].consumo[m].mes == lista_clientes[m].consumo[a].mes && lista_clientes[i].consumo[m].ano == lista_clientes[m].consumo[a].ano ){
									
									existe = 1;
									printf("\n Ja foi inserido um consumo para o mes e ano selecionados");
								}
							}			
						}while(existe == 1);
						
						
						printf("\n Introduza o consumo: \n\n");
						scanf("%f", &lista_clientes[i].consumo[a].consumo);
						
						//calcular o preco a pagar
						preco_total = lista_clientes[i].consumo[a].consumo * PRECO_GB;
						preco_total = preco_total + preco_total * IVA;
						
						lista_clientes[i].consumo[a].preco = preco_total;
						
						printf("O preco total a pagar e de : %f \n", preco_total);
						
						
						//estado do consumo 1 e pago 0 e nao pago	
						printf("\n Introduza o estado do consumo(1 para pago || 0 para nao pago): ");
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].estado);
						fflush(stdin);
						if(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].estado == 0){
							
							lista_clientes[i].estado == 0;
							
						}
						
						
						system("cls");
						printf("\n O CONSUMO FOI EDITADO COM SUCESSO.\n");
						system("pause");
						
						
						}
		      
						else // se o codigo do consumo nao existir o utilizador nao pode editar
						{
						system("cls");
						printf("\n O COODIGO DE CONSUMO NAO EXISTE.\n \n");
						system("pause");
						

						}
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
          fflush(stdin);
          i = pesquisar_clientes(codigo_cliente);

          
		  if (lista_clientes[i].indice_consumo < 100)
          {
          
          	//Final aqui fica i != -1
			  if (i != -1) // Verifico se o código do cliente já existe
		      {
		      	
		         system("cls");

		         
		         do
		         {
		         	printf("\n Introduza o codigo do consumo: ");
		         	scanf("%d", &cod_consumo);
		         	fflush(stdin);
		         	if (cod_consumo > 2921000 || cod_consumo < 2920000) 
					{ // aqui é onde o pograma verifica se o codigo inserido é valido ou nao
						printf("\n O CODIGO DO CONSUMO NAO E VALIDO!!!\n\n  por favor insira um codigo entre 2920000 e 2921000\n \n");
          			}
		         }while(cod_consumo > 2921000 || cod_consumo < 2920000);
		      	 
		      	 
		      	 a = pesquisar_consumos(cod_consumo, lista_clientes[i].indice_consumo);
		      	
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
						
						do{
						
						printf("\n Introduza o mes: ");
						fflush(stdin);
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes);
						if(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes<1 || lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes>12) {
              			system("cls");
             			printf("\n O MES E INVALIDO!!!\n\n Tente novamente.\n\n ");
             			system("pause");
             			system("cls");
			  			}
			  			}while(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes<1 || lista_clientes[i].consumo[lista_clientes[i].indice_consumo].mes>12);
						
							
						do{
						
						printf("\n Introduza o ano: ");
						fflush(stdin);
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano);
						
						if(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano<1900 || lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano>2014) {
              			system("cls");
             			printf("\n O ANO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             			system("pause");
             			system("cls");
             			}
						}while(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano<1900 || lista_clientes[i].consumo[lista_clientes[i].indice_consumo].ano>2014);
						
						existe = 0;
						for(m=0; m < lista_clientes[i].indice_consumo; m++)
							{
								if(lista_clientes[i].consumo[m].mes == lista_clientes[m].consumo[lista_clientes[m].indice_consumo].mes && lista_clientes[i].consumo[m].ano == lista_clientes[m].consumo[lista_clientes[m].indice_consumo].ano ){
									
									printf("\n Ja foi inserido um consumo para o mes e ano selecionados ");
									existe = 1;
									system("pause");
								}
							}
							if(existe == 0)
							{
						
						
						
						
						printf("\n Introduza o consumo: \n \n");
						scanf("%f", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].consumo);
						
						//calcular o preco a pagar
						preco_total = lista_clientes[i].consumo[lista_clientes[i].indice_consumo].consumo * PRECO_GB;
						preco_total = preco_total + preco_total * IVA;
						
						lista_clientes[i].consumo[lista_clientes[i].indice_consumo].preco = preco_total;
						
						printf("O preco total a pagar e de : %f \n\n", preco_total);
						
						//estado do consumo 1 e pago 0 e nao pago	
						printf("\n Introduza o estado do consumo(1 para pago || 0 para nao pago): ");
						scanf("%d", &lista_clientes[i].consumo[lista_clientes[i].indice_consumo].estado);
						fflush(stdin);
						
						if(lista_clientes[i].consumo[lista_clientes[i].indice_consumo].estado == 0){
							
							lista_clientes[i].estado = 0;
							
						}
						
						// Incremento o número actual de consumo em +1
						lista_clientes[i].indice_consumo++;
						system("cls");
						printf("\n O CONSUMO FOI ADICINADO COM SUCESSO.\n");
						system("pause");
						
						}
					}
				   
				   } else {
				   		system("cls");
						printf("\n Nao podem ser adicionados consumos ao cliente devido ao estado em que este se encontra .\n");
						system("pause");
				   }
		   	 					   
		      } else {
		      	printf("\n  ERRO!! O Codigo de Cliente nao existe");
		      	system("pause");
		      }
      
          } else {
          		printf("\n  O cliente selecionado ja atingiu o limite de consumos");
				system("pause");          	
          }
}
            
void menu_gestao_consumos() {// este é o menu que será apresentado ao utilizador. aqui ele ira puder gerir os consumos (adicionar, editar, remover, e listar)
	int escolha;

do 
{
	
	
		system("cls");
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c      Gestao de Consumos     %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Novo                                             %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Editar                                           %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Listar                                           %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 4 - Remover                                          %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 5 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

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
		editar_consumos();
		break;
	case 3:
		system("cls");
		//listar_consumos();
		break;
	case 4:
		system("cls");
		remover_consumos();
		break;
	case 5:
		system("cls");
		
		break;		
	default:
		system("cls");
		printf(" O Valor introduzido nao e valido! Devera introduzir um valor entre 1 e 4");
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
          if (i == -1) // Pesquiso se o cliente existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE NAO EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          else
          {
              system("cls");

			  // Removo o cliente puxando os clientes seguintes 1 posição para traz
              for(a = i; a < indice_cliente - 1;a++)
              {
                    lista_clientes[a] = lista_clientes[a + 1];
              }
              // Decremento o número actual de docentes em -1
              indice_cliente--;
              system("cls");
              printf("\n O CLIENTE FOI REMOVIDO COM SUCESSO.\n");
              system("pause");
          }
      }
	
	
}

void inserir_clientes(){

	int op, i, codigo_cliente, vEmail = 0;
	
		
         
		 do {
		 	printf("_________________________________________________________________\n");
          printf("\n     ADICIONAR CLIENTE");
          printf("\n_________________________________________________________________\n");
		  printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          fflush(stdin);
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
  
              
            do {
			
			            
			  printf("\n Introduza o seu email: ");
              fflush(stdin);
              gets(lista_clientes[indice_cliente].email);
			
              	vEmail = Verifica_email(lista_clientes[indice_cliente].email); //chama a funcao para verificar o email
              
              	if(vEmail == 1)
              	{
    				printf("o seu email e invalido!! \n\n por favor tente outra vez \n \n");
              	}
          	}
          	while(vEmail == 1);
              
              
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
			  
              printf("\n Introduza a data de nascimento:  \n \t Dia: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.dia);
              	if(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31) {
              		system("cls");
             		printf("\n O DIA DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		fflush(stdin);
             	}
             }
              while(lista_clientes[indice_cliente].data_nascimento.dia<1 || lista_clientes[indice_cliente].data_nascimento.dia> 31);
            do {
			
              printf("\n \t Mes: ");
              scanf("%d", &lista_clientes[indice_cliente].data_nascimento.mes);
              	if(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12) {
              		system("cls");
             		printf("\n O MES DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		fflush(stdin);
			  		}
			  }
			  while(lista_clientes[indice_cliente].data_nascimento.mes<1 || lista_clientes[indice_cliente].data_nascimento.mes> 12);
			  
			  do {
			  
              printf("\n \t Ano: ");
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
			 
			  printf("\n Introduza Nr BI: ");
				scanf("%d", &lista_clientes[indice_cliente].bi);
				if(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 ) {
              		system("cls");
             		printf("\n O SEU BI E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		fflush(stdin);
              	}
        	}
        	while(lista_clientes[indice_cliente].bi <10000000 || lista_clientes[indice_cliente].bi > 99999999 );
        	do{
			
              printf("\n Introduza NIF: ");
              scanf("%d", &lista_clientes[indice_cliente].num_fiscal);
              	if(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999) {
              		system("cls");
             		printf("\n O SEU NIF E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		fflush(stdin);
              	}
              }
              while(lista_clientes[indice_cliente].num_fiscal<100000000 || lista_clientes[indice_cliente].num_fiscal>999999999);
              
              do{
			
              printf("\n Introduza o seu estado: ");
              scanf("%d", &lista_clientes[indice_cliente].estado);
              fflush(stdin);
              	if(lista_clientes[indice_cliente].estado<0 || lista_clientes[indice_cliente].estado>1) {
              		system("cls");
             		printf("\n O SEU ESTADO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		fflush(stdin);
              	}
              }
              while(lista_clientes[indice_cliente].estado<0 || lista_clientes[indice_cliente].estado>1);
              
              
              
              
              // Incremento o número actual de clientes em +1
              indice_cliente++;
              system("cls");
              printf("\n O CLIENTE FOI ADICINADO COM SUCESSO.\n");
              system("pause");
              system("cls");
              
              
            }
		}
void listar_clientes() {
int i, op;

do {

		  printf("_________________________________________________________________\n");
          printf("\n     CLIENTES");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          for(i = 0; i< indice_cliente ; i++)
          {
          	 /*
                printf("\n Codigo:%d     Numero BI:%d      Nome:%s      Morada:%s      Email:%s      Telemovel:%d      Data Nascimento:%d      Num Fiscal:%d      Estado:%d", lista_clientes[i].codigo, lista_clientes[i].bi, lista_clientes[i].nome, lista_clientes[i].morada, lista_clientes[i].email, lista_clientes[i].telemovel, lista_clientes[i].data_nascimento, lista_clientes[i].num_fiscal, lista_clientes[i].estado);
            */  
                printf("\nCodigo: %d   Numero BI: %d   Nome:%s\n",lista_clientes[i].codigo, lista_clientes[i].bi, lista_clientes[i].nome);
                printf("\nMorada: %s   Email: %s Telemovel: %d\n",lista_clientes[i].morada, lista_clientes[i].email, lista_clientes[i].telemovel);
                printf("\nData Nascimento: %d/%d/%d   Num Fiscal: %d   Estado: %d\n",lista_clientes[i].data_nascimento.dia, lista_clientes[i].data_nascimento.mes, lista_clientes[i].data_nascimento.ano, lista_clientes[i].num_fiscal, lista_clientes[i].estado);
                printf("\n_________________________________________________________________\n");
          }
          printf("\n\n para sair prima a tecla 5.\n");
          scanf("%d", &op);
    }
    while(op!=5);
}

void editar_clientes() {
	
int op, i, codigo_cliente, a, j, z,flag_remov, b;
	
	
		if (indice_cliente == 0) // Verifico se existem docentes para editar
      {
         printf("\n NAO EXISTEM CLIENTES!!!\n\n ");
         system("pause");
         system("cls");
      }
      else
      {
         
		 
		  printf("_________________________________________________________________\n");
          printf("\n     EDITAR CLIENTES");
          printf("\n_________________________________________________________________\n");
          printf("\n_________________________________________________________________\n");
          for(i = 0; i< indice_cliente ; i++)
          {
                printf("\n Codigo:%d     Numero BI:%d      Nome:%s", lista_clientes[i].codigo, lista_clientes[i].bi, lista_clientes[i].nome);
          }
          printf("\n_________________________________________________________________\n");
          
		  printf("\n para sair prima a tecla 5 \n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          fflush(stdin);
             
          
          i = pesquisar_clientes(codigo_cliente);
          
		  if (i == -1) // Pesquiso se o cliente existe
          {
             system("cls");
             printf("\n O CODIGO DO CLIENTE NAO EXISTE!!!\n\n Tente novamente.\n\n ");
             system("pause");
             system("cls");
          }
          
      	 
      	 else {
		   	
              
          
              lista_clientes[i].codigo = codigo_cliente;
              	system("cls");
			    printf("_________________________________________________________________\n");
          		printf("\n     EDITAR CLIENTES");
         		printf("\n_________________________________________________________________\n");
          		printf("\n_________________________________________________________________\n");
			  
              printf("\n Introduza o seu nome: ");
              fflush(stdin);
              gets(lista_clientes[i].nome);
              printf("\n Introduza a morada: ");
              fflush(stdin);
              gets(lista_clientes[i].morada);
              
			  printf("\n Introduza o seu email: ");
              fflush(stdin);
              gets(lista_clientes[i].email);
              
            do {
			
              Verifica_email(lista_clientes[i].email); //chama a funcao para verificar o email
          		}
          	while(Verifica_email(lista_clientes[i].email) == 1);
              
              
             do {
			 
			 
              printf("\n Introduza o seu telemovel: ");
              scanf("%d", &lista_clientes[i].telemovel);
              if (lista_clientes[i].telemovel <910000000 || lista_clientes[i].telemovel>969999999) {
              	system("cls");
             	printf("\n O NUMERO DE TELEMOVEL E INVALIDO!!!\n\n Tente novamente.\n\n ");
             	system("pause");
             	system("cls");
             	}
             }
            while(lista_clientes[i].telemovel <910000000 || lista_clientes[i].telemovel>969999999);
             	
              
              do {
			  
              printf("\n Introduza a data de nascimento \n \t Dia: ");
              scanf("%d", &lista_clientes[i].data_nascimento.dia);
              	if(lista_clientes[i].data_nascimento.dia<1 || lista_clientes[i].data_nascimento.dia> 31) {
              		system("cls");
             		printf("\n O DIA DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             	}
             }
              while(lista_clientes[i].data_nascimento.dia<1 || lista_clientes[i].data_nascimento.dia> 31);
            do {
			
              printf("\n \t Mes: ");
              scanf("%d", &lista_clientes[i].data_nascimento.mes);
              	if(lista_clientes[i].data_nascimento.mes<1 || lista_clientes[i].data_nascimento.mes> 12) {
              		system("cls");
             		printf("\n O MES DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
			  		}
			  }
			  while(lista_clientes[i].data_nascimento.mes<1 || lista_clientes[i].data_nascimento.mes> 12);
			  
			  do {
			  
              printf("\n \t Ano: ");
              scanf("%d", &lista_clientes[i].data_nascimento.ano);
              	if(lista_clientes[i].data_nascimento.ano<1900 || lista_clientes[i].data_nascimento.ano> 2014) {
              		system("cls");
             		printf("\n O ANO DE NASCIMENTO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		}
             }
             while(lista_clientes[i].data_nascimento.ano<1900 || lista_clientes[i].data_nascimento.ano> 2014);
             
             do{
			 
			  printf("\n Introduza o Nr BI: ");
				scanf("%d", &lista_clientes[i].bi);
				if(lista_clientes[i].bi <10000000 || lista_clientes[i].bi > 99999999 ) {
              		system("cls");
             		printf("\n O SEU BI E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
        	}
        	while(lista_clientes[i].bi <10000000 || lista_clientes[i].bi > 99999999 );
        	do{
			
              printf("\n Introduza o NIF: ");
              scanf("%d", &lista_clientes[i].num_fiscal);
              	if(lista_clientes[i].num_fiscal<100000000 || lista_clientes[i].num_fiscal>999999999) {
              		system("cls");
             		printf("\n O SEU NIF E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
              }
              while(lista_clientes[i].num_fiscal<100000000 || lista_clientes[i].num_fiscal>999999999);
              
               do{
			
              printf("\n Introduza o seu estado: ");
              scanf("%d", &lista_clientes[i].estado);
              	if(lista_clientes[i].estado<0 || lista_clientes[i].estado>1) {
              		system("cls");
             		printf("\n O SEU ESTADO E INVALIDO!!!\n\n Tente novamente.\n\n ");
             		system("pause");
             		system("cls");
             		
              	}
              }
              while(lista_clientes[i].estado<0 || lista_clientes[i].estado>1);
              
              
              
              
              system("cls");
              printf("\n O CLIENTE FOI EDITADO COM SUCESSO.\n");
              system("pause");
              system("cls");
              
        }
  		
  	} while(i == -1);
	}

void menu_gestao_clientes() {// este é o menu que será apresentado ao utilizador. aqui ele ira puder gerir os clientes (adicionar, editar, remover, e listar)
	int escolha;

do 
{
			system("cls");
			system("color 70");
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c      Gestao de Clientes     %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Novo                                             %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Editar                                           %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Remover                                          %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 4 - Listar                                           %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 5 - Voltar Atras                                     %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

	
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
		listar_clientes();
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
			system("color 70");
	printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("             %c          Bem Vindo          %c",186,186);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c                                                      %c\n",186,186);
        printf("%c 1 - Gestao de Clientes                               %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 2 - Gestao de Consumos                               %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 3 - Consultar Base de Dados                          %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 4 - Alterar Base de Dados                            %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c 5 - Sair                                             %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c                                                      %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

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

