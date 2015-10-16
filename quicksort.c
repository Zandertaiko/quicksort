/*
* File: quicksort.c
* Programmer: Zander Møysal
* Date: 14.10.2015
*
* This is quicksort. It sorts an array very fast
* 
*/

#include <stdio.h>

void quickSort(int [], int , int);

int partition(int[], int, int);

int main(void)
{
    int values[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};
    
    int i;
    printf("\n\nUnsorted array is: ");
    for (i = 0; i < 9; i++)
    {
        printf(" %d ", values[i]);
    }
    
    quickSort( values, 1, 8);
    
    printf("\n\nSorted array is: ");
    for (i = 0; i < 9; i++)
    {
        printf(" %d ", values[i]);
    }
    printf("\n");
}

void quickSort(int values[], int value, int length)
{
    int p;
    if (value < length)
    {
        p = partition(values, value, length);
        quickSort(values, value, p - 1);
        quickSort(values, p + 1, length);
    }
}

int partition(int values[], int value, int length)
{
    int pivot = values[value];
    int i = value;
    int j, t;
    j = length + 1;
    while ( 1)
    {
        do
        {
            i++;
        }
        while (values[i] <= pivot && i <= length);
        do
        {
            j--;
        }
        while (values[j] > pivot);
        if (i >= j)
        {
            break;
        }
        t = values[i]; values[i] = values[j]; values[j] = t;   
    }
    t = values[value]; values[value] = values[j]; values[j] = t;
    return j;
}
