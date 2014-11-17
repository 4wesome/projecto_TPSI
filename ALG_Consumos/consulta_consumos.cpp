void consulta_consumos(){

int x, i, n=1, soma_consumos; // soma_consumos é a soma de todos os consumos de um cliente
float tab_cliente_totconsumo[30][2]; //tabela temporaria com os valores <codigo cliente> e <soma de consumos>
float swap_consulta


for (x = 0;x <= indice_cliente; x++) // Esta funcao vai percorrer todos os clientes, desde 0 ate ao número actual de clientes na base de dados
	{
		
	soma_consumos = 0;	
		
	tab_cliente_totconsumo[x][0] = (float)lista_clientes[x].codigo;
	

	for (i=0; i <= lista_clientes[x]indice_consumos; i++) // Esta funcao vai calcular a soma de todos os consumos de um cliente especifico (x)
		{
			
			soma_consumos = soma_consumos + lista_cliente[x].cliente.consumo[i];
			
		}
		
	tab_cliente_totconsumo[x][1] = soma_consumos;
	
	} // no final deste FOR, o ARRAY tab_cliente_totconsumo[30][2] vai estar totalmente preenchido, com a primeira coluna mostrando o código de cliente e a segunda o somatório de todos os consumos.
	
	for(x = 0; x < indice_cliente - 2 ; x++) // função para ordenar os valores do ARRAY tab_cliente_totconsumo[30][2], de forma decrescente.
		{
			for(i = 0; i < indice_cliente - 2 - i; i--)
				{		
					if (tab_cliente_totconsumo[0][1] < tab_cliente_totconsumo[x+1][1])
						{
							swap_consulta = tab_cliente_totconsumo[0][1]
							swap_cod_cliente = tab_cliente_totconsumo[0][0]
							
							tab_cliente_totconsumo[0][1] = tab_cliente_totconsumo[x+1][1]
							tab_cliente_totconsumo[0][0] = tab_cliente_totconsumo[x+1][0]
							
							tab_cliente_totconsumo[x+1][1] = swap_consulta
							tab_cliente_totconsumo[x+1][0] = swap_cod_cliente
							
							
					}
				}
		}

	printf("Código Cliente | Consumos \n");
	printf("\n_______________________________\n");	

		for (x = 0; x <= indice_cliente; x++) // Imprime tab_cliente_totconsumo - lista de clientes por consumo.
		{
				printf("Codigo Cliente: %f	Nome: %s	Consumo Total: %f",tab_cliente_totconsumo[x][0],lista_clientes[x].nome, tab_cliente_totconsumo[x][1]);
		}

	// É preciso isto tudo estar dentro de um DO / WHILE?
}
