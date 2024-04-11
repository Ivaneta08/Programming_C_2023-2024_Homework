#include <stdio.h>

#define NAME_LEN 30

typedef struct node
{
    char first_name[NAME_LEN];
    struct node * father;
    struct node * mother;
    struct node * marriedto;
} Node;


int main(void)
{
    Node Ivan = 
    {
        .first_name = "Ivan",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };

    Node Zlatka = 
    {
        .first_name = "Zlatka",
        .father = NULL,
        .mother = NULL,
        .marriedto = &Ivan
    };

    Ivan.marriedto = &Zlatka;

    Node Vasil = 
    {
        .first_name = "Vasil",
        .father = &Ivan,
        .mother = &Zlatka,
        .marriedto = NULL
    };

    Node Valio = 
    {
        .first_name = "Valio",
        .father = NULL,
        .mother = NULL,
        .marriedto = NULL
    };

    Node Ivanka = 
    {
        .first_name = "Ivanka",
        .father = NULL,
        .mother = NULL,
        .marriedto = &Valio
    };

    Valio.marriedto = &Ivanka;

    Node Elina = 
    {
        .first_name = "Elina",
        .father = &Valio,
        .mother = &Ivanka,
        .marriedto = &Vasil
    };

    Vasil.marriedto = &Elina;

    Node Ivaneta = 
    {
        .first_name = "Ivaneta",
        .father = &Vasil,
        .mother = &Elina,
        .marriedto = NULL
    };

    return 0;
}