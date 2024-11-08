#include <stdio.h>


int Fibonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n <= 2) {
       return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}


int main() {
   float num;
   if (scanf("%f", &num) != 1 || num != (int)num || num < 0) {
      printf("n/a");
      return 1;
   }
   printf("%d", Fibonacci(num));
}
