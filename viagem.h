#ifndef _H_viagem
#define _H_viagem
#include "estacao.h"
#include "passageiro.h"

typedef struct _viagem {

  char *viagem;
  int origem;
  int destino;
  int km;
  int size;

} viagemInfo, *viagem;

viagem criaViagem(estacao origem, estacao destino);

viagem registaViagem(int posicaoPassageiro, int posicaoEstacao, int posicaoViagem, estacao estacoes[], viagem viagens[], passageiro passageiros[]);


#endif