//
// Created by moons on 17-4-29.
//

#include <stdio.h>
#include "bitarray.h"


int main(int argc, char *argv[])
{
    bitarray str;

    str = BitArray();

    AppendBin(str, 1);
    AppendBin(str, 1);
    AppendBin(str, 0);
    AppendBin(str, 1);

    printf("%d\n", str->bytes[0]);
    DeleteBitArray(str);

    return 0;
}

