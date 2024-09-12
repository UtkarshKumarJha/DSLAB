#include <stdio.h>

typedef struct {
    int hour;
    int min;
    int sec;
} Time;


void normalizeTime(Time *t) {
    if (t->sec >= 60) {
        t->min += t->sec / 60;
        t->sec = t->sec % 60;
    }
    if (t->min >= 60) {
        t->hour += t->min / 60;
        t->min = t->min % 60;
    }
    if (t->hour >= 24) {
        t->hour = t->hour % 24;
    }
}


void readTime(Time *t) {
    printf("Enter hour: ");
    scanf("%d", &t->hour);
    printf("Enter minute: ");
    scanf("%d", &t->min);
    printf("Enter second: ");
    scanf("%d", &t->sec);
    normalizeTime(t);
}


void displayTime(Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}


Time addTime(Time t1, Time t2) {
    Time result;
    result.hour = t1.hour + t2.hour;
    result.min = t1.min + t2.min;
    result.sec = t1.sec + t2.sec;
    normalizeTime(&result);
    return result;
}


Time differenceTime(Time t1, Time t2) {
    Time result;
    int totalSeconds1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int totalSeconds2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
    int diffSeconds = totalSeconds1 - totalSeconds2;

    if (diffSeconds < 0) {
        printf("Error: Time1 should be greater than or equal to Time2 for difference calculation.\n");
        result.hour = result.min = result.sec = 0;
        return result;
    }

    result.hour = diffSeconds / 3600;
    diffSeconds %= 3600;
    result.min = diffSeconds / 60;
    result.sec = diffSeconds % 60;
    return result;
}

int main() {
    Time time1, time2, result;

    printf("Enter first time:\n");
    readTime(&time1);

    printf("Enter second time:\n");
    readTime(&time2);

    result = addTime(time1, time2);
    printf("Sum of times: ");
    displayTime(result);

    result = differenceTime(time1, time2);
    if (result.hour != 0 || result.min != 0 || result.sec != 0) {
        printf("Difference of times: ");
        displayTime(result);
    }

    return 0;
}
