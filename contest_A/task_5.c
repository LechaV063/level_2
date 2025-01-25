#include <stdio.h>
#include <inttypes.h>
#define MASK 0x80000000

// На вход программе подается беззнаковое 32-битное целое число N.
// Требуется найти количество единичных битов в двоичном представлении данного числа.

uint8_t countOneBits(uint32_t number)
{
    uint8_t count = 0;
    for (size_t i = 0; i < 32; i++)
    {
        if (number & MASK)
        {
            count++;
        }
        number <<= 1;
    }
    return count;
}
int main(int argc, char **argv)
{
    uint32_t N;
    scanf("%u", &N);
    uint32_t out = countOneBits(N);
    printf("%u\n", out);

    return 0;
}