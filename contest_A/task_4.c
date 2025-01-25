#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным.
// Программа должна вывести полученное число.

#define MASK_START 0xFFFFFFFF

uint32_t maxNumber(uint32_t number, uint32_t k)
{
    int max = 0;
    uint32_t curMask = ~(MASK_START << k);
    for (size_t i = 0; i <= 32 - k; i++)
    {
        max = ((number & curMask) > max) ? (number & curMask) : max;
        number >>=1;
    }
    return max;
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
    uint32_t out = maxNumber(N, K);
    printf("%u\n", out);

    return 0;
}