#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
void insercao(int *v, int n){
    int aux,j;
    for(int i=1; i<n; i++){
        aux = v[i];
        for (j = i; j > 0 && aux < v[j-1]; j--) {
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}
void imprime(int *v, int n){
    for(int i=0; i<n; i++){
        printf("%i\n",v[i]);
    }
}
void troca(int *v, int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
void quickSort(int *v, int inicio, int fim){
    int i, j, pivo;
    if(fim - inicio > 0){
        i = inicio;
        j = fim;
        pivo = v[(i+j)/2];
        while(i < j){
            while(v[i] < pivo){
                i++;
            }
            while(v[j] > pivo){
                j--;
            }
            if(i <= j)
                troca(v,i++,j--);
        }
        quickSort(v,inicio,j);
        quickSort(v,i,fim);
    }
}
int main(){
    int v[TAM];
    clock_t t;
    srand(time(NULL));
    for(int i=0; i<TAM; i++){
        v[i] = rand()%1000;
    }
    t = clock();
    quickSort(v,0,TAM-1);
    t = clock() - t;
    printf("\nTempo de execucao: %lf\n", ((double)t)/CLOCKS_PER_SEC);
    imprime(v,TAM);
    return 0;
}
