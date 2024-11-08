#include <stdio.h>

#define MAX_SIZE 30

int input(int* a, int* size, int* shift_step);
void output(int* a, int size);
void shift(int* a, int size, int shift_step);

int main() {
    int arr[MAX_SIZE], size, shift_step;
    if (input(arr, &size, &shift_step)) {
        printf("n/a");
        return 1;
    }
    shift(arr, size, shift_step);
    output(arr, size);
}


int input(int* a, int* size, int* shift_step) {
    if (scanf("%d", size) != 1 || *size <= 0) {
        return 1;
    }
    for(int i = 0; i < *size; ++i) {
        if (scanf("%d", (a + i)) != 1) {
            return 1;
        }
    }
    if (scanf("%d", shift_step) != 1) {
        return 1;
    }
    return 0;
}

void output(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", *(a + i));
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void shift(int* a, int size, int shift_step) {
    shift_step %= size;
    if (shift_step == 0) {
        return;
    }
    if (shift_step < 0) {
        shift_step = size + shift_step;
    }
    for (int i = 0; i < shift_step; ++i) {
        int tmp = a[0];
        for (int j = 0; j < size - 1; ++j) {
            a[j] = a[j + 1];
        }
        a[size - 1] = tmp;
    }
}