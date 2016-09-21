#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void memcpy2(void * dest,void* src, int len)
{
    char* cdest = (char *)dest;
    char* csrc = (char *)src;

    for(int i = 0;i<len;i++)
    {
        cdest[i] = csrc[i];
    }
}

void memmove2(void* dest, void* src, int len)
{
    char* cdest = (char *)dest;
    char* csrc = (char *)src;
    char* temp = (char*) malloc( sizeof(char) *  len);

    for (int i = 0; i < len; ++i)
    {
        temp[i] = csrc[i];
    }

    for (int i = 0; i < len; ++i)
    {
        cdest[i] = temp[i];
    }
}
int main (void)
{
    char string [] = "stackoverflow";
    char *first, *second;
    first = string;
    second = string;

    puts(string);
    memcpy2(first, first+1, 6);
    puts(first);
    memmove2(second+1, second, 6);
    puts(second);
    return 0;
}