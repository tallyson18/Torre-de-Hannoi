#include "monges.c"
#include "torres.c"
#include "jogo.c"
int main(void){
	fila *f;
	int inicio =0;
	int op;
	setlocale(LC_ALL,"portuguese");
	printf("Bem vindo.\n");
	printf("Aguarde enquanto preparamos tudo...\n");
	f=criar_fila();
	printf("Criando a torre...\n");
	T_torre *t1=criar_torre(1);
	T_torre *t2=criar_torre(2);
	T_torre *t3=criar_torre(3);
	printf("Torres criadas.\n");
	printf("Inserindo discos...\n");
	criar_discos(t1);
	printf("Discos inseridos....\n");
	system("cls");
	do{
		printf("Escolha sua opção.\n");
		printf("--------------------------------------------\n");
		printf("	0: Sair.\n");
		if(f->primeiro!= NULL){
			printf("	1: Cadastrar mais jogadores.\n");
		}
		else{
			printf("	1: Cadastrar os jogadores.\n");	
		}
		printf("	2: Imprimir torres.\n");
		printf("	3: Para iniciar o jogo.\n");
		printf("	4: Para continuar o jogo.\n");
		printf("--------------------------------------------\n");
		scanf("%d",&op);
		printf("Opção escolhida: %d.\n",op);
		switch(op){
			case 1: 
			if(inicio==0){
				novo_monge(f);
				system ("cls");
				print(f);
			}else{
				printf("O jogo já foi iniciado.\n");
			}
			break;
			case 2: 
				imprime_torre(t1,t2,t3);
				printf("\n");
			break;
			case 3:
				if(f->primeiro!=NULL){
					if(inicio==0){
						system ("cls");
						printf("Iniciado...\n");
						jogar(t1,t2,t3,f);
						inicio=1;
						imprime_torre(t1,t2,t3);
						system("pause");
						system("cls");
						break;
	
					}
					printf("O jogo já foi iniciado.\n");
				}
				else{
					printf("Cadastre pelo menos um jogador para iniciar.\n");
				}
			break;
			case 4:
				if(inicio!=0){
					system ("cls");
					printf("Carregando...\n");
					continuar_jogo(t1,t2,t3,f);
					break;
				}
				printf("Inicie o jogo na opção 3.\n");
			break;
			case 0: 
				system ("cls");
				printf("Obrigado por jogar, até a próxima...\n");
				return;
			break;
			default:
				printf("Opção Inválida. Escolha novamente...\n");
			break;
		}
		system("pause");
		system ("cls");
	}
	while(op!=0);
}
