#include <stdio.h>


int abs(int val) {
   return val >= 0 ? val : val;
}
int findLargestPrimeDivider(int num);
int isNumPrime(int);
int isDivisionable(int dividend, int divider);

int main() {
  float num;
  if (scanf("%f", &num) != 1 || num != (int)num) {
    printf("n/a");
    return 1;
  }
  printf("%d", findLargestPrimeDivider(num));
  return 0;
}



int findLargestPrimeDivider(int num) {
    num = abs(num);
    for (int i = num - 1; i > 1; --i) {
      if (isDivisionable(num, i) && isNumPrime(i)) {
         return i;
      }
    }
    return 1;
}

int isDivisionable(int dividend, int divisor) {
   while (dividend > 0) {
     dividend -= divisor;
   }
   if (dividend == 0) {
      return 1;
   } 
   return 0;
}

int isNumPrime(int num) {
    for (int i = num - 1; i > 1; --i) {
      if (isDivisionable(num, i)) {
        return 0;
      }
    }
    return 1;
}
