#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число.

#define MASK_END 0x00000001
#define MASK_BEGIN 0x80000000

uint32_t cicleRigthShift(uint32_t number, uint32_t k)
{
    for (size_t i = 0; i < k; i++)
    {
        if (number & MASK_END)
        {
            number >>= 1;
            number |= MASK_BEGIN;
        }
        else
        {
            number >>= 1;
        }
    }

    return number;
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
    uint32_t out = cicleRigthShift(N, K);
    printf("%u\n", out);
    return 0;
}