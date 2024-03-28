#include <stdio.h>

void WeekLegend()
{
    printf("1 - Monday\n");
    printf("2 - Tuesday\n");
    printf("3 - Wednesday\n");
    printf("4 - Thursdau\n");
    printf("5 - Friday\n");
    printf("6 - Saturday\n");
    printf("7 - Sunday\n");
}

enum Day_of_the_week{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(void)
{
    WeekLegend();

    int input;
    printf("Enter number for a day of the week: ");
    scanf("%d", &input);

    enum Day_of_the_week today = input;

    switch (today)
    {
        case MONDAY:
            printf("Today is Monday. :(\n");
            break;
        case TUESDAY:
            printf("Today is Tuesday.\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n");
            break;
        case THURSDAY:
            printf("Today is Thursday.\n");
            break;
        case FRIDAY:
            printf("Today is Friday! :D\n");
            break;
        case SATURDAY:
            printf("Today is Saturday! :)\n");
            break;
        case SUNDAY:
            printf("Today is Sunday! :]\n");
            break;
    
        default:
            printf("Invalid imput! >:(");
            break;
    }
    return 0;
}