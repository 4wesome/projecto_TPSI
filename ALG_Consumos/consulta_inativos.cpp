
void consulta_inativos(){ // Esta função vai listar todos os clientes que tenham pelo menos 1 consumo não pago.
int n = 1;

do{

	int x, i;
	
		// A função que se segue vai correr cada cliente, e, por cada um, vai analisar os seus consumos.
		// Assim que identificar um consumo não pago, imprime uma msg e deixa de analisar mais consumos desse cliente, e passa para o próximo cliente.
		for (x = 0; x < indice_clientes ; x++) 
		{
		
			for (i = 0; i < indice_clientes[x].indice_consumo; i++)
			{
				if (lista_clientes[x].consumo[i].estado == 0);
					{
						printf("%d  |  %s\n",lista_clientes[x].codigo, lista_clientes[x].nome);	
						x++;
						i = 0;
					}
			}
		}
		
		printf("Prima 0 para voltar ao menu anterior.");
		scanf("%", &n);
	
		
}while (n != 0)




