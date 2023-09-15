#include "jjy_encode.h"
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define FREQ 20000
#define RATE 192000

int jjy_encode(struct tm *t, char out[60])
{
    for (int i = 0; i < 60; i++)
    {
        out[i] = 0;
    }

    out[0]  = 'm';
    out[9]  = 'm';
    out[19] = 'm';
    out[29] = 'm';
    out[39] = 'm';
    out[49] = 'm';
    out[59] = 'm';

    out[4]  = '0';
    out[10] = '0';
    out[11] = '0';
    out[14] = '0';
    out[20] = '0';
    out[21] = '0';
    out[24] = '0';
    out[34] = '0';
    out[35] = '0';
    out[38] = '0';
    
    out[40] = '0';

    out[53] = '0';
    out[54] = '0';
    out[55] = '0';
    out[56] = '0';
    out[57] = '0';
    out[58] = '0';

    int min = t->tm_min;
    if (min >= 40) {
        out[1] = '1';
        min -= 40;
    } else {
        out[1] = '0';
    }
    if (min >= 20) {
        out[2] = '1';
        min -= 20;
    } else {
        out[2] = '0';
    }
    if (min >= 10) {
        out[3] = '1';
        min -= 10;
    } else {
        out[3] = '0';
    }
    if (min >= 8) {
        out[5] = '1';
        min -= 8;
    } else {
        out[5] = '0';
    }
    if (min >= 4) {
        out[6] = '1';
        min -= 4;
    } else {
        out[6] = '0';
    }
    if (min >= 2) {
        out[7] = '1';
        min -= 2;
    } else {
        out[7] = '0';
    }
    if (min >= 1) {
        out[8] = '1';
        min -= 1;
    } else {
        out[8] = '0';
    }
    //printf("%d\n", min);
    assert(min == 0);

    int hours = t->tm_hour;
    if (hours >= 20) {
        out[12] = '1';
        hours -= 20;
    } else {
        out[12] = '0';
    }
    if (hours >= 10) {
        out[13] = '1';
        hours -= 10;
    } else {
        out[13] = '0';
    }
    if (hours >= 8) {
        out[15] = '1';
        hours -= 8;
    } else {
        out[15] = '0';
    }
    if (hours >= 4) {
        out[16] = '1';
        hours -= 4;
    } else {
        out[16] = '0';
    }
    if (hours >= 2) {
        out[17] = '1';
        hours -= 2;
    } else {
        out[17] = '0';
    }
    if (hours >= 1) {
        out[18] = '1';
        hours -= 1;
    } else {
        out[18] = '0';
    }
    assert(hours == 0);

    int day = t->tm_yday + 1;
    if (day >= 200) {
        out[22] = '1';
        day -= 200;
    } else {
        out[22] = '0';
    }
    if (day >= 100) {
        out[23] = '1';
        day -= 100;
    } else {
        out[23] = '0';
    }
    if (day >= 80) {
        out[25] = '1';
        day -= 80;
    } else {
        out[25] = '0';
    }
    if (day >= 40) {
        out[26] = '1';
        day -= 40;
    } else {
        out[26] = '0';
    }
    if (day >= 20) {
        out[27] = '1';
        day -= 20;
    } else {
        out[27] = '0';
    }
    if (day >= 10) {
        out[28] = '1';
        day -= 10;
    } else {
        out[28] = '0';
    }
    if (day >= 8) {
        out[30] = '1';
        day -= 8;
    } else {
        out[30] = '0';
    }
    if (day >= 4) {
        out[31] = '1';
        day -= 4;
    } else {
        out[31] = '0';
    }
    if (day >= 2) {
        out[32] = '1';
        day -= 2;
    } else {
        out[32] = '0';
    }
    if (day >= 1) {
        out[33] = '1';
        day -= 1;
    } else {
        out[33] = '0';
    }
    assert(day == 0);

    int hour_parity = 0;
    for (int i = 12; i < 19; i++) {
        if (out[i] == '1') {
            hour_parity++;
        }
    }
    hour_parity %= 2;

    int minute_parity = 0;
    for (int i = 1; i < 9; i++) {
        if (out[i] == '1') {
            minute_parity++;
        }
    }
    minute_parity %= 2;

    if (hour_parity == 0) {
        out[36] = '0';
    } else {
        out[36] = '1';
    }
    if (minute_parity == 0) {
        out[37] = '0';
    } else {
        out[37] = '1';
    }

    int year = t->tm_year % 100;
    if (year >= 80) {
        out[41] = '1';
        year -= 80;
    } else {
        out[41] = '0';
    }
    if (year >= 40) {
        out[42] = '1';
        year -= 40;
    } else {
        out[42] = '0';
    }
    if (year >= 20) {
        out[43] = '1';
        year -= 20;
    } else {
        out[43] = '0';
    }
    if (year >= 10) {
        out[44] = '1';
        year -= 10;
    } else {
        out[44] = '0';
    }
    if (year >= 8) {
        out[45] = '1';
        year -= 8;
    } else {
        out[45] = '0';
    }
    if (year >= 4) {
        out[46] = '1';
        year -= 4;
    } else {
        out[46] = '0';
    }
    if (year >= 2) {
        out[47] = '1';
        year -= 2;
    } else {
        out[47] = '0';
    }
    if (year >= 1) {
        out[48] = '1';
        year -= 1;
    } else {
        out[48] = '0';
    }
    assert(year == 0);

    int weekday = t->tm_wday;
    if (weekday >= 4) {
        out[50] = '1';
        weekday -= 4;
    } else {
        out[50] = '0';
    }
    if (weekday >= 2) {
        out[51] = '1';
        weekday -= 2;
    } else {
        out[51] = '0';
    }
    if (weekday >= 1) {
        out[52] = '1';
        weekday -= 1;
    } else {
        out[52] = '0';
    }
    assert(weekday == 0);
    return 0;
}

int jjy_encode_now(char out[60])
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    jjy_encode(&tm, out);
    return 0;
}

int jjy_bit_to_pcm(char bit, unsigned short pcm[RATE])
{
    for (int i = 0; i < RATE; i++)
    {
        pcm[i] = 0.2 * (cos(2 * M_PI * i / RATE * FREQ) + 0) * 32768;
    }
    if (bit == '0')
    {
        for (int i = RATE * 0.8; i < RATE; i++)
        {
            pcm[i] = 0.01 * (cos(M_PI * i / RATE * FREQ) + 0) * 32768;
        }
    }
    else if (bit == '1')
    {
        for (int i = RATE * 0.5; i < RATE; i++)
        {
            pcm[i] = 0.01 * (cos(M_PI * i / RATE * FREQ) + 0) * 32768;
        }
    }
    else if (bit == 'm')
    {
        for (int i = RATE * 0.2; i < RATE; i++)
        {
            pcm[i] = 0.01 * (cos(M_PI * i / RATE * FREQ) + 0) * 32768;
        }
    }

    return 0;
}
int jjy_encode_to_pcm(char out[60], unsigned short* pcm)
{
    for (int i = 0; i < 60; i++)
    {
        jjy_bit_to_pcm(out[i], pcm + i * RATE);
    }

    return 0;
}