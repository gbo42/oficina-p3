//Guilherme Bastos de Oliveira

#include "pgmlib.h"
#include "args.h"
#include "coord.h"

FILE *input, *output;

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

	//calcula a média do miolo
	for(int i = 1; i < imagem.lin-1; i++){
		for(int j = 1; j < imagem.col-1; j++){
			int temp = 0;
			//salva a soma de todos os pixels vizinhos de um pixel
			for(int k = 0; k < 9; k++){
				temp += imagem.matriz[i+linm[k]][j+colm[k]];
			}
			//salva a media da soma na copia
			copia.matriz[i][j] = temp/9;
		}
	}

	//calcula a média das bordas laterais
	for(int i = 1; i < imagem.lin-1; i++){
		int temp = 0, temp2 = 0;
		//salva a soma de todos os pixels vizinhos de um pixel
		for(int k = 0; k < 6; k++){
			temp = imagem.matriz[i+linv[k]][0+cole[k]];
			temp2 = imagem.matriz[i+linv[k]][copia.col-1+cold[k]];
		}
		//salva a media da soma na copia
		copia.matriz[i][0] = temp/6;
		copia.matriz[i][copia.col-1] = temp2/6;
	}

	//calcula a média dos polos
	for(int j = 1; j < imagem.col-1; j++){
		int temp = 0, temp2 = 0;
		//salva a soma de todos os pixels vizinhos de um pixel
		for(int k = 0; k < 6; k++){
			temp += imagem.matriz[0+lint[k]][j+colp[k]];
			temp2 += imagem.matriz[imagem.lin-1+linb[k]][j+colp[k]];
		}
		//salva a media da soma na copia
		copia.matriz[0][j] = temp/6;
		copia.matriz[imagem.lin-1][j] = temp2/6;
	}

	//calcula a média dos cantos
	int temp = 0, temp2 = 0, temp3 = 0, temp4 = 0;
	//salva a soma de todos os pixels vizinhos de um pixel
	for(int k = 0; k < 4; k++){
		temp += copia.matriz[0+linct[k]][0+colce[k]];
		temp2 += copia.matriz[0+linct[k]][imagem.col-1+colcd[k]];
		temp3 += copia.matriz[imagem.lin-1+lincb[k]][0+colce[k]];
		temp4 += copia.matriz[imagem.lin-1+lincb[k]][imagem.col-1+colce[k]];
	}
	//salva a media da soma na copia
	copia.matriz[0][0] = temp/4;
	copia.matriz[0][imagem.col-1] = temp2/4;
	copia.matriz[imagem.lin-1][0] = temp3/4;
	copia.matriz[imagem.lin-1][imagem.col-1] = temp4/4;

	imprimePGM(&copia, output);
	return 0;
}
