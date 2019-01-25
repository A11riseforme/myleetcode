#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char c;
    int freq;
} freq;

int cmp( const void *a, const void *b) {
    return (*(freq *)a).freq > (*(freq *)b).freq ? -1 : 1;
}

char* frequencySort(char* s) {
    char *result = malloc((strlen(s) + 1) * sizeof(char));
    freq *table = calloc(128, sizeof(freq));
    while (*s != '\0') {
        table[*s].c = *s;
        ++table[*s++].freq;
    }
    qsort(table, 128, sizeof(table[0]), cmp);
    int j = 0;
    for (int i = 0; i < 128; ++i) {
        //if (table[i].freq > 0) printf("%c appears %d times\n", table[i].c, table[i].freq);
        while (table[i].freq--) {
            result[j++] = table[i].c;

        }
    }
    result[j] = '\0';
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    char *result = frequencySort(argv[1]);
    printf("%s\n", result);
    free(result);
    return 0;
}
