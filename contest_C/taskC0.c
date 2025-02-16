#include <stdio.h>
#include <stdint.h>

// Сколько различных трехзначных чисел можно получить из заданного натурального N,
// вычеркивая цифры из его десятичной записи?

struct digitSet
{
    int digit[10];
    int count[10];
};

int cnk2(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

struct digitSet getNumberOfDigits(int num)
{
    struct digitSet result;
    for (size_t i = 0; i < 10; i++)
    {
        result.digit[i] = 0;
        result.count[i] = 0;
    }
    int temp;
    do
    {
        temp = num % 10;
        result.count[temp]++;
        result.digit[temp] = 1;
        num /= 10;
    } while (num / 10 > 0);
    result.count[num]++;
    result.digit[num] = 1;
    return result;
}

int main(int agrc, char *argv[])
{
    uint64_t inputNumber;
    scanf("%ld", &inputNumber);
    struct digitSet inputSet = getNumberOfDigits(inputNumber);
    // printf("%d\n", cnk2)
    return 0;
}
