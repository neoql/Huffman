//
// Created by moons on 17-4-29.
//

#ifndef HUFFMAN_SORTLIST_H
#define HUFFMAN_SORTLIST_H

#include "Huffman.h"

typedef struct _ListNode *Node;
typedef struct _ListNode *SortList;

struct _ListNode {
    Leaf leaf;
    Node next;
    int length;
};


extern SortList CreateSortList();
extern void Append2SortList(SortList list, Leaf leaf);
extern void DeleteList(SortList list);
extern Leaf PopMin(SortList list);

#endif //HUFFMAN_SORTLIST_H
