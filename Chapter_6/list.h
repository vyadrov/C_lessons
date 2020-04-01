typedef struct list {
    int value;
    struct list *next;
} lineNumber;

lineNumber *getLast(lineNumber *head);
void pushBack(lineNumber **head, int);
void printLinkedList(const lineNumber *head);