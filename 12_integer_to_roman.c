#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    int ones = num % 10;
    int tens = ((num - ones) / 10) % 10;
    int hundreds = ((num - ones - tens * 10) / 100) % 10;
    int thousands = ((num - ones - tens * 10 - hundreds * 100) / 1000) % 10;
    //printf("ones = %d, tens = %d, hundreds = %d, thousands = %d\n",ones,tens,hundreds,thousands);
    char *result = calloc(64, sizeof(char));
    memset(result, 0, sizeof(result));
    int pos = 0;

    //thousands
    while (pos < thousands) {
        result[pos++] = 'M';
    }

    //hundreds
    if (hundreds == 9) {
        result[pos++] = 'C';
        result[pos++] = 'M';
    }
    if (hundreds == 4) {
        result[pos++] = 'C';
        result[pos++] = 'D';
    }
    if (hundreds >= 5 && hundreds != 9) {
        result[pos++] = 'D';
        for (int i = 5; i < hundreds; i++) {
            result[pos++] = 'C';
        }
    }
    if (hundreds < 5 && hundreds != 4) {
        for (int i = 0; i < hundreds; i++) {
            result[pos++] = 'C';
        }
    }

    //tens
    if (tens == 9) {
        result[pos++] = 'X';
        result[pos++] = 'C';
    }
    if (tens == 4) {
        result[pos++] = 'X';
        result[pos++] = 'L';
    }
    if (tens >= 5 && tens != 9) {
        result[pos++] = 'L';
        for (int i = 5; i < tens; i++) {
            result[pos++] = 'X';
        }
    }
    if (tens < 5 && tens != 4) {
        for (int i = 0; i < tens; i++) {
            result[pos++] = 'X';
        }
    }

    //ones
    if (ones == 9) {
        result[pos++] = 'I';
        result[pos++] = 'X';
    }
    if (ones == 4) {
        result[pos++] = 'I';
        result[pos++] = 'V';
    }
    if (ones >= 5 && ones != 9) {
        result[pos++] = 'V';
        for (int i = 5; i < ones; i++) {
            result[pos++] = 'I';
        }
    }
    if (ones < 5 && ones != 4) {
        for (int i = 0; i < ones; i++) {
            result[pos++] = 'I';
        }
    }

    //printf("%s\n",result);
    return result;
}

int main() {
    char *s = intToRoman(123);
    printf("%s", s);
    free(s);
}
