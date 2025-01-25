#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define MASK 0xFFFFFFFF

// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется взять K младших битов числа N и вывести полученное таким образом число.

uint32_t maskNumber(uint32_t N, uint32_t K)
{
    uint32_t temp = ~(MASK << K);

    return N & temp;
};

int main(int argc, char **argv)
{
    uint32_t N, K;
    scanf("%u %u", &N, &K);
    if (K < 1 || K > 31)
    {
        exit(EXIT_FAILURE);
    }
    // printf("N = %d, K = %d\n", N, K);
    uint32_t out = maskNumber(N, K);
    printf("%u\n", out);
    return 0;
}