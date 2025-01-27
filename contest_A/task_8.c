#include <stdio.h>
#include <stdint.h>
#define BASE 3
#define MAX_POWER 19

// В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна)
// и гири массами 1г, 3г, 9г, 27г, и т.д. по одной штуке каждой массы.
// Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно,
// сколько гирь придется положить на весы (на любую чашку). Надо помочь ему.
// Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000).
// Формат выходных данных: единственное целое число – общее количество гирь
// или число –1 если данный товар взвесить невозможно.

typedef struct item
{
    int used;
    int32_t weigth;
    uint32_t summBefore;
} item;

int power(int base, int count)
{

    int result = 1;
    for (size_t i = 0; i < count; i++)
    {
        result *= base;
    }
    return result;
}

int main(int argc, char **argv)
{
    uint32_t weight;
    int count = 0;
    scanf("%u", &weight);
    item set[MAX_POWER];
    uint32_t leftSumm = 0, rightSumm = 0;
    uint32_t exp = 0, summ = 0;
    for (size_t i = 0; i < MAX_POWER; i++)
    {
        set[i].summBefore = summ;
        set[i].used = 0;
        set[i].weigth = power(BASE, i);
        summ += set[i].weigth;
    }
    for (int i = MAX_POWER - 1; i >= 0; i--)
    {
        if (weight >= set[i].weigth)
        {
            count++;
            set[i].used = 1;
            weight -= set[i].weigth;
        }
    }
    if (weight == 0)
    {
        printf("%d\n", count);
        return 0;
    }
    else
    {
        for (size_t i = MAX_POWER - 1; i >= 0; i--)
        {
            if ((set[i].used == 0) && weight >= set[i].weigth)
            {
                count++;
                set[i].used = 1;
                weight -= set[i].weigth;
            }
        }
        weight ? printf("%d\n", -1) : printf("%d\n", count);
    }
    return 0;
}