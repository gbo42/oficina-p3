//Guilherme Bastos de Oliveira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double limiar(int quant, char **entradas){
	//define limiar padrão
	double lim = 0.5;
	//procura -l nos argumentos
	for(int i = 1; i < quant-1; i++){
		if(!strcmp(entradas[i], "-l")){
			//se encontrou -l salva o valor recibo
			sscanf(entradas[i+1], "%lf", &lim);
		}
	}

	//retorna o limiar
	return lim;
}

void arquivoEntrada(int quant, char **entradas, FILE **in){
	//procura pelo parâmetro -o
	for(int i = 1; i < (quant-1); i++){
		//caso seja encontrado -i, abre o arquivo passado
		if(!strcmp(entradas[i],"-i")){
			*in = fopen(entradas[i+1], "r");
			if(!*in){
				perror("ERRO: Não foi possível abrir arquivo de entrada");
				exit(1);
			}
		}
	}

	//se não foi passado arquivo, usa a entrada padrão
	if(!*in){
		*in = stdin;
	}
}

void arquivoSaida(int quant, char **entradas, FILE **out){
	//procura pelo parâmetro -o
	for(int i = 1; i < (quant-1); i++){
		//caso seja encontrado -o, abre o arquivo passado
		if(!strcmp(entradas[i], "-o")){
			*out = fopen(entradas[i+1], "w");
			if(!*out){
				perror("ERRO: Não foi possível abrir/criar arquivo de saida");
				exit(1);
			}
		}
	}

	//se não foi passado arquivo, usa a saída padrão
	if(!*out){
		*out = stdout;
	}
}
