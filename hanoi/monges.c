#include "monges.h"
typedef struct monge{
	char nome[50];
	int id;
	int num_jogadas;
}Monge;
typedef struct monges{
	Monge jogador;
	struct monges *prox;
	struct monges *ant;
}Monges;
typedef struct fila_monges{
	Monges *primeiro;
	Monges *ultimo;
	int total;
	int id;
}fila;
fila *criar_fila(void){
	fila *f=(fila*)malloc(sizeof(fila));
	if(f != NULL){
		f->primeiro=NULL;
		f->ultimo=NULL;
		f->total=0;
		f->id=0;
		return f;
	}
}
bool is_empty(fila *f){
	if(f->primeiro==NULL){
		return true;
	}
	return false;
}
Monges *cadastra_monge(){
	Monges *novo=(Monges*)malloc(sizeof(Monges));
	if(novo != NULL){
		novo->ant=NULL;
		novo->prox=NULL;
		novo->jogador.num_jogadas=0;
		return novo;
	}
}
void novo_monge(fila *f){
 	Monges *m;
 	if(f!= NULL){
	 	m=cadastra_monge();
	 	f->total++;
	 	f->id++;
	 	printf("Vamos Cadastrar o novo monge.\n");
	 	printf("Digite o nome:\n");
	 	fflush(stdin);
	 	gets(m->jogador.nome);
	 	m->jogador.id=f->id;
 		if(is_empty(f)){
		 	f->primeiro=m;
			f->ultimo=m;	
 			m->ant=f->ultimo;
 			m->prox=f->primeiro;
		}
		f->primeiro->ant=m;
		f->ultimo->prox=m;
 		m->prox=f->primeiro;
 		m->ant=f->ultimo;
		f->ultimo=m;
		printf("Monge cadastrado com sucesso.\n");
		return;
	}
	printf("Cadastre primeiro a fila.\n");
	return;
 }

void print(fila *f){
	Monges *aux=f->primeiro;
	int i;
	if(!is_empty(f)){
		for(i=0;i<f->total;i++){
			printf("Nome do monge: %s.\n",aux->jogador.nome);
			printf("ID do monge: %d.\n",aux->jogador.id);
		//	printf("Monge Anterior : %d.\n",aux->ant->jogador.id);
		//	printf("Próximo Monge: %d.\n",aux->prox->jogador.id);
			printf("\n\n\n");
			aux=aux->prox;
		}
		return;
	}
	printf("Vazio...\n");
	return;
}

void rotaciona_monges(fila *f){
		Monges *m;
		m=f->ultimo;
		f->primeiro=f->primeiro->prox;
		f->ultimo=f->ultimo->prox;
		f->ultimo->ant=m;
}
