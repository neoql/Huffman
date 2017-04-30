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
typedef struct _Leaf **HuffmanTree;


struct _Leaf {
    int weight;
    Leaf parent;
    Leaf left;
    Leaf right;
    Key value;
};


extern HuffmanTree create_encode_tab(const uchar *p_str, int length);

#endif //HUFFMAN_HUFFMAN_H
