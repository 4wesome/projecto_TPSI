#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	 int c;
	 COORD c = { x, y };  
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
     printf("@");
     
}

int main (int argc, char *argv[]){
	int op = 0;
	
do
	{
	
	system("cls");
	printf("    1 - Op A\n");
	printf("    2 - Op B\n");
	printf("    3 - Op C\n");
	printf("    4 - Op D\n");
	printf("\n");
	printf("Escolha OP: \n");
	
	switch (op)
		{
			case 1:
				gotoxy(30,1);
				break;
			
			case 2:
				gotoxy(30,2);
				break;
				
			case 3:
				gotoxy(30,3);
				break;
				
			default:
				printf("Ecolha novamente:\n");
				break;
		}
	
	
	}while (op != 4);
	
	
}
