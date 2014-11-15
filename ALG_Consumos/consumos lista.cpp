#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void consulta_consumo{

indice_clientes // contador de clientes
indice_consumos // contador de consumos de um cliente
consumos // array que lista os todos os consumos dos clientes

int soma_consumos; // soma de todos os consumos de um cliente
float tab_cliente_totconsumo[30][2]; //tabela temporaria com os valores <codigo cliente> e <soma de consumos>
float swap_consulta


for (x = 0;x <= indice_cliente; x++) // Esta funcao vai percorrer todos os clientes, desde 0 ate ao número actual de clientes na base de dados
	{
		
	soma_consumos = 0;	
		
	tab_cliente_totconsumo[x][0] = (float)lista_clientes[x].codigo;
	

	for (i=0; i <= lista_clientes.cliente.indice_consumos; i++) // Esta funcao vai calcular a soma de todos os consumos de um cliente especifico (x)
		{
			
			soma_consumos = soma_consumos + lista_cliente.cliente.consumo[i];
			
		}
		
	tab_cliente_totconsumo[x][1] = soma_consumos;
	
	} // no final deste FOR, o ARRAY tab_cliente_totconsumo[30][2] vai estar totalmente preenchido, com a primeira coluna mostrando o código de cliente e a segunda o somatório de todos os consumos.
	
	
	
	
	//APLICAR METODO DA BOLHA Á FUNÇÃO SEGUINTE
	
	
	
	swap_consulta = tab_cliente_totconsumo[x][1]
	swap_cod_cliente = tab_cliente_totconsumo[1][x]
			
	for(x = 1; x < indice_cliente - 1; x = x++) // função para ordenar os valores do ARRAY tab_cliente_totconsumo[30][2].
		{
			
			
				if (tab_cliente_totconsumo[0][1] < tab_cliente_totconsumo[x+1][1])
					{
						swap_consulta = tab_cliente_totconsumo[0][1]
						swap_cod_cliente = tab_cliente_totconsumo[0][0]
						
						tab_cliente_totconsumo[x+1][1] = tab_cliente_totconsumo[0][1]
						tab_cliente_totconsumo[x+1][0] = tab_cliente_totconsumo[0][0]
						
						tab_cliente_totconsumo[0][1] = swap_consulta
						tab_cliente_totconsumo[0][0] = swap_cod_cliente
						
						
					}
				
		}


// funcao para imprimir:
// CODIGO CLIENTE
// NOME CLIENTE
// SOMATORIO CONSUMOS




lista_cliente - struct cliente - array consumo - struct consumo - float consumo



}
