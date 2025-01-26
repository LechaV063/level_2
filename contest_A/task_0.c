#include <stdio.h>
#include <stdint.h>

// На стандартном потоке ввода задаётся натуральное число N (N > 0),
// после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.
// Указание: использовать массивы запрещается.

typedef struct sequence
{
    uint32_t N;  // количество членов последовательности
    int maximum; // текущий максимум
    int count;   // количество повторений
} sequence;

int main(int argc, char **argv)
{
    int temp;
    sequence mySequence = {0, 0, 0};
    scanf("%u", &mySequence.N);
    scanf("%d", &mySequence.maximum);
    mySequence.count = 1;
    mySequence.N--;
    while (mySequence.N > 0)
    {
        scanf("%d", &temp);
        if (temp > mySequence.maximum)
        {
            mySequence.N--;
            mySequence.maximum = temp;
            mySequence.count = 1;
        }
        else if (temp == mySequence.maximum)
        {
            mySequence.N--;
            mySequence.count++;
        }
        else
        {
            mySequence.N--;
        }
    }
    printf("%d\n", mySequence.count);
    return 0;
}