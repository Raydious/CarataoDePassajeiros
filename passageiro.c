#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

passageiro criaPassageiro(int posicaoPassageiro, passageiro passageiros[]) {

  passageiro p = (passageiro)malloc(sizeof(passagerioInfo));
  p->nome = malloc(100 * sizeof(char));
  p->email = malloc(100 * sizeof(char));

  printf("\nNome: ");
  scanf(" %[^\n]", p->nome);
  printf("Email: ");
  scanf(" %s", p->email);

  p->pontos = 0;
  p->codigoEstacao = 501;

  if(posicaoPassageiro == 0){

    printf("Passageiro criado com sucesso!\n");

   }else{

    for(int i = 0; i < posicaoPassageiro; i++){

      if(strcmp(passageiros[i]->email, p->email) == 0){

        printf("Passageiro com este email já está registado\n");
        free(p);
        return NULL;

      }else if(i == posicaoPassageiro - 1){
        
        printf("Passageiro registado com sucesso\n");
        
      }
    }
  }
  return p;
  
}

void listaPassageiros(passageiro passageiros[], int posicaoPassageiro) {

  if (posicaoPassageiro == 0) {

    printf("**********************************************\n");
    printf("Nao existem passageiros registados!\n");
    printf("**********************************************\n");

  } else {

    printf("***************** -> LISTA PASSAGEIROS <- *****************\n\n");

    for (int i = 0; i < posicaoPassageiro; i++) {
      printf("NOME: %s // ", passageiros[i]->nome);
      printf("EMAIL: %s // ", passageiros[i]->email);
      printf("ULTIMA ESTAÇÃO: %d // ", passageiros[i]->codigoEstacao);
      printf("PONTOS: %d\n", passageiros[i]->pontos);
      printf("\n**********************************\n");
    }
  }
}

void destroiPassageiro(passageiro p) { free(p); }
