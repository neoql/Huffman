//
// Created by moons on 17-4-29.
//

#include "Huffman.h"
#include <stdlib.h>
#include "sortlist.h"


static Leaf MergeNode(Leaf left, Leaf right)
{
    Leaf node;

    node = malloc(sizeof(struct _Leaf));
    node->parent = NULL;
    node->left = left;
    node->right = right;
    node->weight = left->weight + right->weight;

    left->parent = node;

    right->parent = node;

    return node;
}


HuffmanTree create_encode_tab(const uchar *p_str, int length)
{
    int i;
    HuffmanTree tree;
    SortList list;
    Leaf left, right, node;
    int key;

    tree = malloc(sizeof(Leaf) * TAB_MAX_SIZE);
    for (i = 0; i < TAB_MAX_SIZE; i++) {
        tree[i] = malloc(sizeof(struct _Leaf));
        tree[i]->parent = NULL;
        tree[i]->left = NULL;
        tree[i]->right = NULL;
        tree[i]->value = (uchar) i;
        tree[i]->weight = 0;
    }

    for (i = 0; i < length; i++) {
        key = p_str[i];
        tree[key]->weight++;
    }

    list = CreateSortList();
    for (i = 0; i < TAB_MAX_SIZE; i++) {
        if (tree[i]->weight != 0) {
            Append2SortList(list, tree[i]);
        }
    }

    while (list->length > 1) {
        left = PopMin(list);
        right = PopMin(list);
        node = MergeNode(left, right);
        Append2SortList(list, node);
    }

    return tree;
}
