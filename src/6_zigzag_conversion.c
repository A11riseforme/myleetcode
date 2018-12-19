#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int totalLength = strlen(s);
    int numCols = totalLength/2+1;
    char pattern[numRows][numCols];
    memset(pattern, 0x20, sizeof(pattern));
    pattern[0][0] = *s;
    char direction = 'd';
    int last[2] = {0,0};
    for (int i = 1; i < totalLength; i++) {
        if (direction == 'd') {
            if (last[0] == numRows-1) {
                direction = 'u';
                pattern[--last[0]][++last[1]] = *(s+i);
            } else {
                pattern[++last[0]][last[1]] = *(s+i);
            }
        } else {
            if (last[0] == 0) {
                direction = 'd';
                pattern[++last[0]][last[1]] = *(s+i);
            } else {
                pattern[--last[0]][++last[1]] = *(s+i);
            }
        }
    }
    char *result = calloc(totalLength+1, sizeof(char));
    int i = 0;
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            if (pattern[r][c] != ' ') {
                *(result + i++) = pattern[r][c];
            }
        }
    }
    *(result + totalLength) = '\0';
    return result;
}

int main() {
    char *s = "PAYPALISHIRING";
    char *a = convert(s,3);
    printf("%s",a);
    free(a);
}
