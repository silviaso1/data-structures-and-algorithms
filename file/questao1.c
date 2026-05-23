/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>

int arquivo(char nome[]);

void main(){
	char nome[10];
	
	printf("Digite o nome do arquivo:\n");
	fflush(stdin);
	gets(nome);
	
	int retorno = arquivo(nome);
	
	if(retorno == -1){
		printf("Erro");
	}
	else{
		printf("%d caracteres\n", retorno);
		}
}

int arquivo(char nome[]){
	
	FILE* arq = fopen(nome, "r");
	char ch;
	int quant = 0;
	
	if (!arq)
	{
		return -1;
	}
	else
	{
		while (fscanf (arq, "%c", &ch) != EOF) 
		{
			quant++;
		}
		fclose(arq);
		return quant;	
}
}

