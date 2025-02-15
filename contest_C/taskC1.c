#include <stdio.h>
#include <string.h>

// На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки.
// Каждая из строк не превышает подлине 104. В строках не встречаются пробельные символы.
// На стандартный поток вывода напечатайте два числа, разделённых пробелом:
// первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
// второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
// Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

#define MAXLEN 104

int findMaxPreffix(char str1[], char str2[]);
int findMaxSuffix(char str1[], char str2[]);

int main(int agrc, char *argv[])
{
    char stringFirst[MAXLEN] = {0};
    char stringSecond[MAXLEN] = {0};
    scanf("%s", stringFirst);
    scanf("%s", stringSecond);
    printf("%d %d\n", findMaxPreffix(stringFirst, stringSecond), findMaxSuffix(stringFirst, stringSecond));
    return 0;
}

int findMaxPreffix(char str1[], char str2[])
{
    int result = 0;
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    return result;
};

int findMaxSuffix(char str1[], char str2[])
{
    int result = 0;

    return result;
};
