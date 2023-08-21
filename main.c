#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct no {
	int info;
	struct no* proximo;
}No;

typedef struct pilha {
	No* topo;
}Pilha;

Pilha* cria(void){
	Pilha* nova_pilha = (Pilha *) malloc(sizeof(Pilha));
	nova_pilha->topo = NULL;
	return nova_pilha;
}

No* retira(No* topo){
	No* aux = topo;
	topo = aux->proximo;
	free(aux);
	return topo;
}

int vazia(Pilha* pilha){
	return(pilha->topo == NULL);
}


No* insere(No* lista, int num){
	No* novo_no = (No *) malloc(sizeof(No));
	novo_no->info = num;
	novo_no->proximo = lista;
	return novo_no;
}

void push(Pilha* p, int v){
	p->topo = insere(p->topo, v);
}


int pop(Pilha* p){
	int num;
	if(vazia(p)){
		printf("Pilha vazia.\n");
		exit(1);
	}
	num = p->topo->info;
	p->topo = retira(p->topo);
	return num;
}

void imprime(Pilha* pilha){
	No* item;
	for(item=pilha->topo; item!=NULL; item=item->proximo)
		printf("\n Item : %d ", item->info);
}
	
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	
	Pilha* p = cria();
	push(p, 1);
	push(p, 2);
	push(p, 3);
	imprime(p);
	pop(p);
	printf("\n Após a remoção de um elemento: \n");
	imprime(p);
	pop(p);
	printf("\n Após a remoção de um elemento: \n");
	imprime(p);
	
	return 0;
}