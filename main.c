#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
    t = *localtime(&lt);
    printf("Year: %d\n", t.tm_year + 1900);
    printf("Day of year: %d\n", t.tm_yday);
    printf("Day of week: %d\n", t.tm_wday);
    printf("Hour: %d\n", t.tm_hour);
    printf("Minute: %d\n", t.tm_min);
}

// _CRTIMP void __cdecl _assert(const char* expression, const char* file, unsigned line)
// {
//     printf("Assertion failed: %s, file %s, line %d\n", expression, file, line);
//     exit(1);
// }