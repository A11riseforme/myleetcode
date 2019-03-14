#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define NEWNODE (Node *)malloc(sizeof(Node))

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

Node* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Node *result = NEWNODE;
    Node *curr = result;
    int sum = 0;
    int carry = 0;
    while (l1 && l2) {
        sum = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        curr -> val = sum;
        l1 = l1->next;
        l2 = l2->next;
        if (!(l1 && l2)) {
            break;
        }
        curr -> next = NEWNODE;
        curr = curr->next;
        curr -> next = NULL;
    }
    while (l1) {
        curr -> next = NEWNODE;
        curr = curr -> next;
        sum = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        curr -> val = sum;
        if (!l1) {
            break;
        }
        l1 = l1->next;
    }
    while (l2) {
        curr -> next = NEWNODE;
        curr = curr -> next;
        sum = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        curr -> val = sum;
        if (!l2) {
            break;
        }
        l2 = l2->next;
    }
    if (carry) {
        curr -> next = NEWNODE;
        curr = curr -> next;
        curr -> val = carry;
    }
    curr -> next = NULL;
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    // l1 = 5 <- 1 <- 3
    Node *l1 = NEWNODE;
    Node *tmp = l1;
    tmp->val = 5;
    tmp->next = NEWNODE;
    tmp = tmp->next;
    tmp->val = 1;
    tmp->next = NEWNODE;
    tmp = tmp->next;
    tmp->val = 3;
    tmp->next = NULL;
    // l2 = 5 <- 1
    Node *l2 = NEWNODE;
    tmp = l2;
    tmp->val = 5;
    tmp->next = NEWNODE;
    tmp = tmp->next;
    tmp->val = 1;
    tmp->next = NULL;
    struct ListNode * list = addTwoNumbers(l1, l2);
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
}
