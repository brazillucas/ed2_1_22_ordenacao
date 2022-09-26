#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void heapsort(int *v, int n);
void merge_sort(int *v, int n);

int main()
{
    int *v;
    int n, i;

    clock_t t;
    double time_taken;

    printf("Digite n: ");
    scanf("%d", &n);

    v = (int *)malloc(n * sizeof(int));

    // preenche vetor aleatoriamente
    srand(time(NULL));
    for(i = 0; i < n; i++)
        v[i] = rand() % n;

    // printa vetor
    printf("Vetor desordenado: ");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    // ordenando com heapsort
    t = clock();
    heapsort(v, n);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Tempo gasto: %f\n", time_taken);

    // printa vetor
    printf("Vetor ordenado com heapsort: ");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    // preenche vetor aleatoriamente
    srand(time(NULL));
    for(i = 0; i < n; i++)
        v[i] = rand() % n;

    // printa vetor
    printf("Vetor desordenado: ");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    // ordenando com mergesort
    t = clock();
    merge_sort(v, n);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Tempo gasto: %f\n", time_taken);

    // printa vetor
    printf("Vetor ordenado com mergesort: ");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);

    return 0;
}

void heapsort(int *v, int n)
{
    int i = n / 2, pai, filho, t;
    while(true) {
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

void merge(int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort(int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
