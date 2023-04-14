#include "estacao.h"
#include "menu.h"
#include "passageiro.h"
#include "viagem.h"
#include "brindes.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  char comando[50];
  passageiro passageiros[100] = {NULL};
  viagem viagens[100] = {NULL};
  estacao estacoes[100] = {NULL};
  menu();
  int posicaoPassageiro = 0;
  int posicaoViagem = 0;
  int posicaoEstacao = 0;

  while (true) {
    fflush(stdin);
    printf("Comando: ");
    scanf(" %s", comando);
    

    if (strcmp(comando, "S") == 0 || strcmp(comando, "s") == 0) {
      printf("BYE BYE!!!!");
      break;
    } else if (strcmp(comando, "A") == 0 || strcmp(comando, "a") == 0) {
      ajuda();
    } else if (strcmp(comando, "M") == 0 || strcmp(comando, "m") == 0) {
      menu();
    } else if (strcmp(comando, "RP") == 0 || strcmp(comando, "rp") == 0) {
      passageiro p = criaPassageiro(posicaoPassageiro, passageiros);

      if(p != NULL){
        passageiros[posicaoPassageiro] = p;
        posicaoPassageiro++;
      }
    } else if (strcmp(comando, "LP") == 0 || strcmp(comando, "lp") == 0) {
      listaPassageiros(passageiros, posicaoPassageiro);
    } else if (strcmp(comando, "RV") == 0 || strcmp(comando, "rv") == 0) {
      viagem v = registaViagem(posicaoPassageiro, posicaoEstacao, posicaoViagem, estacoes, viagens, passageiros);

      if(v != NULL){
        viagens[posicaoViagem] = v;
        posicaoViagem++;
      }
    } else if (strcmp(comando, "RE") == 0 || strcmp(comando, "re") == 0) {
      estacao e = criaEstacao(posicaoEstacao, estacoes);

      if(e != NULL){
        estacoes[posicaoEstacao] = e;
        posicaoEstacao++;
      }
    } else if (strcmp(comando, "IB") == 0 || strcmp(comando, "ib") == 0){
      incrementaBrindes(posicaoEstacao, estacoes);
    } else if (strcmp(comando, "EB") == 0 || strcmp(comando, "eb") == 0){
      escolheBrindes(posicaoEstacao, posicaoPassageiro, estacoes, passageiros);
    } else if (strcmp(comando, "CE") == 0 || strcmp(comando, "ce") == 0){
      consultaEstacao(posicaoEstacao,estacoes);
    } else if (strcmp(comando, "TB") == 0 || strcmp(comando, "tb") == 0){
      //topBrindes(posicaoEstacao, estacoes);
    } else {
    printf("Comando invalido!!\n");
    }
  }
}
