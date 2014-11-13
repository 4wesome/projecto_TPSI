void pesquisa_codigo(){ 

int x,codigo_cliente;
printf("_________________________________________________________________\n");
          printf("\n     Pesquisa por codigo");
          printf("\n_________________________________________________________________\n");
          printf("\n Introduza o codigo do cliente: ");
          scanf("%d", &codigo_cliente);
          
	for (x = 0; x <= indice_clientes ; x++)
	{
       if (cod_cliente_procura == indice_clientes.cliente.cod_cliente)
       {
                               printf("Nome:%c \n ",lista_clientes[x].nome);
                               printf("codigo de cliente: %d\n,lista_clientes[x].cod_cliente);
                               printf("Morada: %c \n",lista_clientes[x].morada);
                               printf("Email: %c \n",lista_clientes[x].email);
                               printf("Telemovel: %c \n",lista_clientes[x].telemovel);
                               printf("Data de nascimento: %c/%c/%c \n",lista_clientes[x].data_nascimento.dia,)lista_clientes[x].data_nascimento.mes,lista_clientes[x].data_nascimento.ano;
                               printf("Cartao de cidadao: %c \n",lista_clientes[x].bi);
                               printf("Nif: %c \n",lista_clientes[x].num_fiscal);
                               printf("Consumos");
                               printf("Codigo de consumos   Mes    Ano     Consumo")
                               for(i=0;i<=lista_clientes[x].indice_consumo;i++){
                               printf("%d %d %d %f",lista_clientes[x].cod_consumo,lista_clientes[x].consumo.mes,lista_clientes[x].consumo.ano,lista_clientes[x].consumo[i]);
                                
                                
                                }                                                
                               }
                               }
