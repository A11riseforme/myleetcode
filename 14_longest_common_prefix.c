#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, count = 0;
    char *common_prefix = calloc(999, sizeof(char));
    while (strsSize > 0) {
        char c = strs[0][count];
        for (i = 1; i < strsSize; i++) {
            if (c != strs[i][count]) {
                break;
            }
        }
        if (i == strsSize && c != '\0') {
            common_prefix[count++] = c;
        } else {
            break;
        }
    }
    return common_prefix;
}

int main(int argc, char **argv) {
    printf("%s\n", longestCommonPrefix(argv + 1, argc - 1));
    return 0;
}
