#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf ("\n");
}
void troca(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int Divide(int *vetor, int esq, int dir)
{
    int p = vetor[dir];
    int i = esq - 1, j;
    for(j = esq; j <= dir - 1; j++)
    {
        if(vetor[j] < p)
        {
            i++;
            troca(vetor, i, j);
        }
    }
    i++;
    troca(vetor, i, dir);
    return i;
}


int QuickFind(int *vetor, int esq, int dir, int k)
{
    if(esq < dir)
    {
        int p = Divide(vetor, esq, dir);
        if(k == p)
        {
            return p;
        }
        if(k < p)
        {
            QuickFind(vetor, esq, p-1, k);
        }
        if(k > p)
        {
            QuickFind(vetor, p+1, dir,k);
        }
    }
}

/*Função principal.*/
int main (int argc, char *argv[])
{
    clock_t start, end;
    double elapsed_time;
    srand(time(NULL));
    int i;
    int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};
    int tamanho = 8;
    Imprimir (vetor, tamanho);
    start = clock();
    int pos = 2;
    int num = QuickFind(vetor, 0, tamanho-1, pos);
    printf("O elemento procurado na posicao %d eh %d\n", pos, vetor[num]);
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    return 0;
}
