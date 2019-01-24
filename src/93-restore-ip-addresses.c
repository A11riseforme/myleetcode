#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myAtoi(char* s, int start, int end) {
    int result = 0;
    if (start > end) {
        return 256;
    }
    if (end - start >= 3) {
        return 256;
    }
    for (int i = start; i <= end; ++i) {
        result = result*10+s[i]-'0';
    }
    return result;
}


void helper(char* s, char** result, int* returnSize, int* ips, int index, int pos, int len) {
    if (index == 3) {
        if (myAtoi(s, pos, len-1) <= 255) {
            ips[index] = myAtoi(s, pos, len-1);
            int ipLens[4];
            int ipsCopy[4];
            memcpy(ipsCopy, ips, 4*sizeof(int));
            ipLens[0] = ips[0] > 99 ? 3 : (ips[0] > 9 ? 2 : 1);
            ipLens[1] = ips[1] > 99 ? 3 : (ips[1] > 9 ? 2 : 1);
            ipLens[2] = ips[2] > 99 ? 3 : (ips[2] > 9 ? 2 : 1);
            ipLens[3] = ips[3] > 99 ? 3 : (ips[3] > 9 ? 2 : 1);

            int resultLen = ipLens[0]+ipLens[1]+ipLens[2]+ipLens[3] + 3;
            if (resultLen != len+3) {
                return;
            }
            result[*returnSize] = malloc((resultLen+1)*sizeof(char));
            result[*returnSize][resultLen] = '\0';
            int i, j = resultLen-1;
            for (i = 3; i >= 0; --i) {
                if (ipsCopy[i] == 0) {
                    result[*returnSize][j--] = '0';
                } else {
                    while (ipsCopy[i] > 0) {
                        result[*returnSize][j--] = ipsCopy[i] % 10 + '0';
                        ipsCopy[i] /= 10;
                    }
                }
                if (i > 0) {
                    result[*returnSize][j--] = '.';
                }
            }
            ++(*returnSize);
            return;

        }
        return;
    }

    if (pos >= len || index > 3) {
        return;
    }

    for (int i = pos; i < len; ++i) {
        if (myAtoi(s, pos, i) <= 255) {
            ips[index] = myAtoi(s, pos, i);
            helper(s, result, returnSize, ips, index+1, i+1, len);
        }
    }
    return;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    int len = strlen(s);
    if (len > 12 || len < 4) {
        *returnSize = 0;
        return NULL;
    }
    int *ips = malloc(4*sizeof(int));
    char **result = malloc(500*sizeof(char*));
    helper(s, result, returnSize, ips, 0, 0, len);
    free(ips);
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    int returnSize = 0;
    char **result = restoreIpAddresses(argv[1], &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        //free(result[i]);
    }
    free(result);

}
