#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


void menu(){
  printf("********+********** -> MENU <- *******************\n");
  printf("RP - Registar Passageiro\n");
  printf("RE - Registar Estacao\n");
  printf("IB - Incrementa Brindes\n");
  printf("RV - Regista Viagem\n");
  printf("EB - Escolhe Brindes\n");
  printf("CE - Consulta Estacao\n");
  printf("LP - Lista de Passageiros\n");
  printf("TB - Top de Brindes\n");
  printf("M - Menu\n");
  printf("A - Ajuda\n");
  printf("S - Sair\n");
  printf("***************************************************\n");
}

void ajuda(){

  printf("******************* -> IMPUTS E AJUDAS <- *******************\n");
  printf("RP - Precisa de um NOME e um EMAIL\n");
  printf("RE - Precisa de um NOME e uma LOCALIDADE\n");
  printf("IB - Precisa de um CODIGO DE ESTAÇÃO e de uma QUANTIDADE DE BRINDES\n");
  printf("RV - Precisa de um EMAIL e de 2 CODIGOS DE ESTAÇÃO\n");
  printf("EB - Precisa de um EMAIL e de uma QUANTIDADE DE BRINDES\n");
  printf("CE - Precisa de um CODIGO DE ESTAÇÃO\n");
  printf("LP - Não precisa de imputs\n");
  printf("TB - Não precisa de imputs\n");
  printf("M - Não precisa de imputs\n");
  printf("A - Não precisa de imputs\n");
  printf("S - Não precisa de imputs\n");
  printf("*************************************************************\n");
  
}