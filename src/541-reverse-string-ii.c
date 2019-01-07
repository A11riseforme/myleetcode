#include <stdio.h>
#include <stdlib.h>

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    char *result = malloc((len + 1) * sizeof(char));
    memcpy(result, s, len + 1);
    int blkNum = len / (2 * k);
    int remainder = len % (2 * k);
    int l;
    int r;
    for (int i = 0; i < blkNum; i++) {
        l = i * 2 * k;
        r = l + k - 1;
        while (r > l) {
            char tmp = result[l];
            result[l++] = result[r];
            result[r--] = tmp;
        }
    }
    l = blkNum * 2 * k;
    r = remainder < k ? len - 1 : l + k - 1;
    while (r > l) {
        char tmp = result[l];
        result[l++] = result[r];
        result[r--] = tmp;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string number\n");
        exit(-1);
    }
    int *result = reverseStr(argv[1], atoi(argv[2]));
    printf("%s", result);
    free(result);
    return 0;
}
