#include "header.c"
char *readstring()
{
    char temp;
    char *stringInput=malloc(30);
    scanf("%c",&temp);
    scanf("%[^\n]",stringInput);
    return stringInput;
}


void datetime()
{
    time_t t = time(NULL);
    int month,date,year,h,m,s;
    // printf("\n Current date and time is : %s", ctime(&t));
    struct tm tm = *localtime(&t);
    date = tm.tm_mday;
    month =  tm.tm_mon+1;
    year = tm.tm_year+1900;
    h = tm.tm_hour;
    m = tm.tm_min;
    s = tm.tm_sec;
}