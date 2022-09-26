//Ordene o vetor [8, 10, 42, 93, 58, 12, 13, 49, 77, 25, 81, 4, 78, 20, 80] com Quicksort, Shellsort, MergeSort e Heapsort em C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void quickSort(int *vetor, int inicio, int fim);
void imprimirVetor(int *vetor, int tamanho);
void shellSort(int *vetor, int n);
void mergeSort(int *vetor, int inicio, int meio, int fim);
void heapSort(int *vetor, int tamanho);

int main(int argc, char const *argv[])
{
    int tamanho = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100;
    }

    printf("\n");
    imprimirVetor(vetor, tamanho);
    printf("\n");

    quickSort(vetor, 0, tamanho - 1);
    printf("\n");
    imprimirVetor(vetor, tamanho);
    printf("\n");

    shellSort(vetor, tamanho);
    printf("\n");
    imprimirVetor(vetor, tamanho);
    printf("\n");

    mergeSort(vetor, 0, tamanho / 2, tamanho);
    printf("\n");
    imprimirVetor(vetor, tamanho);
    printf("\n");

    heapSort(vetor, tamanho);
    printf("\n");
    imprimirVetor(vetor, tamanho);
    printf("\n");

    return 0;
}

void quickSort(int *vetor, int inicio, int fim)
{
    int pivo = inicio;
    int i = inicio;
    int j = fim;
    int aux;

    while (j > i)
    {
        while (vetor[i] <= vetor[pivo] && i < fim)
        {
            i++;
        }
        while (vetor[j] > vetor[pivo])
        {
            j--;
        }
        if (j > i)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    aux = vetor[pivo];
    vetor[pivo] = vetor[j];
    vetor[j] = aux;

    if (inicio < j - 1)
    {
        quickSort(vetor, inicio, j - 1);
    }
    if (j + 1 < fim)
    {
        quickSort(vetor, j + 1, fim);
    }
}

void imprimirVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void shellSort(int *vetor, int n)
{
    int i, j, h = 1;
    int aux;
    do
    {
        h = 3 * h + 1;
    } while (h < n);

    do
    {
        h = (h - 1) / 3;
        for (i = h; i < n; i++)
        {
            aux = vetor[i];
            j = i - h;
            while (j >= 0 && aux < vetor[j])
            {
                vetor[j + h] = vetor[j];
                j = j - h;
            }
            vetor[j + h] = aux;
        }
    } while (h > 1);
}

void mergeSort(int *vetor, int inicio, int meio, int fim)
{
    int *auxiliar = (int *)malloc((fim - inicio) * sizeof(int));
    int i = inicio, j = meio, k = 0;

    while (i < meio && j < fim)
    {
        if (vetor[i] < vetor[j])
        {
            auxiliar[k] = vetor[i];
            i++;
        }
        else
        {
            auxiliar[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i < meio)
    {
        auxiliar[k] = vetor[i];
        k++;
        i++;
    }

    while (j < fim)
    {
        auxiliar[k] = vetor[j];
        k++;
        j++;
    }

    for (i = inicio; i < fim; i++)
    {
        vetor[i] = auxiliar[i - inicio];
    }
    free(auxiliar);
}

void heapSort(int *vetor, int tamanho)
{
    int i = tamanho / 2, pai, filho, t;
    while (true)
    {
        if (i > 0)
        {
            i--;
            t = vetor[i];
        }
        else
        {
            tamanho--;
            if (tamanho == 0)
            {
                return;
            }
            t = vetor[tamanho];
            vetor[tamanho] = vetor[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < tamanho)
        {
            if ((filho + 1 < tamanho) && (vetor[filho + 1] > vetor[filho]))
            {
                filho++;
            }
            if (vetor[filho] > t)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else
            {
                break;
            }
        }
        vetor[pai] = t;
    }
}
