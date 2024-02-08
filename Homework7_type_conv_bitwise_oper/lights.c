#include <stdio.h>

int main(void)
{
    unsigned char lights = 0; // 0000 0000
    unsigned char light_room_1 = 1 << 0; // 0000 0001
    unsigned char light_room_2 = 1 << 1; // 0000 0010
    unsigned char light_room_3 = 1 << 2; // 0000 0100
    unsigned char light_room_4 = 1 << 3; // 0000 1000
    unsigned char light_room_5 = 1 << 4; // 0001 0000
    unsigned char light_room_6 = 1 << 5; // 0010 0000
    unsigned char light_room_7 = 1 << 6; // 0100 0000
    unsigned char light_room_8 = 1 << 7; // 1000 0000

    int end = 1;
    while(end)
    {
        printf("Choose an option by entering 1,2 or 3: \n");
        printf("1. Switch lights \n");
        printf("2. Print state \n");
        printf("3. Exit \n");
        int answer;
        scanf("%d", &answer);

        if(answer == 3)
        {
            end = 0;
            break;
        }
        else if(answer == 1)
        {
            printf("Enter the number of the light you want to turn of/on (a number between 1 and 8): \n");
            int number;
            scanf("%d", &number);

            switch (number)
            {
            case 1:
                lights = lights ^ light_room_1;
                break;
            
            case 2:
                lights = lights ^ light_room_2;
                break;

            case 3:
                lights = lights ^ light_room_3;
                break;

            case 4:
                lights = lights ^ light_room_4;
                break;

            case 5:
                lights = lights ^ light_room_5;
                break;

            case 6:
                lights = lights ^ light_room_6;
                break;

            case 7:
                lights = lights ^ light_room_7;
                break;

            case 8:
                lights = lights ^ light_room_8;
                break;

            default:
                printf("ERROR! Invalid number entered!\n");
                break;
            }
        }
        else if(answer == 2)
        {
            if((lights & light_room_1) == light_room_1)
            {
                printf("1 ");
            }
            if((lights & light_room_2) == light_room_2)
            {
                printf("2 ");
            }
            if((lights & light_room_3) == light_room_3)
            {
                printf("3 ");
            }
            if((lights & light_room_4) == light_room_4)
            {
                printf("4 ");
            }
            if((lights & light_room_5) == light_room_5)
            {
                printf("5 ");
            }
            if((lights & light_room_6) == light_room_6)
            {
                printf("6 ");
            }
            if((lights & light_room_7) == light_room_7)
            {
                printf("7 ");
            }
            if((lights & light_room_8) == light_room_8)
            {
                printf("8 ");
            }
            printf("\n");
        }
    }
    return 0;
}