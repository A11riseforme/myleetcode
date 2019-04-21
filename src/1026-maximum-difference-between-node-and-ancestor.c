#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void solve(struct TreeNode* root, int* ancestors, int* result) {
    // update the result
    *result = MAX(MAX(abs(ancestors[0] - root->val), abs(ancestors[1] - root->val)), *result);
    int ancestors0 = ancestors[0];
    int ancestors1 = ancestors[1];
    ancestors[0] = MAX(ancestors[0], root->val);
    ancestors[1] = MIN(ancestors[1], root->val);
    if (root->left) {
        solve(root->left, ancestors, result);
    }
    // recover the ancestors data.
    ancestors[0] = MAX(ancestors0, root->val);
    ancestors[1] = MIN(ancestors1, root->val);
    if (root->right) {
        solve(root->right, ancestors, result);
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
int maxAncestorDiff(struct TreeNode* root) {
    // record down the largest and smallest ancestor so far.
    int ancestors[2] = {root->val, root->val};
    int result = 0;
    solve(root, ancestors, &result);
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    printf("I am too lazy to code the testcases...\n");
    return 0;
}

