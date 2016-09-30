

typedef struct editor Editor;

/* ESTRUTURA LISTA DE EDITORES (TIPO OPACO)
* Campos da celula da lista:
* - Prox (struct listaEditores*)
* - nomeEditor (char*)
* - contribuicoes (listaContribuicoes*) - lista de contribuicoes que o editor fez
*/
typedef struct listaEditores ListaEditores;

/* CRIA UMA NOVA LISTA DE EDITORES
* Inputs: Nenhum
* Outputs: Lista de editores
* Pre-Condicao:
* Pos-Condicao:
*/
ListaEditores* InicializaListaEditores();

/* INSERE O EDITOR NO INICIO DA LISTA DE EDITORES
* Inputs: Nome do editor e lista de editores
* Outputs: Lista de editores atualizada
* Pre-Condicao:
* Pos-Condicao:
*/
ListaEditores* InsereEditor(char *nomeEditor, ListaEditores* lista);

/* RETIRA EDITOR DA LISTA
* Inputs: Nome do editor
* Outputs: Lista de editores atualizada
* Pre-Condicao:
* Pos-Condicao:
*/
ListaEditores* RetiraEditor(char *nomeEditor, ListaEditores *lista);

/* LIBERA O ESPACO ALOCADO PELA LISTA DE EDITORES
* Inputs: Lista de editores
* Outputs: Lista de editores liberada
* Pre-Condicao:
* Pos-Condicao:
*/
ListaEditores* FimEditores(ListaEditores* lista);

void ImprimeEditores(ListaEditores* lista);

/* RETORNA O EDITOR PEDIDO
* Inputs: Nome
* Outputs: Editor
* Pre-Condicao:
* Pos-Condicao:
*/
Editor* recuperaEditorPorNome(char *nome, ListaEditores *lista);
