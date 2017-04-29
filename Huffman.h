//
// Created by moons on 17-4-29.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#define KeyType uchar

typedef char bool;
typedef unsigned char uchar;

typedef struct _TreeNode *TreeNode;


struct _TreeNode {
    bool real;
    int weight;
    TreeNode parent;
    TreeNode left;
    TreeNode right;
    KeyType value;
};

#endif //HUFFMAN_HUFFMAN_H
