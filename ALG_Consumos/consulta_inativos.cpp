
void consulta_inativos(){ // Esta fun��o vai listar todos os clientes que tenham pelo menos 1 consumo n�o pago.
int n = 1;

do{

	int x, i;
	
		// A fun��o que se segue vai correr cada cliente, e, por cada um, vai analisar os seus consumos.
		// Assim que identificar um consumo n�o pago, imprime uma msg e deixa de analisar mais consumos desse cliente, e passa para o pr�ximo cliente.
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




