/*
Описана структура данных для хранения информации об использованной памяти:
typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. 
Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;

size_t totalMemoryUsage(list *head){
    list *pTmp;
    size_t summ = 0;
    for (pTmp = head; pTmp; pTmp = pTmp->next)
    {      
            summ += pTmp->size;
    }
    return summ;
}

// void printList(list head[])
// {
//     list *tmp;
//     for (tmp = head; tmp; tmp = tmp->next)
//     {
//         printf("%p %lu \n", tmp->address, tmp->size);
//     }
// };

// int main(int argc, char *argv[])
// {
//     int arrSize = 0;
//     scanf("%d", &arrSize);
//     list pList[arrSize];
//     for (size_t i = 0; i < arrSize; i++)
//     {
//         scanf("%p %lu", &pList[i].address, &pList[i].size);
//         pList[i].next = NULL;
//         if (i > 0)
//         {
//             pList[i - 1].next = &pList[i];
//         }
//     }
//     // printList(pList);
//     printf("%lu\n", totalMemoryUsage(pList));
//     return 0;
// }
