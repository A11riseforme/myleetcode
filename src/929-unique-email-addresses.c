#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isSame(char *a, char *b) {
    char aName[200] = {0};
    char bName[200] = {0};
    int i = 0;
    int j = 0;
    while (*a != '@') {
        if (*a == '+') {
            while (*a != '@') {
                a++;
            }
            break;
        }
        while (*a == '.') {
            a++;
        }
        aName[i++] = *a++;
    }
    while (*b != '@') {
        if (*b == '+') {
            while (*b != '@') {
                b++;
            }
            break;
        }
        while (*b == '.') {
            b++;
        }
        bName[j++] = *b++;
    }
    if (strcmp(aName, bName)) {
        return false;
    }
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return false;
        }
        a++;
        b++;
    }
    if (*a != '\0' || *b != '\0') {
        return false;
    }
    return true;
}


int numUniqueEmails(char** emails, int emailsSize) {
    int result = 1;
    bool isDup = false;
    for (int i = 1; i < emailsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (isSame(emails[j], emails[i])) {
                isDup = true;
                break;
            }
        }
        if (!isDup) {
            result++;
        }
        isDup = false;
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc <= 3) {
        fprintf(stderr, "Usage: ./test email1 email2 email3 ...\n");
        exit(-1);
    }
    char **emails = malloc((argc - 1) * sizeof(char*));
    for (int i = 0; i < argc - 1; i++) {
        emails[i] = argv[i + 1];
    }
    printf("%d", numUniqueEmails(emails, argc - 1));
    free(emails);
    return 0;
}
