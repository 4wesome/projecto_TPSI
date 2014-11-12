void pesquisa_consumo_por_nome() //Esta funcao vai pesquisar um cliente pelo nome e retornar a informacao especifica aos seus consumos
{
 int n = 1; // variavel de saida da funcao
 do
   {
   	char pesquisa_nome[100] // variavel para pesquisa
   	int x, i, s = 0; //a variavel S retorna uma mensagem de erro caso o nome pesquisado nao corresponder a nenhum nome da base de dados
   	
	  printf("_________________________________________________________________\n");
      printf("\n     Insira Nome do Cliente");
      printf("\n_______________________________________________________________\n");
	  scanf("%s\n", &pesquisa_nome);
		  
		  for (x = 0; x < indice_clientes;i++) 
		  {
		  	if ((strcmp(pesquisa_nome == lista_clientes[x].nome)) == 0) //comapara-se a string inserida com todos os nomes dos clientes
 			{
			   system("cls");
			   printf("_________________________________________\n");
			   printf("\n      Consumos do cliente %s\n", lista_clientes[x].nome);
			   printf("_________________________________________\n");
			   
			   
 			   for (i = 0; i < lista_clientes[x].indice_consumo;i=i++)
 			   	   {
 			   	   	  s = 1;
   	                  printf("Codigo Consumo: %d | Data: %d/%d | Consumo: %f \n",lista_clientes[x].consumo[i].codigo_consumo, lista_clientes[x].consumo[i].mes, lista_clientes[x].consumo[i].ano, lista_clientes[x].consumo[i].consumo);
   	   	  			 
					  x = indice_clientes; // uma vez encontrado o cliente a pesquisar, alteram-se as variaveis dos FOR para forcar uma saida 
   	   	  			  i = lista_clientes[x].indice_consumo;
 			   	   }
 			}
		  }
		  if (s == 0)
		  {
		  	printf("O nome de cliente que pesquisou esta errado ou nao se encontra na lista.\n");
		  }
		  
	printf("Prima 0 para voltar ao menu anterior.");
	scanf("%d", &n);
	}while (n != 0);

}
	
	
