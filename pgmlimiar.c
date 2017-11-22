//Guilherme Bastos de Oliveira

#include "pgmlib.h"
#include "args.h"

FILE *input, *output;

int main(int argc, char **argv){
	//declaração de variável
	ipgm imagem;

	//abre arquivo de entrada
	arquivoEntrada(argc, argv, &input);
	//salva o conteúdo na memória
	lerPGM(&imagem, input);
	//fecha o arquivo
	fclose(input);

	arquivoSaida(argc, argv, &output);

	//definição do limiar
	double lim = limiar(argc, argv) * imagem.cinzaMax;

	/*para cada pixel da imagem testa se é menor que o limiar, se for salva 0
	 *se não salva o valor de cinza máximo (branco)*/
	for(int i = 0; i < imagem.lin; i++){
		for(int j = 0; j < imagem.col; j++){
			imagem.matriz[i][j] = imagem.matriz[i][j]>lim?imagem.cinzaMax:0;
		}
	}

	imprimePGM(&imagem, output);
	return 0;
}
