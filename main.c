#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
#include <sys/time.h>
#include <unistd.h>
#include "jjy_encode.h"
#include "jjy_decode.h"

int main()
{
    // Compare this snippet from jjy_encode.c:
    // jjy_encode();
    // Compare this snippet from jjy_decode.c:
    // jjy_decode();
    char out[60];
    struct tm t;
    // jjy_encode_now(out);
    // jjy_decode(out, &t);
    time_t lt = time(NULL);

    printf("lt: %ld\n", lt % 60);
    lt += 60-lt%60;
    lt += 60;
    int start_time = lt;
    printf("lt: %ld\n", lt);
    t = *localtime(&lt);
    printf("Year: %d\n", t.tm_year + 1900);
    printf("Day of year: %d\n", t.tm_yday);
    printf("Day of week: %d\n", t.tm_wday);
    printf("Hour: %d\n", t.tm_hour);
    printf("Minute: %d\n", t.tm_min);
    printf("Second:  %d\n", t.tm_sec);
    unsigned short* pcm = malloc(11520000*20*sizeof(unsigned short));
    //jjy_encode(&t, out);
    //jjy_encode_to_pcm(out, pcm);
    FILE* out_file;
    out_file = fopen("jjy.wav", "wb");
    fprintf(out_file, "%s", "RIFF");
    int chunksize = 11520000*20+36;
    fwrite(&chunksize, sizeof(int), 1, out_file);
    fprintf(out_file, "%s", "WAVE");
    fprintf(out_file, "%s", "fmt ");
    int subchunk1size = 16;
    short audioformat = 1;
    short numchannels = 1;
    int samplerate = 192000;
    int byterate = 192000*1*16/8;
    short blockalign = 1*16/8;
    short bitspersample = 16;
    fwrite(&subchunk1size, sizeof(int), 1, out_file);
    fwrite(&audioformat, sizeof(short), 1, out_file);
    fwrite(&numchannels, sizeof(short), 1, out_file);
    fwrite(&samplerate, sizeof(int), 1, out_file);
    fwrite(&byterate, sizeof(int), 1, out_file);
    fwrite(&blockalign, sizeof(short), 1, out_file);
    fwrite(&bitspersample, sizeof(short), 1, out_file);
    fprintf(out_file, "%s", "data");
    int subchunk2size = 11520000*2*20;
    fwrite(&subchunk2size, sizeof(int), 1, out_file);

    for (int j = 0; j < 20; j++)
    {
        printf("%d\n", j);
        if (j == 0)
        {
            printf("Hour: %d\n", t.tm_hour);
            printf("Minute: %d\n", t.tm_min);
            printf("Second:  %d\n", t.tm_sec);
        }
        t = *localtime(&lt);
        bzero(out, 60);
        jjy_encode(&t, out);
        jjy_encode_to_pcm(out, pcm + j * 11520000);
        lt += 60;
    }
    for (int i = 0; i < 11520000*20; i++)
    {
        fwrite(pcm + i, sizeof(unsigned short), 1, out_file);   
    }
    fclose(out_file);
    struct timeval tv;
    struct timespec ts;
    gettimeofday(&tv, NULL);
    if(tv.tv_sec < start_time)
    {
        ts.tv_sec = start_time - tv.tv_sec;
        ts.tv_nsec = 0;
        printf("%ld %ld\n", ts.tv_sec, ts.tv_nsec);
        nanosleep(&ts, NULL);
    }
    gettimeofday(&tv, NULL);
    printf("%ld %d\n", tv.tv_sec, start_time);
    execlp("mpv", "mpv", "jjy.wav", NULL);
    

    // t.tm_hour = 19;
    // t.tm_min = 13;
    // bzero(out, 60);
    // jjy_encode(&t, out);

    // for (int i = 0; i < 60; i++)
    // {
    //    if ( i %10 == 0)
    //     {
    //         printf("\n");
    //     }
    //     printf("%c\n", out[i]);
    // }
    
}

// _CRTIMP void __cdecl _assert(const char* expression, const char* file, unsigned line)
// {
//     printf("Assertion failed: %s, file %s, line %d\n", expression, file, line);
//     exit(1);
// }