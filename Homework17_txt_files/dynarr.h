#ifndef DYN_ARR_H
#define DYN_ARR_H

#define BOOK_NAME_LEN 50
#define AUTHOR_NAME_LEN 30
#define GENRE_LEN 20

typedef struct
{
    char name[BOOK_NAME_LEN];
    char author[AUTHOR_NAME_LEN];
    char genre[GENRE_LEN];
    int published_year;
    int ISBN;
}Book;

typedef Book DynArrType;
typedef unsigned int uint;

typedef struct {
    DynArrType * buffer;
    uint size;
    uint capacity;
} DynamicArray;

DynamicArray init(uint capacity);

void push(DynamicArray * arr, uint index, DynArrType value);
void pushFront(DynamicArray * arr, DynArrType value);
void pushBack(DynamicArray * arr, DynArrType value);

void setElement(DynamicArray * arr, uint index, DynArrType value);
DynArrType getElement(DynamicArray * arr, uint index);

DynArrType removeElement(DynamicArray * arr, uint index);
DynArrType popFront(DynamicArray * arr);
DynArrType popBack(DynamicArray * arr);

int find(DynamicArray * arr, DynArrType value);

void release(DynamicArray * arr);

#endif