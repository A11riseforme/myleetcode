#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p1, *p2, *p3;
    if (!head) return head;
    if (!head->next) return head;
    // node1 -> node2 -> node3 -> node4 -> node5
    p1 = head;
    p2 = head->next;
    p3 = p2->next;      // p1 -> p2 -> p3 -> node4 -> node5;
    p2->next = p1;      // p1 <- p2    p3 -> node4 -> node5;
    p1->next = swapPairs(p3);   //swapPairs(p3) <- p1 <- p2
    return p2;
}


int main(int argc, char **argv) {
    int i, count = argc - 1;
    struct ListNode *head = NULL, *p, *prev;
    for (i = 0; i < count; i++) {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            prev->next = p;
        }
        prev = p;
    }

    for (p = swapPairs(head); p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
    return 0;
}
