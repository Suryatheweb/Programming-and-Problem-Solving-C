#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int hour = 0, minute = 0, second = 0;

    while (1)
    {
        printf("\r%02d:%02d:%02d", hour, minute, second);
        fflush(stdout);
        sleep(1);

        second++;

        if (second == 60)
        {
            minute++;
            second = 0;
        }

        if (minute == 60)
        {
            hour++;
            minute = 0;
        }

        if (hour == 24)
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
    }

    return 0;
}
