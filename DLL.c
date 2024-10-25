#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list backward
void traverseBackward(struct Node *node) {
    if (node == NULL) return;
    while (node->next != NULL) {
        node = node->next;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

// Insert at the beginning of the list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

// Insert at the end of the list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    
    if (*headRef == NULL) {  // If list is empty
        newNode->prev = NULL;
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

// Delete the first node of the list
void deleteAtFirst(struct Node** headRef) {
    if (*headRef == NULL) return; // Empty list

    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;

    if (*headRef != NULL) {
        (*headRef)->prev = NULL;
    }
    free(temp);
}

// Delete the last node of the list
void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL) return; // Empty list

    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *headRef = NULL;  // List only had one node
    }

    free(temp);
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 15);

    printf("Original list:\n");
    traverseForward(head);

    printf("Traverse backward:\n");
    traverseBackward(head);

    deleteAtFirst(&head);
    printf("After deleting the first element:\n");
    traverseForward(head);

    deleteAtEnd(&head);
    printf("After deleting the last element:\n");
    traverseForward(head);

    return 0;
}
