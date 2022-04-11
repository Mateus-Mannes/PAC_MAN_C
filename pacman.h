#ifndef _PACMAN_H_
#define _PACMAN_H_
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

void fantasmas();
void move(char direcao);
int acabou();
int ehdirecao(char direcao);
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay, int qtd);
#endif


