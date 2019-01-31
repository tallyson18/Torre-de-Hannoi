#include "torres.h"
typedef struct disco{
	int tamanho_do_disco;
	struct disco *abaixo;
}T_disco;

typedef struct torre{
	T_disco *base;
	T_disco *top;
	int id;
}T_torre;

T_torre *criar_torre(int id_torre){
	T_torre *new_torre=(T_torre*) malloc (sizeof(T_torre));
	if(new_torre != NULL){
		new_torre->base=NULL;
		new_torre->top=NULL;
		new_torre->id=id_torre;
		return new_torre;
	}
}

void criar_discos(T_torre *t){
	int i;
	if(t!=NULL){
		for(i=7;i>=1;i--){
				T_disco *novo_disco=(T_disco*) malloc (sizeof(T_disco));
				novo_disco->abaixo=NULL;
				if(novo_disco!= NULL){
					novo_disco->tamanho_do_disco=i;	
					novo_disco->abaixo=t->top;
					t->top=novo_disco;
					printf("Inserindo na torre o disco %d.\n",i);
					printf("\n");
				}
		}
		return;
	}
	system("cls");
	printf("Não existe torre para colocar os discos.\n");
}

void imprime_torre(T_torre *t1,T_torre *t2,T_torre *t3){
	int i,j;
	T_disco *aux[3];
	aux[0]=t1->top;
	aux[1]=t2->top;
	aux[2]=t3->top;
	if(t1!= NULL || t2!= NULL || t3!= NULL){
		j=0;
		while(aux[0]!= NULL || aux[1]!= NULL || aux[2]!= NULL ){
			if(j==0){
				printf("*********** TORRE 1************");
				printf("			");
				printf("*********** TORRE 2************");
				printf("			");
				printf("*********** TORRE 3************");
				printf("\n");
				j=1;
			}
			printf("	");
			if(aux[0]!=NULL){
				for(i=0;i<aux[0]->tamanho_do_disco;i++){
					printf("-");
				}
				aux[0]=aux[0]->abaixo;
			}
			printf("					");
			if(aux[1]!=NULL){
				for(i=0;i<aux[1]->tamanho_do_disco;i++){
					printf("-");
				}
				aux[1]=aux[1]->abaixo;
			}
			printf("							");
			
			if(aux[2]!=NULL){
				for(i=0;i<aux[2]->tamanho_do_disco;i++){
					printf("-");
				}
				aux[2]=aux[2]->abaixo;
			}
			printf("												");
			printf("\n");
		}
		return;
	}
	printf("Torre vazia.\n");
}
