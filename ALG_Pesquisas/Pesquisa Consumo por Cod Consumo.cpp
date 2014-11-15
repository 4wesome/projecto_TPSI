void pesquisa_consumo_por_codigo() //Esta funcao vai pesquisar um consumo pelo seu codigo e retornar a informacao especifica a esse consumo
{
 int n = 1; // variavel de saida da funcao
 do
   {
   	int pesquisa_codigo // variavel para pesquisa
   	int x, i, s = 0; //a variavel S retorna uma mensagem de erro caso o nome pesquisado nao corresponder a nenhum nome da base de dados
   	
	  printf("_________________________________________________________________\n");
      printf("\n     Insira Codigo do Cliente");
      printf("\n_______________________________________________________________\n");
	  scanf("%s\n", &pesquisa_codigo);
		  
		  for (x = 0; x < indice_cliente;i++) 
		  {
		  	for (i = 0; i < lista_clientes[x].indice_consumo;i=i++)
		  	
		  		if (pesquisa_codigo == lista_clientes[x].consumo[i].cod_consumo) //comapara-se o codigo inserido com todos os codigos de consumos dos clientes
 					{
			  		 system("cls");
			   		 printf("_________________________________________\n");
			   		 printf("\n      Consumo %d do cliente %s\n", lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].nome);
			   		 printf("_________________________________________\n");
			   		 s = 1;
         			 printf("\nCodigo Consumo: %d | Data: %d/%d | Consumo: %f \n",lista_clientes[x].consumo[i].cod_consumo, lista_clientes[x].consumo[i].mes, lista_clientes[x].consumo[i].ano, lista_clientes[x].consumo[i].consumo);
   	   	  			 
					  x = indice_cliente; // uma vez encontrado o cliente a pesquisar, alteram-se as variaveis dos FOR para forcar uma saida 
   	   	  			  i = lista_clientes[x].indice_consumo;
 			   	   
 				   	}
		  }
		  if (s == 0)
		  {
		  	printf("O codigo de consumo que pesquisou esta errado ou nao se encontra na lista.\n");
		  }
		  
	printf("Prima 0 para voltar ao menu anterior.");
	scanf("%d", &n);
	}while (n != 0);
	
//Problema: Para cada cliente, os codigos de consumo sao exclusivos? Caso contrario, esta funcao retorna apenas o consumo i do primeiro cliente, e depois acaba.
}
	
	
