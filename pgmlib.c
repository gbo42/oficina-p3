//Guilherme Bastos de Oliveira

#include "pgmlib.h"
#include <ctype.h>
#include <stdlib.h>

//função para pular a linha de comentário
void pulaLinha(FILE *fi){
	char ch = fgetc(fi);
	//enquanto receber um '#' no primeiro char, espera até econtrar o fim da linha
 	while(ch == '#' || isspace(ch)){
		while(ch != '\n'){
			ch = fi?fgetc(fi):fgetc(stdin);
		}
		ch = fi?fgetc(fi):fgetc(stdin);
	}

	//volta o ponteiro do arquivo em 1, para compensar a leitura do char extra
	fseek(fi, -1, SEEK_CUR);
}

void alocaPGM(ipgm *img){
	//aloca vetor de (unsigned char *) linhas para imagem
	img->matriz = (unsigned char **)malloc(img->lin * sizeof(unsigned char *));
	for(int i = 0; i < img->lin; i++){
		//aloca vetor de (unsigned char) colunas para a imagem
		img->matriz[i] = (unsigned char *)malloc(img->col * sizeof(unsigned char *));
	}
}

void lerPGM(ipgm *img, FILE *fi){
	//pula as linhas de cometário e lê as 4 primeiras informações do arquivo PGM
	pulaLinha(fi);
	fscanf(fi, "P%u", (unsigned int *)&img->tipo);
	pulaLinha(fi);
	fscanf(fi, "%u %u", (unsigned int *)&img->col, (unsigned int *)&img->lin);
	pulaLinha(fi);
	fscanf(fi, "%u", (unsigned int *)&img->cinzaMax);
	pulaLinha(fi);

	alocaPGM(img);

	//testa o tipo da imagem
	switch (img->tipo) {
		case 2:
			//para pgm plain lê número por número da matriz
			for (int i = 0; i < img->lin; i++) {
				for (int j = 0; j < img->col; j++) {
					fscanf(fi, "%u", (unsigned int *)&img->matriz[i][j]);
				}
			}
		break;
		case 5:
			//para pgm raw lê blocos de tamanho da linha, e salva na matriz
			/*como a imagem pode ter apenas 1 byte por pixel e o tipo char tem um byte
			 *podemos salvar diretamente na memória a linha lida*/
			for(int i = 0; i < img->lin; i++){
				fread(img->matriz[i], sizeof(unsigned char), img->col, fi);
			}
		break;
		default:
			//para qualquer outra informação lida no tipo, resulta em erro
			perror("ERRO: Formato de imagem não reconhecido. \n");
			exit(1);
		break;
	}
}

void imprimePGM(ipgm *img, FILE *fi){
	//imprime o cabeçalho do arquivo pgm
	fprintf(fi, "P2\n");
	fprintf(fi, "%d %d\n", img->col, img->lin);
	fprintf(fi, "%hd\n", img->cinzaMax);

	//imprime a matriz da imagem pixel por pixel
	for (int i = 0; i < img->lin; i++) {
		for (int j = 0; j < img->col; j++) {
			fprintf(fi, "%u ", img->matriz[i][j]);
		}
		fprintf(fi, "\n");
	}
}
