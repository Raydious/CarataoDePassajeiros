#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "brindes.h"
#include "estacao.h"

void incrementaBrindes(int posicaoEstacao, estacao estacoes[])
{
    if (posicaoEstacao == 0)
    {
        printf("Não há estacoes registadas\n");
    }
    else
    {

        int codigo = 0;
        int brindes = 0;
        printf("******************* -> ESTAÇÕES <- *******************\n\n");
        for (int i = 0; i < posicaoEstacao; i++)
        {

            printf("%s / ", estacoes[i]->nome);
            printf("%s -> ", estacoes[i]->localidade);
            printf("%d brindes", estacoes[i]->brindes);
            printf("  ||  CODIGO: %d", estacoes[i]->codigo);
            printf("\n\n****************************************\n\n");
        }

        printf("Em que estação queres incrementar os brindes (COLOCA O CODIGO DA ESTAÇÃO): ");
        scanf(" %d", &codigo);

        for (int i = 0; i < posicaoEstacao; i++)
        {

            if (estacoes[i]->codigo == codigo)
            {

                printf("Quantos brindes queres incrementar nesta estação: ");
                if (scanf(" %d", &brindes) == 1)
                {
                    estacoes[i]->brindes += brindes;
                    printf("Brindes adicionados com sucesso!!\n");
                    printf("A estação %s tem agora %d brindes\n", estacoes[i]->nome, estacoes[i]->brindes);
                }
                else
                {
                    printf("A quantidade de brindes tem de ser um numero inteiro!\n");
                }
            }
            else if (i == posicaoEstacao - 1)
            {

                printf("Não existe nenhuma estação com esse numero!\n");
            }
        }
    }
}

void escolheBrindes(int posicaoEstacao, int posicaoPassageiro, estacao estacoes[], passageiro passageiros[])
{
    if (posicaoEstacao == 0)
    {
        printf("Não existem estações registadas!\n");
    }
    else if (posicaoPassageiro == 0)
    {
        printf("Não existem passajeiros registados!\n");
    }
    else
    {
        char email[50];
        int quantidade;
        int total;
        printf("Email do passageiros que vai comprar brindes: ");
        scanf(" %s", email);
        printf("Quantos brindes queres comprar: ");
        if (scanf(" %d", &quantidade) != 1)
        {
            printf("A quantidade de brindes tem de ser um numero inteiro!\n");
        }
        else
        {

            if (quantidade > 1000)
            {
                printf("ERRO!! - Não podes comprar tantos brindes em uma só compra!\n");
                return NULL;
            }

            for (int i = 0; i < posicaoPassageiro; i++)
            {

                if (strcmp(passageiros[i]->email, email) == 0)
                {

                    estacao e;
                    e = (estacao)malloc(sizeof(estacaoInfo));

                    for (int j = 0; j < posicaoEstacao; j++)
                    {
                        if (estacoes[j]->codigo == passageiros[i]->codigoEstacao)
                        {

                            e->codigo = estacoes[j]->codigo;
                            e->localidade = estacoes[j]->localidade;
                        }
                        else if (passageiros[i]->codigoEstacao > 500)
                        {
                            e->codigo = 11111111111111111111111;
                            e->localidade = "------------------------------------";
                        }
                    }

                    for (int j = 0; j < posicaoEstacao; j++)
                    {
                        if (estacoes[j]->codigo == e->codigo && estacoes[j]->brindes > 0)
                        {

                            total = 300 * quantidade;
                            printf("O brinde fica a %d pontos, queres trocar? (Sim: Y / Não: N): ", total);
                            char simnao[1];
                            scanf(" %s", simnao);
                            while (simnao != "y" || simnao != "n")
                            {
                                

                                if (strcmp(simnao, "y") == 0)
                                {

                                    if (passageiros[i]->pontos >= total)
                                    {

                                        estacoes[j]->brindes -= quantidade; //NAO ESTÁ A ADICIONAR PONTOS A BRINDES INSERIDOS
                                        passageiros[i]->pontos -= total;
                                        estacoes[j]->brindesVendidos += quantidade;
                                        printf("Brinde comprado com sucesso, tens agora %d pontos\n", passageiros[i]->pontos);
                                    }
                                    else
                                    {
                                        printf("Não tens pontos suficientes para trocar pelo brinde :( (FAZ MAIS VIAGENS PARA GANHARES MAIS PONTOS)\n");
                                    }
                                    break;
                                }
                                else if (strcmp(simnao, "n") == 0)
                                {

                                    printf("Fica para a proxima! :D\n");
                                    break;
                                }
                                printf("Comando incorreto!! (TROCAR PONTOS -> Y || NÃO TROCAR -> N)");
                                scanf(" %s", simnao);
                            }
                            break;
                        }
                        else if (strcmp(estacoes[j]->localidade, e->localidade) == 0 && estacoes[j]->brindes > 0)
                        {

                            total = 400 * quantidade;
                            printf("O brinde fica a %d pontos, queres trocar? (Sim: Y / Não: N): ", total);
                            char simnao[1];
                            scanf(" %s", simnao);
                            while (simnao != "y" || simnao != "n")
                            {

                                if (strcmp(simnao, "y") == 0)
                                {

                                    if (passageiros[i]->pontos >= total)
                                    {

                                        estacoes[j]->brindes -= quantidade;
                                        passageiros[i]->pontos -= total;
                                        estacoes[j]->brindesVendidos += quantidade;
                                        ;
                                        printf("Brinde comprado com sucesso, tens agora %d pontos\n", passageiros[i]->pontos);
                                    }
                                    else
                                    {
                                        printf("Não tens pontos suficientes para trocar pelo brinde :( (FAZ MAIS VIAGENS PARA GANHARES MAIS PONTOS)\n");
                                    }
                                    break;
                                }
                                else if (strcmp(simnao, "n") == 0)
                                {

                                    printf("Fica para a proxima! :D\n");
                                    break;
                                }
                                printf("Comando incorreto!! (TROCAR PONTOS -> Y || NÃO TROCAR -> N)");
                                scanf(" %s", simnao);
                            }
                            break;
                        }
                        else if (j == posicaoEstacao - 1)
                        {
                            for (int k = 0; k < posicaoEstacao; k++)
                            {
                                if (estacoes[k]->brindes > 0)
                                {

                                    if (strcmp(e->localidade, "------------------------------------") == 0)
                                    {
                                        printf("Ainda não fizeste nenhuma viagem, ou seja:\n");
                                    }

                                    total = 500 * quantidade;
                                    printf("O brinde fica a %d pontos, queres trocar? (Sim: Y / Não: N): ", total);
                                    char simnao[1];
                                    scanf(" %s", simnao);
                                    while (simnao != "y" || simnao != "n")
                                    {

                                        if (strcmp(simnao, "y") == 0)
                                        {

                                            if (passageiros[i]->pontos >= total)
                                            {

                                                estacoes[j]->brindes -= quantidade;
                                                passageiros[i]->pontos -= total;
                                                estacoes[j]->brindesVendidos += quantidade;
                                                printf("Brinde comprado com sucesso, tens agora %d pontos\n", passageiros[i]->pontos);
                                            }
                                            else
                                            {
                                                printf("Não tens pontos suficientes para trocar pelo brinde :( (FAZ MAIS VIAGENS PARA GANHARES MAIS PONTOS)\n");
                                            }
                                            break;
                                        }
                                        else if (strcmp(simnao, "n") == 0)
                                        {

                                            printf("Fica para a proxima! :D\n");
                                            break;
                                        }
                                        printf("Comando incorreto!! (TROCAR PONTOS -> Y || NÃO TROCAR -> N)");
                                        scanf(" %s", simnao);
                                    }
                                    break;
                                }
                                else if (k == posicaoEstacao - 1)
                                {
                                    printf("De momento não há brindes em nenhuma estação!\n");
                                }
                            }
                        }
                    }
                }
                else if (i == posicaoPassageiro - 1)
                {
                    printf("Este EMAIL não está assuciado a nenhum passageiro!\n");
                }
            }
        }
    }
}

void topBrindes(int posicaoEstacao, estacao e[])
{
    int num = 0;

    for (int i = 0; i < posicaoEstacao; i++)
    {
        if (e[i]->brindesVendidos == 0)
        {
            num++;
        }
    }

    if (posicaoEstacao == 0)
    {

        printf("Ainda não foram adicionadas estações!\n");
    }
    else if (num == posicaoEstacao)
    {

        printf("Ainda não foram distribuidos brindes!\n");
    }
    else
    {
        typedef struct _localidades
                {

                    char *localidade;
                    int brindesVendidosLocal;

                } localidadesinfo, *localidades;
        localidades l;

        for (int i = 0; i < posicaoEstacao; i++)
        {

            for (int j = i + 1; j < posicaoEstacao; j++)
            {

                typedef struct _localidades
                {

                    char *localidade;
                    int brindesVendidosLocal;

                } localidadesinfo, *localidades;

                estacao est;
                l = (localidades)malloc(sizeof(localidadesinfo));
                l->localidade = malloc(100 * sizeof(char));
                l->localidade = e[i]->localidade;
                l->brindesVendidosLocal = 0;
                localidades localidade[100] = {NULL};
                int posicaoLocalidade = 0;
                localidades loc;

                if (e[i]->brindesVendidos < e[j]->brindesVendidos)
                {

                    est = e[i];
                    e[i] = e[j];
                    e[j] = est;
                }

                int exists = 0;
                for (int k = 0; i < 100; i++)
                {
                    if (e[i]->localidade == localidade[k])
                    {
                        exists = 1;
                        localidade[k]->brindesVendidosLocal++;
                        free(l);
                    }
                }
                if (exists == 0)
                {
                    localidade[posicaoLocalidade] = l;
                    posicaoLocalidade++;

                }

                if (l[i].brindesVendidosLocal < l[j].brindesVendidosLocal)
                {

                //     loc = l[i];
                //     l[i] = l[j];
                //     l[j] = loc;
                 }
            }
        }

        printf("\n********************** -> TOP DE BRINDES ESTAÇÕES <- **************************\n");

        for (int i = 0; i < posicaoEstacao; i++)
        {

            printf("%d - %s / %s -> %d\n", i + 1, e[i]->nome, e[i]->localidade, e[i]->brindesVendidos);
            printf("\n------------------------------------------------------------------------\n");
        }

        printf("\n********************** -> TOP DE BRINDES LOCALIDADES <- **************************\n");

        for (int i = 0; i < posicaoEstacao; i++)
        {

            printf("%d - %s -> %d\n", i + 1, l[i].localidade, l[i].brindesVendidosLocal);
            printf("\n------------------------------------------------------------------------\n");
        }
    }
}
