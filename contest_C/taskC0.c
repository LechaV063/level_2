#include <stdio.h>
#include <stdint.h>

// Сколько различных трехзначных чисел можно получить из заданного натурального N, 
// вычеркивая цифры из его десятичной записи?

int cnk2(int n, int k) {
    double res = 1;
    for (int i=1; i<=k; ++i)
        res = res * (n-k+i) / i;
    return (int) (res + 0.01);
}

int getNumberOfDigits(int num) {
    int result=0;

    return result;
}

int main(int agrc, char *argv[]) {
    uint64_t inputNumber;
    scanf("%d", &inputNumber);
    // printf("%d\n", cnk2)
    return 0;
}
