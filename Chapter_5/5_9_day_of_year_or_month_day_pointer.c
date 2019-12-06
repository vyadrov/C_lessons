#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day) {
    int i, leap;
    char *ptr;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;    
    ptr = &daytab[leap][1];

    for (i = 1; i < month; i++) {
        day += *ptr;
        ptr++;
    }
    return day;
}

/* month_day: set month,day from day of year */

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    char *ptr;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    ptr = &daytab[leap][1];

    for (i = 1; yearday > *ptr; i++) {
        yearday -= *ptr;
        ptr++;
    }
    *pmonth = i;
    *pday = yearday;    
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
    printf("For %dth day in %d year, ", day_1, year_1);
    month_day(year_1, day_1, &month_2, &day_2);
    printf("the Month is = %d, the Day is = %d\n", month_2, day_2);
}