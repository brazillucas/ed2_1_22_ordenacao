// Ordene o vetor [8, 10, 42, 93, 58, 12, 13, 49, 77, 25, 81, 4, 78, 20, 80] com Heapsort em C
// Desenvolva um sistema que mostre:
// • O algoritmo utilizado
// • A quantidade de comparações entre posições do vetor.
// • A quantidade de troca de valores entre posições do vetor.
// • O tempo gasto na execução do algoritmo.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapsort(int *v, int n, int *countComp, int *countTroca);

int main() {
    
        int max = 15;
        int min = 10;
        int v[max], heapSortV[max];
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
        //Fim dos Vetores
    
        printf("Vetor original \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", v[i]);
        }
    
        //HeapSort
        heapsort(heapSortV, max, &countComp, &countTroca);
        printf("\n\nVetor ordenado heapsort \n");
        for(int i = 0; i < max; i++) {
            printf("%d ", heapSortV[i]);
        }

        printf("\nComparações feitas: %d\n",countComp);
	    printf("Trocas feitas: %d\n",countTroca);
    
        return 0;
    }
    
    void heapsort(int *v, int n, int *countComp, int *countTroca) {
        int i, aux;
        for(i = (n-1)/2; i >= 0; i--) {
            
           
            maxHeapify(v, i, n-1, &countComp);
        }
        for(i = n-1; i >= 1; i--) {
            aux = v[0];
            v[0] = v[i];
            v[i] = aux;
            *countTroca = *countTroca + 1;
            printf("\nTrocas feitas: %d\n",*countTroca);
            maxHeapify(v, 0, i-1, &countComp);
        }
    }
    
    void maxHeapify(int *v, int i, int f, int **countComp) {
        int aux = v[i];
        int j = i * 2 + 1;
        while(j <= f) {
            if(j < f) {
                if(v[j] < v[j+1]) {
					**countComp = **countComp + 1;
					printf("\nComparações feitas: %d\n",**countComp);
                    j = j + 1;
                }
            }
            if(aux < v[j]) {
                v[i] = v[j];
                i = j;
                j = 2 * i + 1;
            } else {
                j = f + 1;
            }
        }
        v[i] = aux;
    }

// Language: c
// Compare this snippet from ordenaQuatroV2.c:
