//
// Created by moons on 17-4-29.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#define MAX_DEEP 128

typedef unsigned char BOOL;
typedef unsigned char uchar;

typedef struct _Leaf *Leaf;
typedef struct _Leaf *Tree;


struct _Leaf {
    int weight;
    Leaf parent;
    Leaf lchild;
    Leaf rchild;
    uchar value;
};


typedef struct {
    BOOL bit[MAX_DEEP];
    int length;
} CodeEntry;


extern Tree HuffmanTree(uchar *const str, int length);
extern void DeleteTree(Tree tree);
extern void ShowCodeTab(Tree tree);
extern uchar * decode(BOOL bits[], int length, Tree tree);

#endif //HUFFMAN_HUFFMAN_H
