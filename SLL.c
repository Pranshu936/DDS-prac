#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Traverse and print values
void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion at the first position
struct node* insertAtFirst(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Insertion at a given index
struct node* insertAtIndex(struct node* head, int data, int index) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;

    if (index == 0) {
        return insertAtFirst(head, data);
    }

    while (i < index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Index out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

// Insertion at the end
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return head;
}

// Insertion after a given node
struct node* insertAfterNode(struct node* head, struct node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The previous node cannot be NULL.\n");
        return head;
    }
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}

// Deleting the first element from the linked list
struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Deleting the element at a given index
struct node* deleteAtIndex(struct node* head, int index) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    
    struct node* p = head;
    if (index == 0) {
        return deleteFirst(head);
    }

    struct node* q = NULL;
    for (int i = 0; i < index && p != NULL; i++) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }

    q->next = p->next;
    free(p);
    return head;
}

// Deleting the last element
struct node* deleteAtLast(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* p = head;
    struct node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

// Deleting the element with a given value from the linked list
struct node* deleteByValue(struct node* head, int value) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct node* p = head;
    struct node* q = head->next;

    if (p->data == value) {
        return deleteFirst(head);
    }

    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }

    if (q != NULL) {
        p->next = q->next;
        free(q);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
    return head;
}

// Searching for a node with a specific key
struct node* searchNode(struct node* head, int key) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key) {
            return ptr; // Node found
        }
        ptr = ptr->next;
    }
    return NULL; // Node not found
}

// Reversing the linked list
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    return prev; // New head of the reversed list
}

int main() {
    struct node* head = NULL;

    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 11);
    head = insertAtEnd(head, 66);
    head = insertAtEnd(head, 56);

    printf("Linked List after insertion:\n");
    linkedListTraversal(head);

    int key = 11;
    struct node* result = searchNode(head, key);
    if (result != NULL) {
        printf("Node with data %d found.\n", key);
    } else {
        printf("Node with data %d not found.\n", key);
    }

    head = deleteByValue(head, 11);
    printf("Linked List after deleting value 11:\n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 66);
    printf("Linked List after inserting 66 at the beginning:\n");
    linkedListTraversal(head);

    head = deleteAtIndex(head, 2);
    printf("Linked List after deleting node at index 2:\n");
    linkedListTraversal(head);

    head = deleteAtLast(head);
    printf("Linked List after deleting the last node:\n");
    linkedListTraversal(head);

    head = reverseList(head);
    printf("Linked List after reversing:\n");
    linkedListTraversal(head);

    return 0;
}
