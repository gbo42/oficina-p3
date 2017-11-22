//Guilherme Bastos de Oliveira

//variação de coordenadas
//variação do miolo
char linm[9] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};
char colm[9] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};
//variação das linhas nas verticais
char linv[6] = {-1, -1, 0, 0, +1, +1};
//variação da coluna na borda esquerda
char cole[6] = {0, +1, 0, +1, 0, +1};
//variação da coluna na borda direita
char cold[6] = {-1, 0, -1, 0, -1, 0};
//variação da coluna dos polos
char colp[6] = {-1, 0, +1, -1, 0, +1};
//variação da linha do topo
char lint[6] = {0, 0, 0, +1, +1, +1};
//variação da linha de baixo
char linb[6] = {-1, -1, -1, 0, 0, 0};
//variação da linha dos cantos do topo
char linct[4] = {0, 0, +1, +1};
//variação da linha dos cantos de baixo
char lincb[4] = {-1, -1, 0, 0};
//variação da coluna dos cantos da esquerda
char colce[4] = {0, +1, 0, +1};
//variação da coluna dos cantos da direita
char colcd[4] = {-1, 0, -1, 0};
