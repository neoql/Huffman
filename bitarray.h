//
// Created by moons on 17-4-29.
//

#ifndef HUFFMAN_BITARRAY_H
#define HUFFMAN_BITARRAY_H


typedef unsigned char uchar;
typedef unsigned char bool;

typedef struct _bitarray *bitarray;


struct _bitarray {
    uchar *bytes;
    int length;
    int real_size;
};

extern bitarray BitArray();
extern void AppendBin(bitarray str, bool bit);
extern bool GetBin(bitarray str, int index);
extern void DeleteBitArray(bitarray str);

#endif //HUFFMAN_BITARRAY_H
