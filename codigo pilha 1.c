#include <stdio.h>
#include <stdlib.h>

#define TAM 32

typedef struct {
	int vet[TAM];
	int topo;	
}pilha;

void inicializa(pilha *p){
	p->topo = -1;
	
}

int pilhacheia(pilha *p){
	return (p->topo == TAM - 1);
}

int pilhavazia(pilha *p){
	return (p->topo == -1);	
}
void empilha(pilha *p, int valor){
	if(pilhacheia(p)){
		printf("Erro: Pilha cheia!\n");
		exit(1);
	}
	p->vet[++(p->topo)] = valor;
}

int desempilha(pilha *p){
	if(pilhavazia(p)){
		printf("Erro: Pilha vazia!\n");
		exit(1);
	}
	return p->vet[(p->topo)--];
}
int main() {
	pilha p;
	inicializa(&p);
	
	int numero;
	printf("Digite um numero inteiro: ");
	scanf("%d",&numero);
	
	if(numero == 0){
		printf("Binario: 0\n");
		return 0;
	}
	int n = numero;
		while(n>0){
			empilha(&p, n % 2);
			n = n / 2;
		}
		
		printf("Binario de %d: ", numero);
			while(!pilhavazia(&p)){
				printf("%d",desempilha(&p));
			}
			printf("\n");
			
			return 0;
}