#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday);

/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        printf("Wrong data, please try again.\n");
        return -1;
    }
    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
    
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    printf("the Day is: %d\n", day);
}

/* month_day: set month,day from day of year */

int month_day(int year, int yearday) {
    int i, leap;

    if (year < 1 || yearday < 1) {
        printf("Wrong data, please try again.\n");
        return -1;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    printf("Month: %d, Day in month: %d\n", i, yearday);
}

int main(void) {
    int year = 1970;
    int month = 10;
    int dat = 18;
    int year_1 = 2020;
    int day_1 = 100;

    printf("For 18.10.1970 ");
    day_of_year(year, month, dat);
    printf("For 100th day in 2020 ");
    month_day(year_1, day_1);
}