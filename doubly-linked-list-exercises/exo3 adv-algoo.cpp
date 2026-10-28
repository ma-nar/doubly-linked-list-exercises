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

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteAtBeginning(Node** head) {
    Node* temp;
    if (*head == NULL)
        return;
    temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void deleteAtEnd(Node** head) {
    Node* temp;
    if (*head == NULL)
        return;
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
}

void deleteNode(Node** head, int target) {
    Node* temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void freeList(Node** head) {
    while (*head != NULL)
        deleteAtBeginning(head);
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    displayList(head);

    deleteAtBeginning(&head);
    displayList(head);

    deleteAtEnd(&head);
    displayList(head);

    deleteNode(&head, 20);
    displayList(head);

    freeList(&head);
    return 0;
}