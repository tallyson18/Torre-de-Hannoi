#ifndef _TORRE_TAD_H
#define _TORRE_TAD_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>
struct disco;
struct torre;
struct torre *criar_torre(int);
void criar_discos(struct torre *);
void imprime_torre(struct torre *,struct torre *,struct torre *);
#endif
