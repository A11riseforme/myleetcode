#include <stdio.h>
#include <stdlib.h>

int numJewelsInStones(char* J, char* S) {
    int Jfreq[128] = {0};
    int Sfreq[128] = {0};
    while (*J != '\0') {
        Jfreq[*J++]++;
    }
    while (*S != '\0') {
        Sfreq[*S++]++;
    }
    int result = 0;
    for (int i = 0; i < 128; ++i) {
        if (Jfreq[i] != 0) {
            result += Sfreq[i] / Jfreq[i];
        }
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test jewels stones\n");
        exit(-1);
    }
    printf("%d\n", numJewelsInStones(argv[1], argv[2]));
    return 0;
}
