#include <stdlib.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
	int	capacidade;
	int	topo;
	int	*itens;
} Pilha;

Pilha *criarPilha ( int n ) {
	Pilha *p = malloc( sizeof( Pilha ) );
	p->capacidade = n;
	p->topo = -1;

	p->itens = malloc( n * sizeof( int ) );

	return p;
}

bool vazio ( Pilha *p ) {
	if ( p->topo == -1 ) {
		return true;
	}

	return false;
}

void push ( Pilha *p, int val ) {
	if ( p->topo < p->capacidade )
		p->itens[++( p->topo )] = val;
}

int returnTopo ( Pilha *p ) {
	return p->itens[p->topo];
}

int pop ( Pilha *p ) {
	if ( vazio( p ) == true ) {
		return -1;
	}

	return p->itens[( p->topo )--];
}

void liberaPilha( Pilha *p ) {
	free( p->itens );
	free( p );
}

int *nextGreaterElements ( int *nums, int numsSize, int *returnSize ) {
	*returnSize = numsSize;
	Pilha *p = criarPilha( *returnSize );
	int *resul = malloc( *returnSize * sizeof( int ) );

	for ( int i = 0; i < numsSize; i++ ) {
		resul[i] = -1;
	}

	for ( int i = 0; i <= numsSize * 2; i++ ) {
		int atual = nums[i % numsSize];

		while ( !vazio( p ) && atual > nums[returnTopo( p )] ) {
			int n = pop( p );
			resul[n] = atual;
		}

		if ( i < numsSize ) {
			push( p, i );
		}
	}

	liberaPilha( p );
	return resul;
}

int main ( int argc, char const *argv[] ) {
    int nums[] = { 1, 2, 1 };
	int numsSize = 3;
	int returnSize;

    int *resul = nextGreaterElements( nums, numsSize, &returnSize );
	free(resul);
}

