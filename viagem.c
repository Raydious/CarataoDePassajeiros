#include "viagem.h"
#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

viagem criaViagem(estacao origem, estacao destino)
{
  viagem v = (viagem)malloc(sizeof(estacaoInfo));
  v->viagem = malloc(sizeof(viagemInfo));
  v->origem = origem->codigo;
  v->destino = destino->codigo;
  v->km = rand() % 300;
  v->size = 0;
  return v;
}

viagem registaViagem(int posicaoPassageiro, int posicaoEstacao, int posicaoViagem, estacao estacoes[], viagem viagens[], passageiro passageiros[])
{

  char email[50];
  int partida;
  int chegada;
  printf("Email do passageiro que vai viajar: ");
  scanf(" %s", email);

  for (int i = 0; i < posicaoPassageiro; i++)
  {

    if (strcmp(passageiros[i]->email, email) == 0)
    {
      int partidaVezes = 0;
      int chegadaVezes = 0;

      for (int j = 0; j < posicaoEstacao; j++)
      {

        printf("%s -> ", estacoes[j]->nome);
        printf("%d\n", estacoes[j]->codigo);
      }

      printf("De que estação vais partir (INSERIR O CODIGO): ");
      if (scanf(" %d", &partida) != 1)
      {
        printf("Tens de colocar o NUMERO DA ESTAÇÃO!");
        break;
      }
      printf("Para que estção vais (INSERIR O CODIGO): ");
      if (scanf(" %d", &chegada) != 1)
      {
        printf("Tens de colocar o NUMERO DA ESTAÇÃO!");
        break;
      }

      if (partida == chegada)
      {
        printf("A estação de chegada não pode ser igual à de partida!\n");
        return NULL;
      }

      for (int e = 0; e < posicaoEstacao; e++)
      {

        if (estacoes[e]->codigo != partida)
        {
          partidaVezes++;
          if (partidaVezes == posicaoEstacao)
          {
            printf("Estação de partida não existe\n");
            return NULL;
          }
        }

        if (estacoes[e]->codigo != chegada)
        {
          chegadaVezes++;
          if (chegadaVezes == posicaoEstacao)
          {
            printf("Estação de chegada não existe\n");
            return NULL;
          }
        }
      }

      if (partidaVezes == posicaoEstacao - 1 && chegadaVezes == posicaoEstacao - 1)
      {

        estacao estPartida;
        estPartida = (estacao)malloc(sizeof(estacaoInfo));
        estacao estDestino;
        estDestino = (estacao)malloc(sizeof(estacaoInfo));

        if (posicaoViagem == 0)
        {

          for (int k = 0; k < posicaoEstacao; k++)
          {

            if (estacoes[k]->codigo == partida)
            {
              estPartida->codigo = partida;
            }
            if (estacoes[k]->codigo == chegada)
            {
              estDestino->codigo = chegada;
            }
          }

          viagem v = criaViagem(estPartida, estDestino);

          passageiros[i]->pontos += v->km;
          passageiros[i]->codigoEstacao = estDestino->codigo;
          printf("viagem novo criada\n");
          return v;
        }
        else
        {

          for (int j = 0; j < posicaoViagem + 1; j++)
          {

            if (viagens[j]->origem == partida &&
                viagens[j]->destino == chegada)
            {

              passageiros[i]->pontos += viagens[j]->km;
              passageiros[i]->codigoEstacao = chegada;
              printf("viagem penas registada\n");
              return NULL;
            }
            else if (j == posicaoViagem - 1)
            {

              for (int k = 0; k < posicaoEstacao; k++)
              {

                if (estacoes[k]->codigo == partida)
                {
                  estPartida->codigo = partida;
                }
                if (estacoes[k]->codigo == chegada)
                {
                  estDestino->codigo = chegada;
                }
              }

              viagem v = criaViagem(estPartida, estDestino);

              passageiros[i]->pontos += v->km;
              passageiros[i]->codigoEstacao = estDestino->codigo;
              printf("viagem novo criada e registada\n");
              return v;
            }
          }
        }
      }
      break;
    }
    else if (i == posicaoPassageiro - 1)
    {
      printf("Este email não está alucado a nenhum passageiro\n");
      return NULL;
    }
  }
}
