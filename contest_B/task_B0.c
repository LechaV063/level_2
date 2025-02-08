/*
Описана структура данных
typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
Если есть несколько таких блоков, то вернуть адрес любого из них.
Прототип функции:
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    list *pTmp;
    size_t max = 0;
    uint64_t pAddr = 0;
    for (pTmp = head; pTmp; pTmp = pTmp->next)
    {
        if (pTmp->size > max)
        {
            max = pTmp->size;
            pAddr = pTmp->address;
        }
    }
    return pAddr;
};

// void printList(list head[])
// {
//     list *tmp;
//     for (tmp = head; tmp; tmp = tmp->next)
//     {
//         printf("%lu %lu \n", tmp->address, tmp->size);
//     }
// };

// int main(int argc, char *argv[])
// {
//     int arrSize = 0;
//     scanf("%d", &arrSize);
//     list pList[arrSize];
//     for (size_t i = 0; i < arrSize; i++)
//     {
//         scanf("%lu %lu", &pList[i].address, &pList[i].size);
//         pList[i].next = NULL;
//         if (i > 0)
//         {
//             pList[i - 1].next = &pList[i];
//         }
//     }
//     // printList(pList);
//     printf("%lu\n", findMaxBlock(pList));
//     return 0;
// }
