//Guilherme Bastos de Oliveira

#include <stdlib.h>
#include <string.h>
#include "pgmlib.h"
#include "args.h"
#include "coord.h"

FILE *input, *output;

//função de comparação para o qsort
int compara(const void *a, const void *b){
    return *(unsigned char *)a - *(unsigned char *)b;
}

int main(int argc, char **argv){
	//declaração de variáveis
	ipgm imagem, copia;

	//abre arquivo de entrada
	arquivoEntrada(argc, argv, &input);
	//salva o conteúdo na memória
	lerPGM(&imagem, input);
	//fecha o arquivo
	fclose(input);

	arquivoSaida(argc, argv, &output);

	//copia as informação da imagem de origem para a copia
	copia.col = imagem.col;
	copia.lin = imagem.lin;
	copia.cinzaMax = imagem.cinzaMax;

	alocaPGM(&copia);

	//calcula a mediana do miolo
    for(int i = 1; i < imagem.lin-1; i++){
		for(int j = 1; j < imagem.col-1; j++){
			unsigned char vet[9];
			//salva os valores de pixels vizinhos de um pixel em um vetor
			for(int k = 0; k < 9; k++){
				vet[k] = imagem.matriz[i+linm[k]][j+colm[k]];
			}

			//ordena os vetores
			qsort(vet, strlen((const char *)vet), sizeof(unsigned char), compara);
			//salva a mediana dos vetores na copia
			copia.matriz[i][j] = vet[4];
		}
	}

	//calcula a mediana das bordas laterias
	for(int i = 1; i < imagem.lin-1; i++){
        unsigned char vet[6], vet2[6];
		//salva os valores de pixels vizinhos de um pixel em um vetor
		for(int k = 0; k < 6; k++){
			vet[k] = imagem.matriz[i+linv[k]][0+cole[k]];
			vet2[k] = imagem.matriz[i+linv[k]][copia.col-1+cold[k]];
		}
		//ordena os vetores
        qsort(vet, strlen((const char *)vet), sizeof(unsigned char), compara);
		copia.matriz[i][copia.col-1] = (vet2[2] + vet2[3])/2;
        qsort(vet2, strlen((const char *)vet2), sizeof(unsigned char), compara);

		//salva a mediana dos vetores na copia
        copia.matriz[i][0] = (vet[2] + vet[3])/2;
	}

	//calcula a mediana dos polos
	for(int j = 1; j < imagem.col-1; j++){
        unsigned char vet[6], vet2[6];
		//salva os valores de pixels vizinhos de um pixel em um vetor
        for(int k = 0; k < 6; k++){
			vet[k] = imagem.matriz[0+lint[k]][j+colp[k]];
			vet2[k] = imagem.matriz[imagem.lin-1+linb[k]][j+colp[k]];
		}
		//ordena os vetores
        qsort(vet, strlen((const char *)vet), sizeof(unsigned char), compara);
		qsort(vet2, strlen((const char *)vet2), sizeof(unsigned char), compara);

		//salva a mediana dos vetores na copia
        copia.matriz[0][j] = (vet[2]+vet[3])/2;
        copia.matriz[imagem.lin-1][j] = (vet[2]+vet[3])/2;
	}


	//calcula a mediana dos cantos
    int vet[4], vet2[4], vet3[4], vet4[4];
	//salva os valores de pixels vizinhos de um pixel em um vetor
	for(int k = 0; k < 4; k++){
		vet[k] = copia.matriz[0+linct[k]][0+colce[k]];
		vet2[k]  = copia.matriz[0+linct[k]][imagem.col-1+colcd[k]];
		vet3[k] = copia.matriz[imagem.lin-1+lincb[k]][0+colce[k]];
		vet4[k] = copia.matriz[imagem.lin-1+lincb[k]][imagem.col-1+colce[k]];
	}

	//ordena os vetores
    qsort(vet, strlen((const char *)vet), sizeof(unsigned char), compara);
    qsort(vet2, strlen((const char *)vet2), sizeof(unsigned char), compara);
    qsort(vet3, strlen((const char *)vet3), sizeof(unsigned char), compara);
    qsort(vet4, strlen((const char *)vet4), sizeof(unsigned char), compara);

	//salva a mediana dos vetores na copia
    copia.matriz[0][0] = (vet[1]+vet[2])/2;
	copia.matriz[0][imagem.col-1] = (vet2[1]+vet2[2])/2;
    copia.matriz[imagem.lin-1][0] = (vet3[1]+vet3[2])/2;
    copia.matriz[imagem.lin-1][imagem.col-1] = (vet4[1]+vet4[2])/2;

	imprimePGM(&copia, output);
	return 0;
}
