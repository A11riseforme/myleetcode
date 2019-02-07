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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    // l1 head value >= l2 head value
    if (l1 -> val >= l2 -> val) {
        l2 -> next = mergeTwoLists(l1, l2 -> next);
        return l2;
    }
    l1 -> next = mergeTwoLists(l2, l1 -> next);
    return l1;
}

// iterative way.
struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1 -> val <= l2 -> val) {
            tail -> next = l1;
            l1 = l1 -> next;
        } else {
            tail -> next = l2;
            l2 = l2 -> next;
        }
        tail = tail -> next;
    }
    if (l1) {
        tail -> next = l1;
    } else {
        tail -> next = l2;
    }
    return dummy.next;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number \n");
        exit(-1);
    }
    */
    struct ListNode l1;
    l1.val = 2;
    l1.next = NULL;
    struct ListNode l2;
    l2.val = 1;
    l2.next = NULL;
    struct ListNode * list = mergeTwoLists(&l1, &l2);
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
    return 0;
}
