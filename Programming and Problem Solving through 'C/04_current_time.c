#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now = time(NULL);
    struct tm *current = localtime(&now);

    if (current == NULL)
    {
        printf("Could not read the system time.\n");
        return 1;
    }

    printf("Date: %02d-%02d-%04d\n",
           current->tm_mday, current->tm_mon + 1, current->tm_year + 1900);
    printf("Time: %02d:%02d:%02d\n",
           current->tm_hour, current->tm_min, current->tm_sec);

    return 0;
}
