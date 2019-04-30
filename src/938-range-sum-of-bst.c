#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode *root, int L, int R) {
    if (!root) {
        return 0;
    }
    if (root->val < L) {
        return rangeSumBST(root->right, L, R);
    }
    if (root->val > R) {
        return rangeSumBST(root->left, L, R);
    }
    return root->val + rangeSumBST(root->left, L, R) +
           rangeSumBST(root->right, L, R);
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    printf("I am too lazy to code the testcases...\n");
    return 0;
}