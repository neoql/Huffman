//
// Created by moons on 17-4-29.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#define Key uchar
#define TAB_MAX_SIZE 256

typedef char bool;
typedef unsigned char uchar;

typedef struct _Leaf *Leaf;
typedef struct _Leaf *Tree;


struct _Leaf {
    int weight;
    Leaf parent;
    Leaf lchild;
    Leaf rchild;
    Key value;
};


extern Tree HuffmanTree(uchar *const str, int length);

#endif //HUFFMAN_HUFFMAN_H
