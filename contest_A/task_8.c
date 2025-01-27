#include <stdio.h>
#include <stdint.h>
#define BASE 3
#define MAX_POWER 20
#define MAX_POSSIBLE_WEIGHT 1000000

// В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна)
// и гири массами 1г, 3г, 9г, 27г, и т.д. по одной штуке каждой массы.
// Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно,
// сколько гирь придется положить на весы (на любую чашку). Надо помочь ему.
// Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000).
// Формат выходных данных: единственное целое число – общее количество гирь
// или число –1 если данный товар взвесить невозможно.

typedef struct item
{
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
    int32_t weight;
    int count = 0;
    scanf("%u", &weight);
    item set[MAX_POWER];
    uint32_t summ = 0;
    uint32_t leftWeigth = 0, rightWeigth = 0;
    for (size_t i = 0; i < MAX_POWER; i++) // заполнение структуры набора гирь
    {
        set[i].summBefore = summ;

        set[i].weigth = power(BASE, i);
        summ += set[i].weigth;
    }
    leftWeigth = weight;
    for (int i = MAX_POWER - 1; i >= 0; i--)
    {
        weight = leftWeigth - rightWeigth;
        if ((leftWeigth >= MAX_POSSIBLE_WEIGHT) || (rightWeigth >= MAX_POSSIBLE_WEIGHT))
        {
            printf("%d\n", -1);
            return 0;
        }
        if (leftWeigth > rightWeigth)
        {
            if ((set[i].weigth >= weight && set[i].summBefore < weight) || (weight >= set[i].weigth))
            {
                count++;
                rightWeigth += set[i].weigth;
            }
        }
        else if (leftWeigth < rightWeigth)
        {
            if ((set[i].weigth >= -weight && set[i].summBefore < -weight) || (-weight >= set[i].weigth))
            {
                count++;
                leftWeigth += set[i].weigth;
            }
        }
        if (leftWeigth == rightWeigth)
        {
            printf("%d\n", count);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}