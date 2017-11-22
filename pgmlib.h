//Guilherme Bastos de Oliveira

#include <stdio.h>

//define o tipo e estrutura para a imagem pgm
typedef struct struct_pgm {
    unsigned char tipo;
    int lin;
    int col;
    unsigned char cinzaMax;
    unsigned char **matriz;
} ipgm;

//função para ler PGM do arquivo
void lerPGM(ipgm *img, FILE *fi);

//função para imprimir PGM no arquivo
void imprimePGM(ipgm *img, FILE *fi);

//função para alocar memória para a imagem
void alocaPGM(ipgm *img);
