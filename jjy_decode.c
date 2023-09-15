#include "jjy_decode.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>

int jjy_decode(const char in[60], struct tm* t)
{
    for (int i = 0; i < 60; i++) {
        printf("%d: %c\n", i, in[i]);
        assert(in[i] == '0' || in[i] == '1' || in[i] == 'm');
        assert(in[i] != 0);
    }
    int year = 0;
    int day_of_year = 0;
    int day_of_week = 0;
    int hour = 0;
    int minute = 0;

    if (in[1] == '1') {
        minute += 40;
    }
    if (in[2] == '1') {
        minute += 20;
    }
    if (in[3] == '1') {
        minute += 10;
    }
    if (in[5] == '1') {
        minute += 8;
    }
    if (in[6] == '1') {
        minute += 4;
    }
    if (in[7] == '1') {
        minute += 2;
    }
    if (in[8] == '1') {
        minute += 1;
    }
    
    if (in[12] == '1') {
        hour += 20;
    }
    if (in[13] == '1') {
        hour += 10;
    }
    if (in[15] == '1') {
        hour += 8;
    }
    if (in[16] == '1') {
        hour += 4;
    }
    if (in[17] == '1') {
        hour += 2;
    }
    if (in[18] == '1') {
        hour += 1;
    }

    if (in[22] == '1') {
        day_of_year += 200;
    }
    if (in[23] == '1') {
        day_of_year += 100;
    }
    if (in[25] == '1') {
        day_of_year += 80;
    }
    if (in[26] == '1') {
        day_of_year += 40;
    }
    if (in[27] == '1') {
        day_of_year += 20;
    }
    if (in[28] == '1') {
        day_of_year += 10;
    }
    if (in[29] == '1') {
        day_of_year += 8;
    }
    if (in[30] == '1') {
        day_of_year += 4;
    }
    if (in[31] == '1') {
        day_of_year += 2;
    }
    if (in[32] == '1') {
        day_of_year += 1;
    }
    if (in[41] == '1') {
        year += 80;
    }
    if (in[42] == '1') {
        year += 40;
    }
    if (in[43] == '1') {
        year += 20;
    }
    if (in[44] == '1') {
        year += 10;
    }
    if (in[45] == '1') {
        year += 8;
    }
    if (in[46] == '1') {
        year += 4;
    }
    if (in[47] == '1') {
        year += 2;
    }
    if (in[48] == '1') {
        year += 1;
    }
    if (in[50] == '1') {
        day_of_week += 4;
    }
    if (in[51] == '1') {
        day_of_week += 2;
    }
    if (in[52] == '1') {
        day_of_week += 1;
    }
    t->tm_year = 100+year;
    t->tm_yday = day_of_year;
    t->tm_wday = day_of_week;
    t->tm_hour = hour;
    t->tm_min = minute;
    return 0;
}
