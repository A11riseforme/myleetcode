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

void insert(struct TreeNode *root, int val) {
    if (val < root->val) {
        if (root->left == NULL) {
            root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->left->val = val;
            root->left->left = NULL;
            root->left->right = NULL;
        } else {
            insert(root->left, val);
        }
    } else {
        if (root->right == NULL) {
            root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->right->val = val;
            root->right->left = NULL;
            root->right->right = NULL;
        } else {
            insert(root->right, val);
        }
    }
    return;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {
    if (root->val < val) {
        if (root->right == NULL) {
            root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->right->val = val;
            root->right->left = NULL;
            root->right->right = NULL;
        } else {
            insertIntoBST(root->right, val);
        }
    } else {
        if (root->left == NULL) {
            root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            root->left->val = val;
            root->left->left = NULL;
            root->left->right = NULL;
        } else {
            insertIntoBST(root->left, val);
        }
    }
    return root;
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