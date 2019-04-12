#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b))?(b):(a)


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void inorder(struct TreeNode *root, int* i, int* nums) {
    if (!root) {
        return;
    }
    inorder(root->left, i, nums);
    nums[(*i)++] = root->val;
    inorder(root->right, i, nums);
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
int getMinimumDifference(struct TreeNode* root) {
    int *nums = malloc(10000 * sizeof(int));
    int i = 0;
    inorder(root, &i, nums);
    int result = INT_MAX;
    for (int j = 1; j < i; ++j) {
        result = MIN(result, abs(nums[j] - nums[j - 1]));
    }
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    printf("I am too lazy to code the test case...\n");

    return 0;
}

