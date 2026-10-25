#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char *month_names[] = {
    "",
    "\n\n  --- January ---",
    "\n\n  --- February ---",
    "\n\n  --- March ---",
    "\n\n  --- April ---",
    "\n\n  --- May ---",
    "\n\n  --- June ---",
    "\n\n  --- July ---",
    "\n\n  --- August ---",
    "\n\n  --- September ---",
    "\n\n  --- October ---",
    "\n\n  --- November ---",
    "\n\n  --- December ---"
};

int inputyear(void)
{
    int year;

    printf("Please enter a year: ");
    scanf("%d", &year);

    return year;
}

int determineleapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}

int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;

    return daycode;
}

void calendar(int year, int daycode)
{
    int month, day;

    for (month = 1; month <= 12; month++)
    {
        printf("%s\n", month_names[month]);
        printf("SUN MON TUE WED THU FRI SAT\n");

        for (day = 1; day <= daycode; day++)
        {
            printf("    ");
        }

        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%3d ", day);

            if ((day + daycode) % 7 == 0)
            {
                printf("\n");
            }
        }

        printf("\n");

        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void)
{
    int year, daycode;

    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calendar(year, daycode);
    printf("\n");

    return 0;
}
