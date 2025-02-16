#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки.
// Каждая из строк не превышает подлине 104. В строках не встречаются пробельные символы.
// На стандартный поток вывода напечатайте два числа, разделённых пробелом:
// первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
// второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
// Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

#define MAXLEN 104

int findMaxPreffix(char *str1, char *str2);
int findMaxSuffix(char str1[], char str2[]);

int main(int agrc, char *argv[])
{
    char temp1[1024] = {0};
    char temp2[1024] = {0};
    scanf("%s", temp1);
    scanf("%s", temp2);
    int len1 = strlen(temp1);
    int len2 = strlen(temp2);
    char *stringFirst = NULL;
    char *stringSecond = NULL;
    stringFirst = (char *)calloc((len1 + 1), sizeof(char));
    stringSecond = (char *)calloc((len2 + 1), sizeof(char));
    strcpy(stringFirst, temp1);
    strcpy(stringSecond, temp2);
    printf("%d %d\n", findMaxPreffix(stringFirst, stringSecond), findMaxSuffix(stringFirst, stringSecond));
    free(stringFirst);
    free(stringSecond);
    return 0;
}

int findMaxPreffix(char *str1, char *str2)
{
    int result = 0;
    int len2 = strlen(str2);
    int len1 = strlen(str1);
    int min = (len1 < len2) ? len1 : len2;
    char *preffix = (char *)calloc(min, sizeof(char));
    char *tmp;
    for (int i = 0; i < min; i++)
    {
        preffix[i] = str1[i];
        tmp = str2 + len2 - 1 - i;
        if (strstr(tmp, preffix))
        {
            result = i + 1;
        }
    }
    free(preffix);
    return result;
};

int findMaxSuffix(char str1[], char str2[])
{
    int result = 0;
    char *suffix;
    for (size_t i = 0; i < strlen(str2) && i < strlen(str1); i++)
    {
        suffix = str1 + strlen(str1) - i - 1;
        if (strstr(str2, suffix) == str2)
        {
            result = i + 1;
        }
    }
    return result;
};
