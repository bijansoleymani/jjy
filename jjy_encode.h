#include <time.h>
#include <assert.h>

int jjy_encode(struct tm *t, char out[60]);
int jjy_encode_now(char out[60]);
int jjy_bit_to_pcm(char bit, unsigned short pcm[192000]);
int jjy_encode_to_pcm(char out[60], unsigned short* pcm);