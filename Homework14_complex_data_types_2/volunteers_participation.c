#include <stdio.h>

#define TITLE_LEN 40
#define DESCRIPTION_LEN 80
#define NAME_LEN 20
#define NUMBER_LEN 12
#define EMAIL_LEN 30
#define MAX_VOLUNTEERS_PER_CAUSE 100

typedef struct
{
    int hours;
    int minutes;
}Time;


typedef enum 
{
    false = 0,
    true = 1
}Bool;

typedef struct
{
    char first_name[NAME_LEN];
    char second_name[NAME_LEN];
    char third_name[NAME_LEN];
    char email[EMAIL_LEN];
    char phone_number[NUMBER_LEN];
}Volunteer;

typedef struct
{
    Volunteer volunteer;
    Bool answer;
}VolunteerAnswer;

typedef struct
{
    char title[TITLE_LEN];
    char description[DESCRIPTION_LEN];
    struct
    {
        int day;
        int month;
        int year;
        Time time;
    } date;
    VolunteerAnswer volunteeranswers[MAX_VOLUNTEERS_PER_CAUSE];
}Cause;

void printTime(Time * time)
{
    printf("\t%d:%d\n", time->hours, time->minutes);
}

void printVolunteer(Volunteer * vol)
{
    printf("\tName: %s %s %s\n", vol->first_name, vol->second_name, vol->third_name);
    printf("\tEmail: %s\n", vol->email);
    printf("\tPhone number: %s\n", vol->phone_number);
}

void printVolunteerAnswers(VolunteerAnswer vol_answers[], int num_volunteers)
{
    for(int i=0; i < num_volunteers; i++)
    {
        printVolunteer(&(vol_answers[i].volunteer));
        if(vol_answers[i].answer)
        {
            printf("\tAttending! :D\n");
        }
        else
        {
            printf("\tNot attending. :<\n");
        }
        printf("\n");
    }
}

void printCause(Cause * cause)
{
    printf("Title:\n\t%s\n", cause->title);
    
    printf("Description:\n\t%s\n", cause->description);
    
    printf("Date:\n");
    printf("\t%d.%d.%d\n", (*cause).date.day, (*cause).date.month, cause->date.year);
    
    //printf("\tTime:\n");
    printTime(&(cause->date.time));

    printf("Volunteers and their answers:\n");
    printVolunteerAnswers(cause->volunteeranswers, MAX_VOLUNTEERS_PER_CAUSE);
}

int main(void)
{
    Cause team_trees = 
    {
        .title = "Team trees!",
        .description = "Let's plant more trees for our planet!",
        {
            .day = 9,
            .month = 4,
            .year = 2008,
            {
                .hours = 9,
                .minutes = 30
            }
        },
        .volunteeranswers = 
        {
            [0] = {
                .volunteer =
                {
                    .first_name = "Kristiyan",
                    .second_name = "Kirilov",
                    .third_name = "Kobarelov",
                    .email = "random_email@gmail.com",
                    .phone_number = "088 888 8888"
                },
                .answer = true
            },
            [2] = {
                .volunteer =
                {
                    .first_name = "Ivaneta",
                    .second_name = "Vasileva",
                    .third_name = "Ivanova",
                    .email = "random_email2@abv.bg",
                    .phone_number = "088 999 9999"
                },
                .answer = true
            },
            [1] = {
                .volunteer =
                {
                    .first_name = "Magdalena",
                    .second_name = "Georgieva",
                    .third_name = "Papazova",
                    .email = "my_cousin@gmail.bg",
                    .phone_number = "088 333 3333"
                },
                .answer = false
            },
            [20 ... 30] = {
                .volunteer =
                {
                    .first_name = "Ignat",
                    .second_name = "Velinov",
                    .third_name = "Kamchev",
                    .email = "idk_anymore@gmail.bg",
                    .phone_number = "088 444 4444"
                },
                .answer = false
            }
        }
    };

    Cause team_seas = 
    {
        .title = "Team seas!",
        .description = "Let's clean the oceans for our planet!",
        {
            .day = 16,
            .month = 1,
            .year = 2028,
            {
                .hours = 12,
                .minutes = 45
            }
        },
        .volunteeranswers = 
        {
            [0] = {
                .volunteer =
                {
                    .first_name = "Kristiyan",
                    .second_name = "Kirilov",
                    .third_name = "Kobarelov",
                    .email = "random_email@gmail.com",
                    .phone_number = "088 888 8888"
                },
                .answer = false
            },
            [2] = {
                .volunteer =
                {
                    .first_name = "Ivaneta",
                    .second_name = "Vasileva",
                    .third_name = "Ivanova",
                    .email = "random_email2@abv.bg",
                    .phone_number = "088 999 9999"
                },
                .answer = true
            },
            [1] = {
                .volunteer =
                {
                    .first_name = "Magdalena",
                    .second_name = "Georgieva",
                    .third_name = "Papazova",
                    .email = "my_cousin@gmail.bg",
                    .phone_number = "088 333 3333"
                },
                .answer = true
            },
            [80 ... 99] = {
                .volunteer =
                {
                    .first_name = "Ignat",
                    .second_name = "Velinov",
                    .third_name = "Kamchev",
                    .email = "idk_anymore@gmail.bg",
                    .phone_number = "088 444 4444"
                },
                .answer = true
            }
        }
    };

    printCause(&team_trees);

    printCause(&team_seas);

    return 0;
}