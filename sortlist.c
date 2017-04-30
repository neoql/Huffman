//
// Created by moons on 17-4-29.
//

#include "sortlist.h"
#include <stdlib.h>


SortList CreateSortList()
{
    SortList list;

    list = malloc(sizeof(struct _ListNode));
    list->leaf = NULL;
    list->next = NULL;
    list->length = 0;

    return list;
}


void Append2SortList(SortList list, Ele leaf)
{
    Node *node, last, temp;

    node = &list->next;
    last = list;

    while (1) {
        if (*node == NULL) {
            *node = malloc(sizeof(struct _ListNode));
            (*node)->next = NULL;
            (*node)->leaf = leaf;
            break;
        }

        if ((*node)->leaf->weight > leaf->weight) {
            temp = *node;
            last->next = malloc(sizeof(struct _ListNode));
            last->next->next = temp;
            last->next->leaf = leaf;
            break;
        }

        last = *node;
        node = &(*node)->next;
    }
    list->length++;
}


void DeleteList(SortList list)
{
    Node node, last;

    node = list->next;
    while (node != NULL) {
        last = node;
        node = node->next;
        free(last);
    }
    free(list);
}


Ele PopMin(SortList list)
{
    Ele ele;
    Node node;

    node = list->next;
    list->next = node->next;
    ele = node->leaf;
    free(node);
    list->length--;

    return ele;
}
