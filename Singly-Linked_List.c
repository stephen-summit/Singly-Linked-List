#include <stdio.h>
#include <stdlib.h>  // Added for memory allocation functions
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node.
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle in a linked list.
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *tortoise = head;
    struct ListNode *hare = head;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle detected
}

int main() {
    // Input from the user to create a linked list with or without a cycle
    int n, val, i;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    struct ListNode *head = NULL, *tail = NULL;
    struct ListNode *prev = NULL;

    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &val);

        struct ListNode *newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    // Check if there is a cycle in the linked list
    bool hasCycleResult = hasCycle(head);

    if (hasCycleResult) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    return 0;
}

