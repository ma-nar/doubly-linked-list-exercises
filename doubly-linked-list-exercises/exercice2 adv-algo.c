
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

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtBeginning(Node** head, int value) {
    Node* n = newNode(value);
    n->next = *head;
    if (*head != NULL)
        (*head)->prev = n;
    *head = n;
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

void insertAfter(Node* head, int value, int target) {
    Node* temp = head;
    Node* n;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
        return;
    n = newNode(value);
    n->prev = temp;
    n->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = n;
    temp->next = n;
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

    insertAtBeginning(&head, 15);
    displayList(head);
    insertAtBeginning(&head, 10);
    displayList(head);

    insertAtEnd(&head, 20);
    displayList(head);
    insertAtEnd(&head, 25);
    displayList(head);
    insertAtEnd(&head, 30);
    displayList(head);

    insertAfter(head, 17, 15);
    displayList(head);

    freeList(&head);
    return 0;
}