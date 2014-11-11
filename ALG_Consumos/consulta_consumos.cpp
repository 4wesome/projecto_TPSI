void consulta_consumos(){

int x, i, n=1, soma_consumos; // soma de todos os consumos de um cliente
float tab_cliente_totconsumo[30][2]; //tabela temporaria com os valores <codigo cliente> e <soma de consumos>
float swap_consulta


for (x = 0;x <= indice_cliente; x++) // Esta funcao vai percorrer todos os clientes, desde 0 ate ao n�mero actual de clientes na base de dados
	{
		
	soma_consumos = 0;	
		
	tab_cliente_totconsumo[x][0] = (float)lista_clientes[x].codigo;
	

	for (i=0; i <= lista_clientes.cliente.indice_consumos; i++) // Esta funcao vai calcular a soma de todos os consumos de um cliente especifico (x)
		{
			
			soma_consumos = soma_consumos + lista_cliente.cliente.consumo[i];
			
		}
		
	tab_cliente_totconsumo[x][1] = soma_consumos;
	
	} // no final deste FOR, o ARRAY tab_cliente_totconsumo[30][2] vai estar totalmente preenchido, com a primeira coluna mostrando o c�digo de cliente e a segunda o somat�rio de todos os consumos.
	
	//////////////////////////////////////
	
	for(x = 0; x < indice_clientes - 2 ; x++) // fun��o para ordenar os valores do ARRAY tab_cliente_totconsumo[30][2].
		{
			for(i = 0; i < indice_clientes - 2 - i; i--)
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

	//////////////////////////////

	printf("C�digo Cliente | Consumos \n");
	printf("\n");	

		for (x = 0; x <= indice_clientes; x++) // Imprime tab_cliente_totconsumo - lista de clientes por consumo.
		{
				printf("%f | %f \n", tab_cliente_totconsumo[x][0],tab_cliente_totconsumo[x][1]);
		}

	
}
