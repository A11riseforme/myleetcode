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
// recursion might not be the most efficient, but easiest.
bool isUnivalTree(struct TreeNode *root) {
    if (!root->left && !root->right) {
        return true;
    }
    if (root->left && root->right) {
        return (root->val == root->left->val) &&
               (root->left->val == root->right->val) &&
               (isUnivalTree(root->left)) && (isUnivalTree(root->right));
    } else if (root->left) {
        return (root->val == root->left->val) && isUnivalTree(root->left);
    } else {
        return (root->val == root->right->val) && isUnivalTree(root->right);
    }
    return true;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    printf("I am too lazy to code the testcases\n");
    return 0;
}