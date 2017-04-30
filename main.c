//
// Created by moons on 17-4-29.
//

#include <stdio.h>
#include <string.h>
#include "Huffman.h"


int main(int argc, char *argv[])
{
    Tree tree;
    char str[] = "Hello World";
    uchar *s;
    BOOL bits[] = {1,1,1,1,0,
                   1,0,1,0,1,
                   0,1,1,0,1,
                   1,1,0,0,0,
                   0,1,1,0,0,
                   1,1,1,0,0,
                   0,1};

    tree = HuffmanTree((uchar *const) str, (int) strlen(str));

    ShowCodeTab(tree);
    s = decode(bits, 37, tree);
    printf("%s\n", s);
    DeleteTree(tree);

    return 0;
}

