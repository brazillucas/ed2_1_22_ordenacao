// Ordene o vetor [8, 10, 42, 93, 58, 12, 13, 49, 77, 25, 81, 4, 78, 20, 80] com Quicksort, Shellsort, MergeSort e Heapsort em C

// Desenvolva um sistema que gere um vetor aleatório, ordene este vetor com cada um dos
// quatro algoritmos e mostre:
// • O algoritmo utilizado
// • A quantidade de comparações entre posições do vetor.
// • A quantidade de troca de valores entre posições do vetor.
// • O tempo gasto na execução do algoritmo.
// • E, ao final, o algoritmo de melhor desempenho em função do tempo.
// O programa deve receber o tamanho do vetor (N) entre 10 e 100000, criar o vetor, preencher com valores inteiros aleatoriamente e utilizar o mesmo vetor para os quatro algoritmos.
// O vetor deve ser impresso antes e depois de cada ordenação.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapsort(int *v, int n, int* countComp, int* countTroca);
void mergeSort(int *v, int n, int* countComp, int* countTroca);
void quickSort(int *v, int n, int* countComp, int* countTroca);
void shellSort(int *v, int n, int* countComp, int* countTroca);

int main() {
    
        int max = 15;
        int min = 10;
        int v[max], heapSortV[max], mergeSortV[max], quickSortV[max], shellSortV[max];
        int aux = 0;
        int countComp = 0, countTroca = 0;
    
        //Vetores
        //Gerando vetor aleatório
        for(int i = 0; i < max; i++) {
            v[i] = rand() % max;
        }
        //Copia do vetor para HeapSort
        for(int i = 0; i < max; i++) {
            heapSortV[i] = v[i];
        }
        //Copia do vetor para MergeSort
        for(int i = 0; i < max; i++) {
            mergeSortV[i] = v[i];
        }
        //Copia do vetor para QuickSort
        for(int i = 0; i < max; i++) {
            quickSortV[i] = v[i];
        }
        //Copia do vetor para ShellSort	
        for(int i = 0; i < max; i++) {
            shellSortV[i] = v[i];
        }
        //Fim dos Vetores
    
        printf("Vetor original \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", v[i]);
        }

        //HeapSort
        heapsort(heapSortV, max, countComp, countTroca);
        printf("\n\nVetor ordenado heapsort \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", heapSortV[i]);
        }

        compTrocas(countComp, countTroca);
        //Fim do MergeSort
    
        //Resetando contadores
        resetVetores(countComp, countTroca);

        //MergeSort
        mergeSort(mergeSortV, max, countComp, countTroca);
        printf("\n\nVetor ordenado mergeSort \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", mergeSortV[i]);
        }

        compTrocas(countComp, countTroca);
        //Fim do MergeSort

        //Resetando contadores
        resetVetores(countComp, countTroca);

        //QuickSort
        quickSort(quickSortV, max, countComp, countTroca);
        printf("\n\nVetor ordenado quickSort \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", quickSortV[i]);
        }

        compTrocas(countComp, countTroca);
        //Fim do QuickSort

        //Resetando contadores
        resetVetores(countComp, countTroca);

        //ShellSort
        shellSort(shellSortV, max, countComp, countTroca);
        printf("\n\nVetor ordenado shellSort \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", shellSortV[i]);
        }

        compTrocas(countComp, countTroca);
        //Fim do ShellSort

        //Resetando contadores
        resetVetores(countComp, countTroca);

        return 0;
}

void heapsort(int *v, int n, int* countComp, int* countTroca) {
    int i = n / 2, pai, filho, t;
    for (;;) {
        if (i > 0) {
            i--;
            t = v[i];
        } else {
            n--;
            if (n == 0) return;
            t = v[n];
            v[n] = v[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho]))
                filho++;
            if (v[filho] > t) {
                v[pai] = v[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        v[pai] = t;
    }
}

void mergeSort(int *v, int n, int* countComp, int* countTroca) {
    int *b = malloc(n * sizeof(int));
    int inicio = 0, fim = n, meio = (inicio + fim) / 2, i, j, k;
    if (n < 2) return;
    mergeSort(v, meio, countComp, countTroca);
    mergeSort(v + meio, n - meio, countComp, countTroca);
    for (i = inicio; i < meio; i++) {
        b[i] = v[i];
    }
    for (j = meio; j < fim; j++) {
        b[fim + meio - j] = v[j];
    }
    for (k = inicio; k < fim; k++) {
        if (b[i] <= b[j]) {
            v[k] = b[i];
            i++;
        } else {
            v[k] = b[j];
            j--;
        }
    }
    free(b);
}

void quickSort(int *v, int n, int* countComp, int* countTroca) {
    int esq, dir, pivo, aux;
    esq = 0;
    dir = n - 1;
    pivo = v[n / 2];
    while(esq <= dir) {
    while(v[esq] < pivo && esq < n)
        esq++;
    while(v[dir] > pivo && dir > 0)
        dir--;
    if(esq <= dir) {
        aux = v[esq];
        v[esq++] = v[dir];
        v[dir--] = aux;
    }
    }
    if(dir > 0) quickSort(v, dir + 1, countComp, countTroca);
    if(esq < n) quickSort(v + esq, n - esq, countComp, countTroca);
}

void shellSort(int *v, int n, int* countComp, int* countTroca) {
    int i, j, value;
    int gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < n);
    do {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = v[i];
            j = i - gap;
            while (j >= 0 && value < v[j]) {
                v [j + gap] = v[j];
                j -= gap;
            }
            v [j + gap] = value;
        }
    } while ( gap > 1);
}

void compTrocas(int* countComp, int* countTroca) {
    printf("\n\nComparacoes: %d", *countComp);
    printf("\nTrocas: %d", *countTroca);
}

void resetVetores(int* countComp, int* countTroca) {
    *countComp = 0;
    *countTroca = 0;
}

void preencheVetor(int* v, int max) {
    for(int i = 0; i < max; i++) {
        v[i] = rand() % 100;
    }
}

void printVetor(int* v, int max) {
    for(int i = 0; i < max; i++) {
        printf("%d ", v[i]);
    }
}



