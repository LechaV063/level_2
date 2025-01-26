#include <stdio.h>

// Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float,
// она возвращает порядок который хранится в поле EXP в виде десятичного целого числа.
// Функция должна строго соответствовать прототипу
// int extractExp(float)
int extractExp(float);
int main(int argc, char **argv)
{
    int exp;
    float ft;
    scanf("%f", &ft);
    printf("%d\n", extractExp(ft));
    return 0;
}
int extractExp(float numb)
{
    int exp = 0;
    // if (numb < 0)
    //     numb = -numb;
    int *pInt = NULL;
    pInt = (int *)&numb;
    exp = (*pInt >> 23) & 0xff;
    return exp;
};