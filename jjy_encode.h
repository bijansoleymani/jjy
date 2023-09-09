#include <time.h>
#include <assert.h>

int jjy_encode(struct tm *t, char out[60]);
int jjy_encode_now(char out[60]);