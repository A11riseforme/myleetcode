#include <stdio.h>
#include <stdlib.h>

char *convertToTitle(int n) {
    int i = 0;
    char *ch = calloc(255, sizeof(char));
    char *ch1 = calloc(255, sizeof(char));
    while(n > 0) {
        n--;
        *(ch + i) = (n % 26) + 'A';
        i++;
        n = n / 26;
    }
    for(i = 0; i < strlen(ch); i++) {
        *(ch1 + i) = *(ch + strlen(ch) - i - 1);
    }
    free(ch);
    return ch1;
}


int main() {
    char *result = convertToTitle(1234321);
    printf("%s", result);
    free(result);
}
