//
// Created by moons on 17-4-29.
//

#include "bitarray.h"
#include <stdlib.h>


bitarray BitArray()
{
    bitarray str;

    str = malloc(sizeof(struct _bitarray));
    str->real_size = 16;
    str->bytes = calloc((size_t) str->real_size, sizeof(uchar));
    str->length = 0;

    return str;
}


void DeleteBitArray(bitarray str)
{
    free(str->bytes);
    free(str);
}


void AppendBin(bitarray str, bool bit)
{
    uchar *p;
    int index, offset;

    p = str->bytes;
    index = str->length / 8;
    offset = 7 - str->length % 8;

    p += index;
    *p |= (bit << offset);
    str->length++;
}
