#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>

int ehPersonagem(MAPA* m, char personagem,int x, int y){
    return m->matriz[x][y] == personagem;
}

int ehParede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int podeAndar(MAPA* m, char personagem, int x, int y){
    return ehvalida(m, x, y) && !ehParede(m, x, y) && !ehPersonagem(m, personagem,x, y);
}

void copiaMapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocaMapa(destino);
    for(int i = 0; i < destino->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xorigem][yorigem] = VAZIO;
    m->matriz[xdestino][ydestino] = personagem;
}

int ehvazia(MAPA* m, int x, int y){
    return m->matriz[x][y] == VAZIO;
}

int ehvalida(MAPA* m, int x, int y){
    return x < m->linhas && y < m->colunas;
}

int encontraMapa(MAPA* m, POSICAO* p, char c){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

void alocaMapa(MAPA* m){
    m->matriz = malloc(sizeof(int*) * m->linhas);
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void liberaMapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void lerMapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Erro ao acessar o mapa");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocaMapa(m);
    for(int i = 0; i < m->linhas; i++){
        fscanf(f," %s", m->matriz[i]);
    }
    fclose(f);
}

