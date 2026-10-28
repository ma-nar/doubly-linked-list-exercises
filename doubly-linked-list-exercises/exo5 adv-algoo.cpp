#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;

Node* newNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertAtEnd(Node** head, int value) {
    Node* n = newNode(value);
    Node* temp;
    if (*head == NULL) {
        *head = n;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void traverseForward(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseBackward(Node* last) {
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    Node* last;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);

    printf("Forward: ");
    traverseForward(head);

    last = head;
    while (last != NULL && last->next != NULL)
        last = last->next;

    printf("Backward: ");
    traverseBackward(last);

    freeList(&head);
    return 0;
}