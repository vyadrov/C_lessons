typedef struct list {
    int value;
    struct list *next;
} list;

list *getLast(list *head);
void pushBack(list **head, int);
void printLinkedList(const list *head);