#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Сколько различных трехзначных чисел можно получить из заданного натурального N,
// вычеркивая цифры из его десятичной записи?

/*!
    @brief сколько и каких цифр в числе
    @param digit цифры из числа
    @param count количество повторений каждой цифры
*/
struct digitSet
{
    uint64_t digit[10];
    uint64_t count[10];
};

/*!
    @brief вычисляет сочетание n по k
    @param n - количество в наборе
    @param k - выборка для сочетаний
*/
int cnk2(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

/*!
    @brief раскладывает число в структуру по количеству цифр и их повторений
*/
struct digitSet getNumberOfDigits(char *num)
{
    struct digitSet result;
    for (size_t i = 0; i < 10; i++)
    {
        result.digit[i] = 0;
        result.count[i] = 0;
    }
    char temp;
    int len = strlen(num);
    for (size_t i = 0; i < len; i++)
    {if (num[i]>= '0' && num[i] <= '9')
        temp = num[i]-'0';
        result.count[temp]++;
        result.digit[temp] = 1;
    }
    return result;
}

int main(int agrc, char *argv[])
{
    char number[100];
    scanf("%s", number);
    struct digitSet inputSet = getNumberOfDigits(number);
    int countDigits = 0; ///< количество разрядов в числе
    int DigitKind = 0;   ///< количество различных цифр в числе
    for (size_t i = 0; i < 10; i++)
    {
        countDigits += inputSet.count[i];
        DigitKind += inputSet.digit[i];
    }
    int result;
    // printf("Количество разрядов в числе = %d\nКоличество разных цифр в числе = %d\n",
    //        countDigits, DigitKind);
    if (countDigits < 3)
    {
        printf("Слишком мало разрядов в числе\n");
        return 0;
    }
    if (inputSet.count[0])
        result = cnk2(DigitKind - 1, 1) * cnk2(DigitKind - 1, 1) * cnk2(DigitKind - 2, 1);
    else
        result = cnk2(DigitKind, 1) * cnk2(DigitKind - 1, 1) * cnk2(DigitKind - 2, 1);
    int itog = result;
    for (size_t i = 0; i < 10; i++)
    {
        if (i && inputSet.count[i] == 2)
        {
            itog += result;
        }
        else if (i && inputSet.count[i] > 2)
        {
            itog += result;
            itog += 1;
        }
        else if (i == 0 && inputSet.count[i] > 1)
        {
            itog += result;
        }
    }
    printf("%d\n", itog);
    return 0;
}
