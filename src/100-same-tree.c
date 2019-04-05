#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Definition for a binary struct struct TreeNodeNode *node.
 * struct struct TreeNodeNode {
 *     int val;
 *     struct struct TreeNodeNode *left;
 *     struct struct TreeNodeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main(int argc, char **argv) {
    /*
    if (argc < 2 || argc % 2 == 0) {
        fprintf(stderr, "Usage: ./test start0 end0 start1 end1...");
        exit(-1);
    }
    */
    printf("I am too lazy to code the rest...\n");
    return 0;
}
