 #include <stdio.h>
#include <stdlib.h>
#include "list.h"

void pushBack(list **head, int value) {
    if (*head == NULL) {
        list *tmp = (list*) malloc(sizeof(list));
        tmp->value = value;
        tmp->next = NULL;
        *head = tmp;
    }
    else {
        list *last = getLast(*head);
        if (last->value == value)
            return ;
        list *tmp1 = (list*) malloc(sizeof(list));
        tmp1->value = value;
        tmp1->next = NULL;
        last->next = tmp1;
    }
}

void printLinkedList(const list *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

list *getLast(list *head) {
    while(head->next != NULL)
        head = head->next;
    return head;
}