//Guilherme Bastos de Oliveira

#include "pgmlib.h"
#include "args.h"

FILE *input, *output;

int main(int argc, char **argv){
	//declaração de variáveis
	ipgm imagem;

	//abre arquivo de entrada
	arquivoEntrada(argc, argv, &input);
	//salva o conteúdo na memória
	lerPGM(&imagem, input);
	//fecha o arquivo
	fclose(input);

	arquivoSaida(argc, argv, &output);

	//para cada pixel da imagem salva o cinza máximo (branco) menos o valor daquele pixel
	for(int i = 0; i < imagem.lin; i++){
		for(int j = 0; j < imagem.col; j++){
			imagem.matriz[i][j] = imagem.cinzaMax - imagem.matriz[i][j];
		}
	}

	imprimePGM(&imagem, output);
	return 0;
}
