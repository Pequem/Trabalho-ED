#include "Pagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Log.h"
#include "Link.h"
#include "Contribuicao.h"

typedef struct link Link;
typedef struct listaLinks ListaLinks;


struct pagina
{
	char *nomePagina;
	char *nomeArquivo;
	Pagina *Prox;
};

struct listaPaginas
{
	Pagina *Primeiro;
};

ListaPaginas* InicializaListaPaginas()
{
	ListaPaginas *lista = (ListaPaginas*)malloc(sizeof(ListaPaginas));

	lista->Primeiro = NULL;

	return lista;
}

void ImprimePaginas(ListaPaginas* lista)
{
	printf("ImprimePaginas\n");

	Pagina *aux = lista->Primeiro;

	if (aux == NULL)
	{
		printf("Nao ha paginas");
		return;
	}

	do
	{
		printf("%s->", aux->nomePagina);
		aux = aux->Prox;
	} while (aux != NULL);

	return;
}

Pagina * recuperaPaginaPorNome(ListaPaginas * listaPaginas, char * nome)
{
	Pagina *aux;

	if (listaPaginas->Primeiro == NULL)
	{
		return NULL;
	}

	if (listaPaginas->Primeiro->nomePagina == nome)
	{
		return listaPaginas->Primeiro;
	}

	aux = listaPaginas->Primeiro;

	do
	{
		aux->Prox;
	} while (nome == aux->nomePagina || aux == NULL);

	return aux;
}

int checkExistencia(char * nomePagina, ListaPaginas * listaPaginas)
{
	Pagina *aux;
	if (strcmp(listaPaginas->Primeiro->nomePagina, nomePagina)) {
		return 1;
	}
	do {
		aux->Prox;
		if (strcmp(aux->nomePagina, nomePagina)) {
			return 1;
		}
	} while (aux != NULL);
	return 0;
}

ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas *lista)
{
	printf("InserePagina\n");

	if (checkExistencia(nomePagina, lista)) {
		printf("Pagina ja existe");
		printLog("Pagina", nomePagina, "ja existe");
		return lista;
	}

	Pagina *novaPagina = (Pagina*)malloc(sizeof(Pagina));
	novaPagina->Prox = NULL;

	int tamNomePagina = strlen(nomePagina) + 1;
	int tamNomeArquivo = strlen(nomeArquivo) + 1;

	novaPagina->nomePagina = (char*)malloc(tamNomePagina * sizeof(char));
	novaPagina->nomeArquivo = (char*)malloc(tamNomeArquivo * sizeof(char));

	strcpy(novaPagina->nomePagina, nomePagina);
	strcpy(novaPagina->nomeArquivo, nomeArquivo);

	//SE A LISTA ESTIVER VAZIA
	if (lista->Primeiro == NULL)
		lista->Primeiro = novaPagina;

	//SE A LISTA JA TIVER ELEMENTOS
	else
	{
		novaPagina->Prox = lista->Primeiro;
		lista->Primeiro = novaPagina;
	}
	printLog("Pagina", nomePagina, "inserida");
	return lista;
}

ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista, ListaLinks *listaLinks, ListaContribuicoes *listaContribuicoes)
{
	printf("RetiraPagina\n");

	Pagina *atual = lista->Primeiro;
	Pagina *anterior = lista->Primeiro;

	//PROCURANDO PAGINA A SER RETIRADA
	while (atual != NULL)
	{
		if (strcmp(atual->nomePagina, nomePagina) == 0)
			break;

		anterior = atual;
		atual = atual->Prox;
	}

	//CASO A PAGINA NAO EXISTA
	if (atual == NULL)
	{
		printf("ERRO: PAGINA NAO EXISTE!\n");
		printLog("ERRO: PAGINA",nomePagina,"NAO EXISTE!");
	}

	//PAGINA A SER RETIRADA EH A PRIMEIRA DA LISTA
	else if (atual == lista->Primeiro)
	{
		lista->Primeiro = atual->Prox;
	}
	//PAGINA A SER RETIRADA ESTA EM OUTRA POSICAO DA LISTA
	else
	{
		anterior->Prox = atual->Prox;
	}
	RetiraContribuicoesPorPagina(atual, listaContribuicoes);
	RetiraLinksPorPagina(atual, listaLinks);
	free(atual->nomeArquivo);
	free(atual->nomePagina);
	free(atual);
	printLog("Pagina", nomePagina, "retirada");

	return lista;
}

void FimPaginas(ListaPaginas *lista)
{
	printf("FimPaginas\n");

	Pagina *aux1, *aux = lista->Primeiro;

	while (aux != NULL)
	{
		aux1 = aux;

		free(aux1->nomeArquivo);
		free(aux1->nomePagina);

		aux = aux->Prox;

		free(aux1);
	}

	free(lista);
}