#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 64

typedef struct {
    char *dayName;
    int date;
    char *activity;
} Day;

void create(Day *day);
void read(Day calendar[], int size);
void display(Day calendar[], int size);
void destroyDays(Day *calendar, int size);

int main() {
    int n;
    printf("Enter the number of day in the week: ");
    scanf("%d", &n);

    Day calendar[n];
    read(calendar, n);

    display(calendar, n);
    destroyDays(calendar, n);

    return 0;
}

void create(Day *day) {
    day = (Day *) malloc(sizeof(Day));
    day->dayName = (char *) malloc(MAX_LEN * sizeof(char));
    day->activity = (char *) malloc(MAX_LEN * sizeof(char));
    
    printf("Enter Day Name: ");
    fgets(day->dayName, MAX_LEN, stdin);

    printf("Enter Activity: ");
    fgets(day->activity, MAX_LEN, stdin);

    printf("Enter date: ");
    scanf("%d", &day->date);
}

void read(Day calendar[], int size) {
    for (int i = 0; i < size; i++) {
        create(&calendar[i]);
    }
}

void display(Day calendar[], int size) {
    printf("Week's Activity Detail");
    for (int i = 0; i < size; i++) {
        printf("Date: %d\n", calendar[i].date);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Activity for the Day: %s\n", calendar[i].activity);
    }
}

void destroyDays(Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}