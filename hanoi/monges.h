#ifndef _MONGE_TAD_H
#define _MONGE_TAD_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>
struct monge;
struct monges;
struct fila_monges;
struct fila_monges *criar_fila();
bool is_empty(struct fila_monges *);
void novo_monge(struct fila_monges *);
struct monges*cadastra_monge();
void print(struct fila_monges *);
void rotaciona_monges(struct fila_monges *);
#endif
