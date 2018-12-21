#include <stdio.h>
#include <stdlib.h>

int compareVersion(char* version1, char* version2) {
    int i = 0;
    int j = 0;
    int v1 = 0;
    int v2 = 0;
    while (*(version1 + i) != '\0' && *(version2 + j) != '\0') {
        v1 = atoi(version1 + i);
        v2 = atoi(version2 + j);
        if (v1 > v2) {
            return 1;
        }
        if (v2 > v1) {
            return -1;
        }
        for (; * (version1 + i) != '.' && *(version1 + i) != '\0'; i++) {}
        for (; * (version2 + j) != '.' && *(version2 + j) != '\0'; j++) {}
        i++;
        j++;
    }
    while (*(version1 + i) != '\0') {
        v1 = atoi(version1 + i);
        if (v1 > 0) {
            return 1;
        }
        for (; * (version1 + i) != '.' && *(version1 + i) != '\0'; i++) {}
        i++;
    }
    while (*(version2 + j) != '\0') {
        v2 = atoi(version2 + j);
        if (v2 > 0) {
            return -1;
        }
        for (; * (version2 + j) != '.' && *(version2 + j) != '\0'; j++) {}
        j++;
    }
    return 0;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test versioin1 version2\n");
        exit(-1);
    }
    printf("%d\n", compareVersioin(argv[1], argv[2]));
    return 0;
}
