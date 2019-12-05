#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        printf("Wrong data, please try again.\n");
        return -1;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month,day from day of year */

int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 1 || yearday < 1) {
        printf("Wrong data, please try again.\n");
        return -1;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main(void) {
    int year = 1970;
    int month = 10;
    int dat = 18;
    int year_1 = 2020;
    int day_1 = 100;
    int month_2;
    int day_2;

    printf("For %d.%d.%d the Day is: %d\n", dat, month, year, day_of_year(year, month, dat));
    printf("For %dth day in %d year, ", year_1, day_1);
    month_day(year_1, day_1, &month_2, &day_2);
    printf("the Month is = %d, the Day is = %d\n", month_2, day_2);
}