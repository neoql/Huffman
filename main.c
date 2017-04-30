//
// Created by moons on 17-4-29.
//

#include <stdio.h>
#include "Huffman.h"


int main(int argc, char *argv[])
{
    HuffmanTree tab;
    uchar array[5] = {5, 5, 5, 2, 1};
    int i;

    tab = create_encode_tab(array, 5);

    return 0;
}

