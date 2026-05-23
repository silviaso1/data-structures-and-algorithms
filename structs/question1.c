/*Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/


#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct
{
	int fabricacao;
	int modelo;
} TAno;

typedef struct
{
	char placa[10];
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	TAno ano;
	float valor;
	char tipo[10];
} TCarro;

int  filtrarCarros (TCarro ag[], int quantidade, char modelo[], int anoInicial, int anoFinal, float valorLimite);
void reajustar0KM (TCarro ag[], int quantidade, float taxaAumento);
int  removerCarro (TCarro ag[], int *quantidade, char placa[]);

void exibirDadosCarro (TCarro carro);
void preencherVetor (TCarro agencia[]);
void exibirTodosCarros (TCarro agencia[], int quantidade);

//main
void main ()
{

	TCarro agencia[TAM];
	int quantCarros = TAM;
	
	preencherVetor (agencia);
		

	
	
	printf ("Chamada 1 (exibindo carros por filtro):\n");
	if (filtrarCarros (agencia, quantCarros, "HB20", 2015, 2020, 38000) == 0)
	{
		printf ("\nNenhum carro atende aos filtros apresentados!\n\n");
	}

	
	printf ("Chamada 2 (exibindo carros por filtro):\n");
	if (filtrarCarros (agencia, quantCarros, "CRETA", 2015, 2020, 38000) == 0)
	{
		printf ("\nNenhum carro atende aos filtros apresentados!\n\n");
	}
	
	reajustar0KM (agencia, quantCarros, 2.5);
	
	printf ("\n\nExibindo os carros apos o reajuste:\n");
	exibirTodosCarros (agencia, quantCarros);


	printf ("Chamada 1 (removendo carro do estoque):\n");
	if (removerCarro (agencia, &quantCarros, "XYZ 1234") == 1)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca não localizada!\n\n");
	}
	

	printf ("Chamada 2 (remvendo carro do estoque):\n");
	if (removerCarro (agencia, &quantCarros, "CDE 3456") == 1)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca não localizada!\n\n");
	}
}

int  filtrarCarros (TCarro ag[], int quantidade, char modelo[], int anoInicial, int anoFinal, float valorLimite)
{
	
	int i, cont = 0;
	

	for (i=0;i<quantidade;i++)
	{
		
		if ((strcmp(modelo,ag[i].modelo)==0) &&  
		    ((ag[i].ano.fabricacao >= anoInicial) && (ag[i].ano.fabricacao <= anoFinal)) &&
		    (ag[i].valor <= valorLimite))
		{
			exibirDadosCarro (ag[i]);
			
			cont++;
		}
	}
	
	return cont;
}

void exibirDadosCarro (TCarro carro)
{
	printf ("Placa: %s\n", carro.placa);
	printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf ("Cor: %s\n", carro.cor);
	printf ("Km: %.1f\n", carro.quilometragem);
	printf ("Ano: %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: %s\n\n", carro.tipo);
}

void exibirTodosCarros (TCarro agencia[], int quantidade)
{
	int i;
	
	
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (agencia[i]);
	}
}

void reajustar0KM (TCarro ag[], int quantidade, float taxaAumento)
{
	
	int i;
	
	for (i=0;i<quantidade;i++)
	{
		
		if (ag[i].quilometragem == 0)

		{
			ag[i].valor *= (1 + taxaAumento/100);
		}
	}
}

int  removerCarro (TCarro ag[], int *quantidade, char placa[])
{

	int i;
	
	for (i=0;i<*quantidade;i++)
	{
	
		if (strcmp(placa,ag[i].placa) == 0)
		{
		
			ag[i] = ag[(*quantidade)-1];
			
			(*quantidade)--;
			
			return 1;
		}
	}	
	
	return 0;
}

void preencherVetor (TCarro agencia[])
{
	
	strcpy (agencia[0].placa, "ABC 1234");
	strcpy (agencia[0].modelo, "HB20");
	strcpy (agencia[0].marca, "HYUNDAI");
	strcpy (agencia[0].cor, "PRATA");
	agencia[0].quilometragem = 20000;
	agencia[0].ano.modelo = 2016;
	agencia[0].ano.fabricacao = 2015;
	agencia[0].valor = 25000;
	strcpy (agencia[0].tipo, "USADO");	
	
	
	strcpy (agencia[1].placa, "BCD 2345");
	strcpy (agencia[1].modelo, "CIVIC");
	strcpy (agencia[1].marca, "HONDA");
	strcpy (agencia[1].cor, "BRANCA");
	agencia[1].quilometragem = 0;
	agencia[1].ano.modelo = 2022;
	agencia[1].ano.fabricacao = 2022;
	agencia[1].valor = 90000;
	strcpy (agencia[1].tipo, "0KM");	
	

	strcpy (agencia[2].placa, "CDE 3456");
	strcpy (agencia[2].modelo, "HB20");
	strcpy (agencia[2].marca, "HYUNDAI");
	strcpy (agencia[2].cor, "PRETA");
	agencia[2].quilometragem = 45000;
	agencia[2].ano.modelo = 2017;
	agencia[2].ano.fabricacao = 2017;
	agencia[2].valor = 35000;
	strcpy (agencia[2].tipo, "USADO");	
	
	
	strcpy (agencia[3].placa, "EFG 4567");
	strcpy (agencia[3].modelo, "HB20");
	strcpy (agencia[3].marca, "HYUNDAI");
	strcpy (agencia[3].cor, "AZUL");
	agencia[3].quilometragem = 58000;
	agencia[3].ano.modelo = 2019;
	agencia[3].ano.fabricacao = 2018;
	agencia[3].valor = 40000;
	strcpy (agencia[3].tipo, "USADO");	
	
	strcpy (agencia[4].placa, "FGH 5678");
	strcpy (agencia[4].modelo, "ECOSPORT");
	strcpy (agencia[4].marca, "FORD");
	strcpy (agencia[4].cor, "VERDE");
	agencia[4].quilometragem = 0;
	agencia[4].ano.modelo = 2022;
	agencia[4].ano.fabricacao = 2022;
	agencia[4].valor = 85000;
	strcpy (agencia[4].tipo, "0KM");	
}