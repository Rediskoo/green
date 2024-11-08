#include <stdio.h>
#define SIZE 10

int input(int* array);
void sort(int* array);
void output(int* array);


int main() {
    int array[SIZE];
    if (input(array)) {
        printf("n/a");
        return 1;
    }
    sort(array);
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

void sort(int* array) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void output(int* array) {
    for (int i = 0; i < SIZE; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }
}