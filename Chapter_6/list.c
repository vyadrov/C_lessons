#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void pushBack(lineNumber **head, int value) {
    if (*head == NULL) {
        lineNumber *tmp = (lineNumber*) malloc(sizeof(lineNumber));
        tmp->value = value;
        tmp->next = NULL;
        *head = tmp;
    }
    else {
        lineNumber *last = getLast(*head);
        if (last->value == value)
            return ;
        lineNumber *tmp1 = (lineNumber*) malloc(sizeof(lineNumber));
        tmp1->value = value;
        tmp1->next = NULL;
        last->next = tmp1;
    }
}

void printLinkedList(const lineNumber *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

lineNumber *getLast(lineNumber *head) {
    while(head->next != NULL)
        head = head->next;
    return head;
}