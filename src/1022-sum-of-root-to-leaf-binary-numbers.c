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

// recursive method
int MySum(struct TreeNode* root, int sum) {
    if (!root) {
        return 0;
    }
    sum = sum*2+root->val;
    //printf("sum is %d\n", sum);
    if (!root->left && !root->right) {
        return sum;
    }
    return MySum(root->left, sum) + MySum(root->right, sum);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumRootToLeaf(struct TreeNode* root) {
    return MySum(root,0);
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    printf("I am too lazy to code the test cases\n");
    return 0;
}

