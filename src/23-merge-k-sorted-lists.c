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

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

typedef struct ListNode Node;

// sorted and created a new linked list
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int *nums = malloc(10000 * sizeof(int));
    int i = 0;
    for (int j = 0; j < listsSize; ++j) {
        Node *tmp = lists[j];
        while (tmp) {
            nums[i++] = tmp->val;
            tmp = tmp->next;
        }
    }
    qsort(nums, i, sizeof(nums[0]), cmp);
    for (int j = 0; j < i; ++j) {
        printf("%d ", nums[j]);
    }

    Node *result = (Node *)malloc(sizeof(Node));
    Node *head = result;
    for(int j = 0; j < i - 1; ++j) {
        head -> val = nums[j];
        head -> next = (Node *)malloc(sizeof(Node));
        head = head -> next;
        head -> next = NULL;
    }
    head -> val = nums[i - 1];
    return result;
}



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

//recursive method.
struct ListNode *mergeKLists_recursive(struct ListNode **lists, int listsSize) {
    if (listsSize == 0)  {
        return NULL;
    }
    if (listsSize == 1)   {
        return lists[0];
    }
    for (int i = 0, j = listsSize - 1; i < j; i++, j--) {
        lists[i] = mergeTwoLists(lists[i], lists[j]);
        listsSize--;
    }
    return mergeKLists(lists, listsSize);
}

int main() {
    int i, size;
    struct ListNode *p, *prev, *sorted, dummy1, dummy2, **lists;

    dummy1.next = NULL;
    prev = &dummy1;
    for (i = 0; i < 3; i++) {
        p = malloc(sizeof(*p));
        p->val = i * 2;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    for (p = dummy1.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    dummy2.next = NULL;
    prev = &dummy2;
    for (i = 0; i < 5; i++) {
        p = malloc(sizeof(*p));
        p->val = i * 2 + 1;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    for (p = dummy2.next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    size = 2;
    lists = malloc(size * sizeof(struct ListNode *));
    lists[0] = dummy1.next;
    lists[1] = dummy2.next;
    sorted = mergeKLists(lists, size);
    for (p = sorted; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    return 0;
}
