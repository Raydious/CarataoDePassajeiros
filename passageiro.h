#ifndef _H_passageiro
#define _H_passageiro

typedef struct _passagerio{

char* nome;
char* email;
int size;
int pontos;
int codigoEstacao;

}passagerioInfo, *passageiro;

passageiro criaPassageiro(int posicaoPassageiro, passageiro passageiros[]);

void destroiPassageiro(passageiro p);

void listaPassageiros(passageiro p[], int posicaoPassageiro);

#endif