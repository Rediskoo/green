#include <stdio.h>
#define SIZE 10

int input(int* array);
void quick_sort(int* array, int l, int r);
int partition(int* array, int l, int r);
void heap_sort(int* array);
void heapify(int* array, int n, int i);
void output(int* array);


void swap(int *a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int array[SIZE];
    if (input(array)) {
        printf("n/a");
        return 1;
    }
    int array2[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array2[i] = array[i];
    }
    quick_sort(array, 0, SIZE - 1);
    output(array);
    heap_sort(array);
    output(array);
}

int input(int* array) {
    for (int i = 0, *p = array; i < SIZE; ++i, ++p) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    return 0;
}

void quick_sort(int* array, int l, int r) {
    if (l < r) {
        int q = partition(array, l, r);
        quick_sort(array, l, q);
        quick_sort(array, q + 1, r);
    }
}

int partition(int* array, int l, int r) {
    int middle = array[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (array[i] < middle) {
            ++i;
        }
        while (array[j] > middle) {
            --j;
        }
        if (i >= j) {
            break;
        }
        swap(array + i, array + j);
        ++i; --j;
        
    }
    return j;
}

void output(int* array) {
    for (int i = 0; i < SIZE; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void heapify(int* array, int n, int i) {
    int largest = i;
    int l = 2 * largest + 1, r = 2 * largest + 2;
    if (l < n && array[l] > array[largest]) {
        largest = l;
    }
    if (r < n && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(array + i, array + largest);
        heapify(array, n, largest);
    }
}

void heap_sort(int* array) {
    for (int i = SIZE / 2 - 1; i >= 0; --i)  {
        heapify(array, SIZE, i);
    }

    for (int i = SIZE - 1; i >= 0; --i) {
        swap(array, array + i);
        heapify(array, i, 0);
    }
}