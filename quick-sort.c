#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Para o melhor caso de ordenação de uma sequencia dos quais foram sugeridos (crescente, decrescente, aleatório) o mais rápido para ordenar foi o aleatório (O (n *logn)),
para o pior caso foram o crescente e decrescente O (n²), os dois são igualmente ruins por conta de escolhas sucessivas de um péssimo pivot
quando esse vetor já está ordenado.

Quanto ao tempo de ordenaçao para os tamanhos 10, 100, 1000 todos os resultados foram 0.00 segundos para ordenação
A = (aleatório), C = (crescente), D = (decrescente), a partir de  10.000 temos:
10.000
A = 0.00s, C = 0.23s, D = 0.22s
100.000
A = 0.02s, C = 9.76s, D = 9.56s
1.000.000
A = 0.22s, C = depois de 90.00s segundos ele retorna erro, D = (mesmo situaçao que crescente)

podemos considerar  os tempos de ordenação para crescente e decrescente iguais, pois ambos são o pior caso para ordenar com quick sort pois
neste caso sempre vai pegar o pior pivot possivel (um numero que nao é bom para dividir o vetor no meio, no caso o ultimo ou primeiro
não tendo ninguem maior ou menor que ele), acaba se tornando um algoritmo de complexide O(n²) demorando muito mais tempo.

*/

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao(int *vetor, int tamanho)
{
    int i;
    for (i = 0; i < tamanho-1; i++)
    {
        if(vetor[i] > vetor[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Imprimir(int *vetor, int tamanho)
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
    int i = esq - 1;
    for(int j = esq; j <= dir - 1; j++)
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

void QuickSort(int *vetor, int esq, int dir)
{
    if(esq < dir)
    {
        int p = Divide(vetor, esq, dir);
        QuickSort(vetor, esq, p-1);
        QuickSort(vetor, p+1, dir);
    }
}

/*Função principal.*/
int main (int argc, char *argv[])
{
    clock_t start, end;
    double elapsed_time;
    srand(time(NULL));
    int i;
    int tamanho = 10000;
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % (tamanho+1);
    }
    //Imprimir (vetor, tamanho);
    start = clock();
    QuickSort (vetor, 0, tamanho-1); // vetor aleatorio
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
    start = clock();
    QuickSort (vetor, 0, tamanho-1);// vetor ordenado crescentemente
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
    if (!Verifica_Ordenacao(vetor, tamanho))
    {
        printf("Erro: a ordenação não está correta!\n");
    }
    //Imprimir (vetor, tamanho);
    free (vetor);
    return 0;
}
