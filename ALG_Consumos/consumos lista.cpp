#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void consulta_consumo{

indice_clientes // contador de clientes
indice_consumos // contador de consumos de um cliente
consumos // array que lista os todos os consumos dos clientes
int soma_consumos; // soma de todos os consumos de um cliente
float tab_cliente_totconsumo[30][2]; 



for (x = 0;x <= indice_clientes; x++) // Esta funcao vai percorrer todos os clientes, desde 0 ate ao número actual de clientes na base de dados
	{
		
	tab_cliente_totconsumo[x][0] = (float)lista_clientes[x].codigo

	for (i=0; i <= indice_consumos; i++) // Esta funcao vai calcular a soma de todos os consumos de um cliente especifico (x)
		{
			
			soma_consumos = soma_consumos + lista_consumos[consumos[i]].codigo;
			
		}
		
	tab_cliente_totconsumo[x][1] = soma_consumos
	
	} // no final deste FOR, o ARRAY tab_cliente_totconsumo[30][2] vai estar totalmente preenchido  


}
