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

Node* searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
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

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);

    if (searchNode(head, 25) != NULL)
        printf("25 found\n");
    else
        printf("25 not found\n");

    if (searchNode(head, 17) != NULL)
        printf("17 found\n");
    else
        printf("17 not found\n");

    freeList(&head);
    return 0;
}