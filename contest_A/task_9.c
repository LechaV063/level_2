#include <stdio.h>
#include <stdint.h>
#define ARRAY_LENGHT 32

// В программе реализована структура данных:
// struct pack_array {
// uint32_t array; // поле для хранения упакованного массива из 0 и 1
// uint32_t count0 : 8; // счетчик нулей в array
// uint32_t count1 : 8; // счетчик единиц в array
// }
// Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
// Функция должна строго соответствовать прототипу:

struct pack_array
{
    uint32_t array;      // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};
void array2struct(int arr[], struct pack_array *myStructure)
{
    myStructure->array = 0;
    for (size_t i = 0; i < ARRAY_LENGHT; i++)
    {
        myStructure->array <<= 1;
        myStructure->array += arr[i];
        if (arr[i])
        {
            (myStructure->count1)++;
        }
        else
        {
            (myStructure->count0)++;
        }
    }
};

void structPrint(struct pack_array *myStructure)
{
    printf("%u %d %d\n", myStructure->array, myStructure->count0, myStructure->count1);
}
int main(int argc, char **argv)
{
    int inputArray[ARRAY_LENGHT];
    struct pack_array myStruct;
    for (size_t i = 0; i < ARRAY_LENGHT; i++)
    {
        scanf("%d", &inputArray[i]);
    }
    myStruct.array = 0;
    myStruct.count0 = 0;
    myStruct.count1 = 0;
    array2struct(inputArray, &myStruct);
    structPrint(&myStruct);
    return 0;
}