#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	FILE *fp;
	char nome[100];
	int i;

	fp = fopen("clientes.bin", "a");
	if(!fp)
	{
		printf("Erro na abertura do ficheiro.\n");
		exit(0);
	}
 
 	do
 	{
 		printf("Insira o nome do cliente:\n");
 		gets(nome);
 		if(strcmp(nome,"fim")!=0)
 		{
 			for(i = 0; i < strlen(nome); i++)
			{
				putc(nome[i], fp);
			}
			putc('\n', fp);
		}
 	}
 	while(strcmp(nome,"fim")!=0);
	fclose(fp);
	
	return 0;
}
