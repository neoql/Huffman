//
// Created by moons on 17-4-29.
//

#include "Huffman.h"
#include <stdlib.h>
#include "sortlist.h"


#define MAX_LEN 256


static Leaf MergeNode(Leaf left, Leaf right)
{
    Leaf node;

    node = malloc(sizeof(struct _Leaf));
    node->parent = NULL;
    node->lchild = left;
    node->rchild = right;
    node->weight = left->weight + right->weight;

    left->parent = node;

    right->parent = node;

    return node;
}


Tree HuffmanTree(uchar *const str, int length)
{
    int weights[MAX_LEN], weight;
    Tree tree;
    Leaf leaf, left, right;
    SortList list;
    int i, k;

    for (i = 0; i < length; i++) {
        k = str[i];
        weight = weights[k];
        weights[k] = weight + 1;
    }

    list = CreateSortList();
    for (i = 0; i < MAX_LEN; i++) {
        if (weights[i]) {
            leaf = malloc(sizeof(struct _Leaf));
            leaf->parent = NULL;
            leaf->lchild = NULL;
            leaf->rchild = NULL;
            leaf->weight = weights[i];
            leaf->value = (uchar) i;
            Append2SortList(list, leaf);
        }
    }

    while (list->length > 1) {
        left = PopMin(list);
        right = PopMin(list);
        leaf = MergeNode(left, right);
        Append2SortList(list, leaf);
    }
    tree = PopMin(list);
    DeleteList(list);

    return tree;
}
