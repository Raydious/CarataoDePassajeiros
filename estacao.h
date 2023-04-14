#ifndef _H_estacao
#define _H_estacao

typedef struct _estacao {

  char *nome;
  char *localidade;
  int codigo;
  int brindes;
  int brindesVendidos;
  int size;

} estacaoInfo, *estacao;

estacao criaEstacao(int posicaoEstacao, estacao estacoes[]);

void consultaEstacao(int posicaoEstacao, estacao estacoes[]);

#endif