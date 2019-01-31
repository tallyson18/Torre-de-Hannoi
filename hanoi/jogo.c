trofeu(){
	printf("                                \n");
    printf("\t\t\t\t     ______________________\n");
    printf("\t\t\t\t   /|                    |\\    \n");
    printf("\t\t\t\t /  |                    | \\   \n");
    printf("\t\t\t\t |  |                    |  |   \n");
    printf("\t\t\t\t  \\ |                    | /   \n");
    printf("\t\t\t\t   \\|                    |/    \n"); 
    printf("\t\t\t\t    |                    |      \n");
    printf("\t\t\t\t     \\                  /      \n");
    printf("\t\t\t\t      \\                /       \n");
    printf("\t\t\t\t       \\              /        \n");
    printf("\t\t\t\t        |            |          \n");
    printf("\t\t\t\t         |          |           \n");
    printf("\t\t\t\t          |        |            \n");
    printf("\t\t\t\t           |      |             \n");
    printf("\t\t\t\t           |      |             \n");
    printf("\t\t\t\t         __|______|__        \n");
}
jogar(T_torre *t1,T_torre *t2, T_torre *t3,fila *f){
	int tor,tor_p;
	T_disco *aux;
	printf("Vamos iniciar o jogo......\n");
	printf("Aguade......\n");
	sleep(2);
	system("cls");
	printf("Informações do jogo.\n");
	sleep(1);
	printf("Fila de jogadores.\n");
	print(f);
	system("pause");
	system("cls");
	printf("Torres.....\n");
	imprime_torre(t1,t2,t3);
	system("pause");
	//system("cls");
	printf("Por favor digite o seu movimento.\n");
	printf("De qual torre deseja retirar o disco ?.\n");
	printf("1:Para torre 1.\n");
	printf("2:Para torre 2.\n");
	printf("3:Para torre 3.\n");
	scanf("%d",&tor);
	printf("Torre escolhida: %d\n",tor);
	printf("Para qual torre deseja mover o disco ?.\n");
	printf("1:Para torre 1.\n");
	printf("2:Para torre 2.\n");
	printf("3:Para torre 3.\n");
	scanf("%d",&tor_p);
	system("cls");
	printf("Jogador atual: %s.\n",f->primeiro->jogador.nome);
	printf("Número de jogadas: %d.\n",f->primeiro->jogador.num_jogadas);
	printf("Movendo de torre %d para torre %d.\n",tor,tor_p);
	switch(tor){
		case 1:
			if(t1->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t1->top;
			if(t1->top->abaixo== NULL){
				t1->top=NULL;
			}
			else{
				t1->top=t1->top->abaixo;
			}
			switch(tor_p){
				case 1:
					t1->top=aux;
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
				break;
				case 2:
					if(t2->top== NULL || t2->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t2->top==NULL){
							t2->base=aux;
							t2->top=aux;
							t2->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
					
						}else{
							aux->abaixo=t2->top;
							t2->top=aux;
							f->primeiro->jogador.num_jogadas++;
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t1->top=aux;
					}
				break;
				case 3:
					if(t3->top== NULL || t3->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t3->top==NULL){
							t3->base=aux;
							t3->top=aux;
							t3->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
					
						}else{
							aux->abaixo=t3->top;
							t3->top=aux;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t1->top=aux;
					}
				break;
			}
		break;
		case 2:
			if(t2->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t2->top;
			if(t2->top->abaixo== NULL){
				t2->top=NULL;
			}
			else{
				t2->top=t2->top->abaixo;
			}
			
			switch(tor_p){
				case 1:
					if(t1->top== NULL || t1->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t1->top==NULL){
							t1->base=aux;
							t1->top=aux;
							t1->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
					
						}else{
							aux->abaixo=t1->top;
							t1->top=aux;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t2->top=aux;
					}
				break;
				case 2:
					t2->top=aux;
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
				break;
				case 3:
					if(t3->top== NULL || t3->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t3->top==NULL){
							t3->base=aux;
							t3->top=aux;
							t3->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
	//						verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
					
						}else{
							aux->abaixo=t3->top;
							t3->top=aux;
							f->primeiro->jogador.num_jogadas++;
////							verifica_jogo(t2,f);
	//						verifica_jogo(t3,f);
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t2->top=aux;
					}
				break;
			}
		break;
		case 3:
			if(t1->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t3->top;
			if(t3->top->abaixo== NULL){
				t3->top=NULL;
			}
			else{
				t3->top=t3->top->abaixo;
			}
			switch(tor_p){
				case 1:
					if(t1->top== NULL || t1->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t1->top==NULL){
							t1->base=aux;
							t1->top=aux;
							t1->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
//							verifica_jogo(t2,f);
///							verifica_jogo(t3,f);
							
					
						}else{
							aux->abaixo=t1->top;
							t1->top=aux;
							f->primeiro->jogador.num_jogadas++;
//							verifica_jogo(t2,f);
//							verifica_jogo(t3,f);
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t3->top=aux;
					}
				break;
				case 2:
					if(t2->top== NULL || t2->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t2->top==NULL){
							t2->base=aux;
							t2->top=aux;
							t2->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
//							verifica_jogo(t2,f);
//							verifica_jogo(t3,f);
							
					
						}else{
							aux->abaixo=t2->top;
							t2->top=aux;
							f->primeiro->jogador.num_jogadas++;
//							verifica_jogo(t2,f);
//							verifica_jogo(t3,f);
							
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t3->top=aux;
					}
				break;
				case 3:
					t3->top=aux;
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
				break;
			}
		break;
		default: 
			printf("Opção Inválida....\n");
	}
	rotaciona_monges(f);
	system("pause");
	system("cls");
	printf("Torres.....\n");
	imprime_torre(t1,t2,t3);
	system("pause");
	system("cls");
}
void continuar_jogo(T_torre *t1,T_torre *t2, T_torre *t3,fila *f){
	int tor,tor_p;
	T_disco *aux;
	printf("Vamos continuar o jogo......\n");
	printf("Carregando......\n");
	sleep(1);
	system("cls");
	printf("Informações do jogo.\n");
	printf("Ordem dos jogadores.\n");
	print(f);
	system("pause");
	system("cls");
	printf("Torres atualmente.....\n");
	imprime_torre(t1,t2,t3);
	system("pause");
	//system("cls");
	printf("Continuando....\n");
	sleep(1);
	printf("Por favor digite o seu movimento.\n");
	printf("De qual torre deseja retirar o disco ?.\n");
	printf("1:Para torre 1.\n");
	printf("2:Para torre 2.\n");
	printf("3:Para torre 3.\n");
	scanf("%d",&tor);
	printf("Torre escolhida: %d\n",tor);
	printf("Para qual torre deseja mover o disco ?.\n");
	printf("1:Para torre 1.\n");
	printf("2:Para torre 2.\n");
	printf("3:Para torre 3.\n");
	scanf("%d",&tor_p);
	system("cls");
	printf("Jogador atual: %s.\n",f->primeiro->jogador.nome);
	printf("Número de jogadas: %d.\n",f->primeiro->jogador.num_jogadas);
	printf("Movendo de torre %d para torre %d.\n",tor,tor_p);
	switch(tor){
		case 1:
			if(t1->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t1->top;
			if(t1->top->abaixo== NULL){
				t1->top=NULL;
			}
			else{
				t1->top=t1->top->abaixo;
			}
			switch(tor_p){
				case 1:
					t1->top=aux;
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
				break;
				case 2:
					if(t2->top== NULL || t2->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t2->top==NULL){
							t2->base=aux;
							t2->top=aux;
							t2->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
					
						}else{
							aux->abaixo=t2->top;
							t2->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
						verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t1->top=aux;
					}
				break;
				case 3:
					if(t3->top== NULL || t3->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t3->top==NULL){
							t3->base=aux;
							t3->top=aux;
							t3->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
					
						}else{
							aux->abaixo=t3->top;
							t3->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t1->top=aux;
					}
				break;
			}
		break;
		case 2:
			if(t2->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t2->top;
			if(t2->top->abaixo== NULL){
				t2->top=NULL;
			}
			else{
				t2->top=t2->top->abaixo;
			}
			
			switch(tor_p){
				case 1:
					if(t1->top== NULL || t1->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t1->top==NULL){
							t1->base=aux;
							t1->top=aux;
							t1->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
					
						}else{
							aux->abaixo=t1->top;
							t1->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t2->top=aux;
					}
				break;
				case 2:
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
					t2->top=aux;
				break;
				case 3:
					if(t3->top== NULL || t3->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t3->top==NULL){
							t3->base=aux;
							t3->top=aux;
							t3->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
					
						}else{
							aux->abaixo=t3->top;
							t3->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t2->top=aux;
					}
				break;
			}
		break;
		case 3:
			if(t3->top==NULL){
				printf("Não há elementos nesta torre para serem movidos.\n");
				return;
			}
			aux=t3->top;
			if(t3->top->abaixo== NULL){
				t3->top=NULL;
			}
			else{
				t3->top=t3->top->abaixo;
			}
			switch(tor_p){
				case 1:
					if(t1->top== NULL || t1->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t1->top==NULL){
							t1->base=aux;
							t1->top=aux;
							t1->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
					
						}else{
							aux->abaixo=t1->top;
							t1->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t3->top=aux;
					}
				break;
				case 2:
					if(t2->top== NULL || t2->top->tamanho_do_disco>aux->tamanho_do_disco){
						if(t2->top==NULL){
							t2->base=aux;
							t2->top=aux;
							t2->top->abaixo=NULL;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);					
						}else{
							aux->abaixo=t2->top;
							t2->top=aux;
							f->primeiro->jogador.num_jogadas++;
							verifica_jogo(t2,f);
							verifica_jogo(t3,f);
							rotaciona_monges(f);
						}
					}else{
						printf("A torre não pode ser movida pois um elemento maior não pode sobrepor um menor....\n");
						t3->top=aux;
					}
				break;
				case 3:
					printf("Você não pode mover um elemento da pilha para a própria pilha...\n");
					t3->top=aux;
				break;
			}
		break;
		default: 
			printf("Opção Inválida....\n");
	}
	system("pause");
	system("cls");
	printf("Torres.....\n");
	imprime_torre(t1,t2,t3);
	system("pause");
	system("cls");
	continuar_jogo(t1,t2,t3,f);
}
verifica_jogo(T_torre *t2,fila *f){
	int pontuacao=0,j=1;
	T_disco *aux=t2->top;
	if(aux != NULL){
		if(aux->tamanho_do_disco== 1){
				j=1;
				while(aux != NULL){
					if(aux->tamanho_do_disco==j){
						pontuacao++;
					}
					if(aux->abaixo== NULL){
						aux=NULL;
					}else{
						aux=aux->abaixo;
					}
					j++;
				}
				if(pontuacao==7){
					printf("Vencedor..\n");
					sleep(2);
					system("cls");
					printf("		-----------------------------------------------------------			\n");
					printf("		|        Parabens! Você é o mais sábio dos monges.        | 		\n");
					printf("		-----------------------------------------------------------			\n");
					printf("\n\n");
					printf("			---------------------NOME------------------			\n");
					printf("				           %s										\n",f->primeiro->jogador.nome);
					printf("			--------------------JOGADAS----------------			\n");
					printf("					     %d									\n",f->primeiro->jogador.num_jogadas);
					printf("		-----------------------------------------------------------			\n");
					trofeu();
					exit(1);
				}
		}
		return;
	}
	return;
}
