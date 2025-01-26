#include <stdio.h>
#include <stdint.h>

// Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000) натуральных чисел,
// не превосходящих 1 000 000. Известно, что ровно одно число в этом наборе встречается один раз,
// а остальные — ровно по два раза. Помогите им найти это число.
// Входные данные: в первой входной строке вводится число N, затем по одному числу в строке вводятся
//      N натуральных чисел, не превосходящих 2000 000 000.
// Выходные данные: ваша программа должна определить число, встречающееся один раз, и вывести его на экран.
// Указание: использовать массивы запрещается.

int main(int argc, char **argv)
{
    uint32_t result = 0, size;
    int temp;
    scanf("%u", &size);
    for (uint32_t i = 0; i < size; i++)
    {
        scanf("%d", &temp);
        result ^= temp;
    }
    printf("%d\n", result);
    return 0;
}