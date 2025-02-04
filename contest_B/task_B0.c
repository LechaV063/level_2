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
    list *p;
    size_t max = 0;
    uint64_t pAddr = 0;
    for (p = head; p; p = p->next)
    {
        if (p->size > max)
            max = p->size;
        pAddr = p->address;
    }
    return pAddr;
};

int main(int argc, char *argv[])
{
    int arrSize = 0;
    scanf("%d", arrSize);
    list *arr;
    arr = malloc(sizeof(list)*arrSize);
    arr->next=NULL;
    for (size_t i = 0; i < arrSize; i++)
    {
        /* code */
    }
    

    return 0;
}