#include "sort.h"
/**
 * funtion swap - swaps elements
 * @i: first element
 * @j: second element
 */
void _swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
/**
 * build_heap - builds heap out of list
 *
 * @list_heap: the list
 * @i: heap size
 * @j: root index
 * @size: Number of elements of the list
 */

void build_heap(int *list_heap, int i, int j, size_t size)
{
    int max = j;
    int left = j * 2 + 1;
    int right = j * 2 + 2;

    if (left < i && list_heap[left] > list_heap[max])
        max = left;

    if (right < i && list_heap[right] > list_heap[max])
        max = right;

    if (max != j)
    {
        _swap(&list_heap[j], &list_heap[max]);
        print_array(list_heap, size);
        build_heap(list_heap, i, max, size);
    }
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @list_heap: an unordered list
 * @size: Number of elements of the list
 */

void heap_sort(int *list_heap, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        build_heap(list_heap, size, i, size);

    for (i = size - 1; i >= 0; i--)
    {
        _swap(&list_heap[0], &list_heap[i]);
        if (i != 0)
            print_array(list_heap, size);
        build_heap(list_heap, i, 0, size);
    }
}