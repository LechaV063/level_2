#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Сколько различных трехзначных чисел можно получить из заданного натурального N,
// вычеркивая цифры из его десятичной записи?

int main(int agrc, char *argv[])
{
    char number[100];
    scanf("%s", number);
    char digits[3];
    int result = 0, count = 0, temp;
    for (size_t i = 100; i < 1000; i++)
    {
        temp = i;
        digits[2] = (temp % 10) + '0';
        temp /= 10;
        digits[1] = (temp % 10) + '0';
        digits[0] = (temp / 10) + '0';
        int start_id = 0;
        int is_found = 0;
        for (int k = 0; k < 3; k++)
        {
            int len = strlen(number);
            for (size_t j = start_id; j < len; j++)
            {
                if (number[j] == digits[k])
                {
                    start_id = j + 1;
                    is_found++;
                    break;
                }
            }
        }
        if (is_found == 3)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
