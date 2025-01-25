#include <stdio.h>
#include <inttypes.h>
#define MASK 0xFF000000

// На вход программе подается беззнаковое 32-битное целое число N.
// Требуется изменить значения всех битов старшего байта числа на противоположные и
// вывести полученное таким образом число.

uint32_t invertHightByte(uint32_t number)
{
    return number ^ MASK;
};

int main(int argc, char **argv)
{
    uint32_t N;
    scanf("%u", &N);
    uint32_t out = invertHightByte(N);
    printf("%u\n", out);

    return 0;
}