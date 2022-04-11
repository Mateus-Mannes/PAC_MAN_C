#ifndef _MAPA_H_
#define _MAPA_H_
#define HEROI '@'
#define FANTASMA 'F'
#define PILULA 'P'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

int ehPersonagem(MAPA* m, char personagem,int x, int y);
int ehParede(MAPA* m, int x, int y);
int podeAndar(MAPA* m, char personagem, int x, int y);
void copiaMapa(MAPA* destino, MAPA* origem);
void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
int ehvazia(MAPA* m, int x, int y);
int ehvalida(MAPA* m, int x, int y);
int encontraMapa(MAPA* m, POSICAO* p, char c);
void liberaMapa(MAPA* m);
void alocaMapa(MAPA* m);
void lerMapa(MAPA* m);

#endif