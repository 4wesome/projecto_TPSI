
void consulta_inativos(){ 

int x, i;

	for (x = 1; x <= indice_clientes ; x++)
	{
	
		for (i = 1; i <= indice_clientes[x].indice_consumo; i++)
		{
			if (lista_clientes[x].consumo[i].estado == 0);
				{
					printf("%d  |  %s\n",lista_clientes[x].codigo, lista_clientes[x].nome);	
					x++;
					i = 1;
				}
		}
}