#include "estacao.h"
#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

estacao criaEstacao(int posicaoEstacao, estacao estacoes[]) {
  
  estacao e = (estacao)malloc(sizeof(estacaoInfo)); 
  e->nome = malloc(100 * sizeof(char));
  e->localidade = malloc(100 * sizeof(char));
  printf("\nNome da estacao: ");
    scanf(" %s", e->nome);
    printf("Localidade da estacao: ");
    scanf(" %s", e->localidade);
    e->codigo = rand() % 500;
    e->size = 0;
    e->brindes = rand() % 5;
    e->brindesVendidos = 0;
//SIM
  if(posicaoEstacao == 0){

    printf("Estacao criada com sucesso\n");

  }else{

    for(int i = 0; i < posicaoEstacao; i++){

      if(strcmp(estacoes[i]->nome, e->nome) == 0 && strcmp(estacoes[i]->localidade, e->localidade) == 0){
        
        printf("Já existe uma estacao com esse NOME nessa LOCALIDADE\n");
        free(e);
        return NULL;

      }else if(i == posicaoEstacao - 1){

        printf("Estacao registada com sucesso!!!\n");

      }
    }
  }
  return e;
  
}

void consultaEstacao(int posicaoEstacao, estacao estacoes[]){

  if(posicaoEstacao == 0){
    printf("*************** -> ESTAÇÕES <- ***************\n\n");
    printf("Não existem estações registadas!\n\n");
    printf("**********************************************\n");
  }else{
    printf("*************** -> ESTAÇÕES <- ***************\n");
    for(int i = 0; i < posicaoEstacao; i++){
    printf("\n %s / %s -> %d brindes  ||  CODIGO: %d\n\n", estacoes[i]->nome, estacoes[i]->localidade, estacoes[i]->brindes, estacoes[i]->codigo);
    printf("**********************************************\n");
    }
  }

}

