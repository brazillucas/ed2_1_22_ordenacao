//Quicksort, Shellsort, MergeSort e Heapsort em C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void resetVetores(int *countComp, int *countTroca) {
	*countComp = 0;
	*countTroca = 0;
}

void compTrocas(int *countComp, int *countTroca) {
	printf("\nComparações feitas: %d\n",*countComp);
	printf("Trocas feitas: %d",*countTroca);
}

void copiaVetor(int *v2, int *v, int max) {
	for(int i = 0; i < max; i++) {
		v2[i] = v[i];
	}
}

void printVetor(int *v, int max) {
	for(int i = 0; i < max; i++) {
		printf("%d ", v[i]);
	}
}

void melhorAlgoritmo(double *tempoHeap, double *tempoMerge, double *tempoQuick, double *tempoShell) {
	
	double min = 1316134912;
	int melhor;

	double v[4];
	
	v[0] = *tempoMerge;
	v[1] = *tempoHeap;
	v[2] = *tempoQuick;
	v[3] = *tempoShell;

	for (int i = 0; i < 4; i++ ) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	
	printf("\nMenor tempo: %f", min);

	for (int i = 0; i < 4; i++ ) {
		if (v[i] == min) {
			melhor = i;
		}
	}
	
	switch (melhor) {
		case 0:
		//	printf("\nMergeSort");
			printf("\nO melhor tempo foi do algoritmo MergeSort");
			break;
		case 1:
		//	printf("\nHeapSort");
			printf("\nO melhor tempo foi do algoritmo HeapSort");
			break;
		case 2:
		//	printf("\nQuickSort");
			printf("\nO melhor tempo foi do algoritmo QuickSort");
			break;
		case 3:
		//	printf("\nShellSort");
			printf("\nO melhor tempo foi do algoritmo ShellSort");
			break;
		default:
			printf("\nNenhum resultado bom, melhore!");
			break;
	}
}

void heapsort(int *v, int n, int *countComp, int *countTroca) {

	int i = n / 2, pai, filho, t;

	while(1) {
		if(i > 0) {
			i--;
			t = v[i];
		} else {
			n--;
			
			if(n == 0) {
				return;
			}
			
			t = v[n];
			v[n] = v[0];
		}
		
		pai = i;
		filho = i * 2 + 1;
		
		while(filho < n) {
			if((filho + 1 < n) && (v[filho + 1] > v[filho])) {
				filho++;
			}
			*countComp = *countComp + 1;
			if(v[filho] > t) {
				v[pai] = v[filho];
				*countTroca = *countTroca + 1;
				pai = filho;
				filho = pai * 2 + 1;
			} else {
				break;
			}
		}		
		v[pai] = t;
	}
}

void merge(int *v, int n, int meio, int *countComp, int *countTroca) {
  
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = n;
	p1 = 0;
	p2 = meio;
	temp = (int *) malloc(tamanho * sizeof(int));

	if(temp != NULL) {
		for(i = 0; i < tamanho; i++) {
			if(!fim1 && !fim2) {
				*countComp = *countComp + 1;
				if(v[p1] < v[p2]) {
					temp[i] = v[p1++];
				} else {
					temp[i] = v[p2++];
				}
				if (p1 == meio) {
					fim1 = 1;
				}
				if (p2 == n) {
					fim2 = 1;
				}
			} else {
				*countTroca = *countTroca + 1;
				if(!fim1) {
					temp[i] = v[p1++];
				} else {
					temp[i] = v[p2++];
				}
			}
		}
		for(j = 0, k = 0; j < tamanho; j++, k++) {
			v[k] = temp[j];
		}
	}
	free(temp);
  
}

void mergeSort(int *v, int n, int *countComp, int *countTroca) {
	
	int meio;
	if (n > 1) {
		meio = n / 2;
		mergeSort(v, meio, countComp, countTroca);
		mergeSort(v + meio, n - meio, countComp, countTroca);
		merge(v, n, meio, countComp, countTroca);
	}
  
}

void quickSort(int *v, int n, int* countComp, int* countTroca) {

	int esq, dir, pivo, aux;
	esq = 0;
	dir = n - 1;
	pivo = v[n / 2];
	
	while (esq <= dir) {
		while (v[esq] < pivo && esq < n) {
			esq++;
		}
		while (v[dir] > pivo && dir > 0) {
			dir--;
		}
		*countComp = *countComp + 1;
		if (esq <= dir) {
		  aux = v[esq];
		  v[esq++] = v[dir];
		  v[dir--] = aux;
		  *countTroca = *countTroca + 1;
		}
	}
	
	if (dir > 0) {
		quickSort(v, dir + 1, countComp, countTroca);
	}
	if (esq < n) {
		quickSort(v + esq, n - esq, countComp, countTroca);
	}  
}

void shellSort(int *v, int n, int *countComp, int *countTroca) {
  
	int i, j, value;
	int gap = 1;

	while(gap < n) {
		gap = 3 * gap + 1;
	}
	while(gap > 1) {
		gap /= 3;
		for(i = gap; i < n; i++) {
			value = v[i];
			j = i - gap;
			*countComp = *countComp + 1;
			while(j >= 0 && value < v[j]) {				
				v[j + gap] = v[j];
				*countTroca = *countTroca + 1;
				j -= gap;
			}
			v[j + gap] = value;
		}
	}
}

void heapsort(int *v, int n, int *countComp, int *countTroca);
void mergeSort(int *v, int n, int *countComp, int *countTroca);
void quickSort(int *v, int n, int *countComp, int *countTroca);
void shellSort(int *v, int n, int *countComp, int *countTroca);

int main() {

	srand(time(NULL));
	int max = rand() % 100000;
	int v[max], heapSortV[max], mergeSortV[max], quickSortV[max], shellSortV[max];
	int compHeap = 0, trocaHeap = 0;
	int compMerge = 0, trocaMerge = 0;
	int compQuick = 0, trocaQuick = 0;
	int compShell = 0, trocaShell = 0;
	clock_t t;
    double tempoHeap, tempoMerge, tempoQuick, tempoShell;

	//Vetores
	//Gerando vetor aleatório
	for(int i = 0; i < max; i++) {
		v[i] = rand() % 100000;
	}

	//Copia do vetor para HeapSort
	copiaVetor(heapSortV, v, max);
  
	//Copia do vetor para MergeSort	
	copiaVetor(mergeSortV, v, max);

	//Copia do vetor para QuickSort
	copiaVetor(quickSortV, v, max);

	//Copia do vetor para ShellSort
	copiaVetor(shellSortV, v, max);
	//Fim dos Vetores
  
	//Tamanho do vetor
	printf("Vetor original\n");
	printVetor(v, max);

	//HeapSort
	t = clock();
	heapsort(heapSortV, max, &compHeap, &trocaHeap);
	t = clock() - t;
	
	printf("\n\nVetor ordenado HeapSort\n");
	printVetor(heapSortV, max);

	compTrocas(&compHeap, &trocaHeap);
    tempoHeap = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTempo gasto: %f", tempoHeap);
	//Fim do HeapSort

	//MergeSort
	t = clock();
	mergeSort(mergeSortV, max, &compMerge, &trocaMerge);
	t = clock() - t;

	printf("\n\nVetor ordenado MergeSort\n");
	printVetor(mergeSortV, max);

	compTrocas(&compMerge, &trocaMerge);
    tempoMerge = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTempo gasto: %f", tempoMerge);
	//Fim do MergeSort
  
	//QuickSort
	t = clock();
	quickSort(quickSortV, max, &compQuick, &trocaQuick);
	t = clock() - t;

	printf("\n\nVetor ordenado QuickSort\n");
	printVetor(quickSortV, max);

	compTrocas(&compQuick, &trocaQuick);
    tempoQuick = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTempo gasto: %f", tempoQuick); 
	//Fim do QuickSort

	//ShellSort
	t = clock();
	shellSort(shellSortV, max, &compShell, &trocaShell); 
	t = clock() - t;

	printf("\n\nVetor ordenado ShellSort\n");
	printVetor(shellSortV, max);

	compTrocas(&compShell, &trocaShell);
    tempoShell = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTempo gasto: %f", tempoShell); 
	//Fim do ShellSort
	
	printf("\n");	
	printf("\nTamanho do vetor: %d", max);
	melhorAlgoritmo(&tempoHeap, &tempoMerge, &tempoQuick, &tempoShell);

	return 0;
}