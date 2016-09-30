#include "Contribuicao.h"
#include "Editor.h"
#include "Pagina.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct contribuicao
{
	char *nomeContribuicao;
	Contribuicao *Prox;
	int excluida;
	Pagina *pagina;
	Editor *editor;
};

struct listaContribuicoes
{
	Contribuicao *Primeiro, *Ultimo;
};

ListaContribuicoes* InicializaListaContribuicoes()
{
	ListaContribuicoes *lista = (ListaContribuicoes*)malloc(sizeof(ListaContribuicoes));

	lista->Primeiro = lista->Ultimo = NULL;

	return lista;
}

void ImprimeContribuicoes(ListaContribuicoes* lista)
{
	printf("ImprimeContribuicoes\n");

	Contribuicao *aux = lista->Primeiro;

	if (aux == NULL)
	{
		printf("Nao ha contribuicoes");
		return;
	}

	do
	{
		printf("%s->", aux->nomeContribuicao);
		aux = aux->Prox;
	} while (aux != NULL);

	return;
}

void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaPaginas *listaP)
{
	printf("InsereContribuicao\n");

	Editor *editor = recuperaEditorPorNome(nomeEditor, listaE);
	Pagina *pagina = recuperaPaginaPorNome(listaP, nomePagina);

	if (editor == NULL)
	{
		printf("ERRO: EDITOR NAO EXISTE!\n");
		return;
	}
	if (pagina == NULL) {
		printf("ERRO: PAGINA NAO EXISTE!\N");
		return;
	}

	Contribuicao *c = (Contribuicao*) malloc(sizeof(Contribuicao));
	c->editor = editor;
	c->excluida = 0;
	c->nomeContribuicao = (char*)malloc(sizeof(char)*(strlen(nomeContribuicao) + 1));
	strcpy(c->nomeContribuicao,nomeContribuicao);
	c->Prox = NULL;
	c->pagina = pagina;
	if (listaC->Primeiro == NULL) {
		listaC->Primeiro = listaC->Ultimo = c;
		return;
	}
	c->Prox = listaC->Ultimo;
	listaC->Ultimo = c;
	return;
}