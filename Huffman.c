//
// Created by moons on 17-4-29.
//

#include "Huffman.h"
#include <stdlib.h>
#include <stdio.h>
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
    int *weights, weight;
    Tree tree;
    Leaf leaf, left, right;
    SortList list;
    int i, k;

    weights = calloc(MAX_LEN, sizeof(int));
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


void DeleteTree(Tree tree)
{
    Leaf leaf;
    leaf = tree;


    if (leaf->lchild) {
        DeleteTree(leaf->lchild);
    }

    if (leaf->rchild) {
        DeleteTree(leaf->rchild);
    }

    if (leaf->lchild == NULL && leaf->rchild == NULL) {
        free(leaf);
    }
}


static void ShowEntry(Leaf leaf, CodeEntry *entry)
{
    int i;


    if (leaf->lchild) {
        entry->bit[entry->length++] = 0;
        ShowEntry(leaf->lchild, entry);
    }

    if (leaf->rchild) {
        entry->bit[entry->length++] = 1;
        ShowEntry(leaf->rchild, entry);
    }

    if (leaf->lchild == NULL && leaf->rchild == NULL) {
        printf("%c : ", leaf->value);
        for (i = 0; i < entry->length; i++) {
            printf("%d", entry->bit[i]);
        }

        printf("\n");
    }

    entry->length--;
}


void ShowCodeTab(Tree tree)
{
    CodeEntry *entry;

    entry = malloc(sizeof(CodeEntry));
    entry->length = 0;
    ShowEntry(tree, entry);
    free(entry);
}


uchar * decode(BOOL bits[], int length, Tree tree)
{
    uchar *s, *p;
    int i;
    Leaf leaf;

    leaf = tree;

    s = calloc(20, sizeof(uchar));
    p = s;
    for (i = 0; i < length; i++) {
        if (bits[i] == 0) {
            leaf = leaf->lchild;
        } else if (bits[i] == 1) {
            leaf = leaf->rchild;
        }

        if (leaf->lchild == NULL && leaf->rchild == NULL) {
            *p++ = leaf->value;
            leaf = tree;
        }
    }

    return s;
}
