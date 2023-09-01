#include <stdio.h>
struct time
{
    int hour;
    int min;
    int sec;
};
struct time add(struct time t1, struct time t2);
struct time diff(struct time t1, struct time t2);
void read(struct time *t);
void display(struct time t);
int main()
{
    struct time time1,time2,sum,difference;
    printf("Enter the Time 1:\n");
    read(&time1);
    printf("Enter the Time 2:\n");
    read(&time2);
    sum = add(time1, time2);
    difference = diff(time1, time2);
    printf("\nTime 1 is: ");
    display(time1);
    printf("Time 2 is: ");
    display(time2);
    printf("Sum of times is: ");
    display(sum);
    printf("Difference of times is: ");
    display(difference);
    return 0;
}
struct time add(struct time t1, struct time t2)
{
    struct time sum;
    sum.hour = t1.hour + t2.hour;
    sum.min = t1.min + t2.min;
    sum.sec = t1.sec + t2.sec;
    if (sum.sec>=60)
    {
        sum.min+=sum.sec / 60;
        sum.sec%=60;
    }
    if (sum.min>=60)
    {
        sum.hour+=sum.min / 60;
        sum.min%=60;
    }
    return sum;
}
struct time diff(struct time t1, struct time t2)
{
    struct time diff;
    int s1=t1.hour*3600+t1.min*60+t1.sec;
    int s2=t2.hour*3600+t2.min*60+t2.sec;
    int diffs=s1-s2;
    if (diffs<0)
    {
        diffs=-diffs;
    }
    diff.hour=diffs/3600;
    diff.min=(diffs%3600) / 60;
    diff.sec= diffs%60;
    return diff;
}
void read(struct time *t)
{
    printf("Enter hour: ");
    scanf("%d", &t->hour);
    printf("Enter minute: ");
    scanf("%d", &t->min);
    printf("Enter second: ");
    scanf("%d", &t->sec);
}
void display(struct time t)
{
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}
