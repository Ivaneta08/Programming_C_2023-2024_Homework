#include <stdio.h>
#include "dynarr.h"

void printDynamicArray(DynamicArray * arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%f ", arr->buffer[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Executing tests \n");

    DynamicArray dynarr = init(2);

    printf("Initial capacity: %u\n", dynarr.capacity);
    printf("Initial size: %u\n", dynarr.size);

    pushBack(&dynarr, 10);
    pushBack(&dynarr, 15);
    printDynamicArray(&dynarr);

    push(&dynarr, 1, 77);
    printDynamicArray(&dynarr);

    pushFront(&dynarr, 105);
    pushFront(&dynarr, 11);
    printDynamicArray(&dynarr);

    DynArrType secondElement = getElement(&dynarr, 1);
    printf("Second element: %f\n", secondElement);

    setElement(&dynarr, 10, 999);
    printDynamicArray(&dynarr);

    DynArrType thirdElement = removeElement(&dynarr, 2);
    printf("Third element: %f\n", thirdElement);
    printDynamicArray(&dynarr);

    DynArrType firstElement = popFront(&dynarr);
    printf("First element: %f\n", firstElement);
    printDynamicArray(&dynarr);

    DynArrType lastElement = popBack(&dynarr);
    printf("Last element: %f\n", lastElement);
    printDynamicArray(&dynarr);

    printf("Element with value 105 at: %d\n", find(&dynarr, 105));
    printf("Element with value 9 at: %d\n", find(&dynarr, 9));

    release(&dynarr);

    return 0;
}