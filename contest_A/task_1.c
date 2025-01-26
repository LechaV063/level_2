#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// На стандартном потоке ввода задается целое неотрицательное число N и
// последовательность допустимых символов в кодировке ASCII, оканчивающаяся точкой.
// Допустимые символы - латинские буквы 'a' ... 'z', 'A' ... 'Z' и пробел.
// Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') шифром Цезаря,
// пробелы вывести без изменения. Число N задает сдвиг в шифре. Шифр Цезаря заключается в
// следующем преобразовании. Пусть буквы алфавита пронумерованы от 0 до K - 1,
// где K - число символов в алфавите. Тогда символ с номером n кодируется символом с номером
// p = (n + N) mod K (mod - операция взятия остатка).
// На стандартном потоке вывода напечатать зашифрованное сообщение, оканчивающееся точкой.
// Преобразование требуется выполнять независимо для заглавных и строчных латинских букв.
// Указание: использовать массивы запрещается.

#define BASE 26

char getCesar(uint32_t shift, char chr)
{
    if (chr == ' ')
    {
        return ' ';
    }
    else if (chr == '.')
    {
        return ' ';
    }
    else if (chr >= 'a' && chr <= 'z')
    {
        chr = ((chr - 'a' + shift) % BASE) + 'a';
    }
    else if (chr >= 'A' && chr <= 'Z')
    {
        chr = ((chr - 'A' + shift) % BASE) + 'A';
    }
    else
    {
        chr = 0;
    }
    return chr;
}
int main(int argc, char **argv)
{
    uint32_t N;
    char currentChar;
    scanf("%u ", &N);
    scanf("%c", &currentChar);
    while (currentChar != '.')
    {
        printf("%c", getCesar(N, currentChar));
        scanf("%c", &currentChar);
    }
    printf("%c\n", currentChar);
    return 0;
}