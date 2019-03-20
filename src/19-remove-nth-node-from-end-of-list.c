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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *tmp = head;
    // let you go first
    while (n--) {
        tmp = tmp -> next;
    }
    if (!tmp) {
        head = head -> next;
        return head;
    }
    struct ListNode *ref = head;
    while (tmp->next) {
        ref = ref -> next;
        tmp = tmp -> next;
    }
    tmp = ref -> next -> next;
    ref -> next = tmp;
    return head;
}


int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: ./test numbers ...\n");
        exit(-1);
    }

    int i;
    struct ListNode *list, *p, *prev = NULL;
    for (i = 1; i < argc; i++) {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i]);
        p->next = NULL;
        if (i == 1) {
            list = p;
        }
        if (prev != NULL) {
            prev->next = p;
        }
        prev = p;
    }

    list = removeNthFromEnd(list, 3);
    if (list != NULL) {
        for (p = list; p != NULL; p = p->next) {
            printf("%d\n", p->val);
        }
    }

    return 0;
}
