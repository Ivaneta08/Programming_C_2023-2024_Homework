#include <stdio.h>
#include "dynarr_donors.h"

void printDonors(DynamicArray * arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("Donor No%d's EGN: %ld\n", i+1, arr->buffer[i]);
    }
  printf("\n");
}

void menu()
{
    printf("1. Add a new donor\n");
    printf("2. Remove donor\n");
    printf("3. Print all donors' EGN\n");
    printf("4. Exit\n");
    printf("Enter number to choose: ");
}

int main(void) {

    int end = 1;

    DynamicArray donors_egn = init(2);

    while(end)
    {
        int choice;
        menu();
        scanf("%d", &choice);

        long egn;
        uint index;

        switch (choice)
        {
        case 1:
            printf("Enter the EGN of the donor you wish to add:\n");
            scanf("%ld", &egn);

            pushBack(&donors_egn, egn);

            index = find(&donors_egn, egn);

            if(index != -1) printf("EGN: %ld successfully addad to list\n", egn);
            else printf("Error adding EGN: %ld\n", egn);
            break;

        case 2:
            printf("Enter the egn of the donor you wish to remove:\n");
            scanf("%ld", &egn);

            index = find(&donors_egn, egn);

            if(index != -1) printf("Egn: %ld removed from list\n", removeElement(&donors_egn, index));
            else printf("Unable to find EGN\n");
            break;

        case 3:
            printDonors(&donors_egn);
            break;

        case 4:
            end = 0;
            break;
        
        default:
            printf("ERROR! Invalid imput. Try again.\n");
            break;
        }
    }

    release(&donors_egn);
    
    return 0;
}