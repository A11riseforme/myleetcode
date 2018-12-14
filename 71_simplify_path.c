#include <stdio.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    char *result = calloc(1024, sizeof(char));
    int test = path;
    int length = 0;
    while (*path != '\0') {
        // parse //
        if (*path == '/' && *(path + 1) == '/') {
            path++;
        // parse /./ or /.$, $ is the end of the string.
        } else if (*path == '/' && *(path + 1) == '.' && (*(path + 2) == '/' || *(path + 2) == '\0')) {
            path = path + 2;
        // parse /../ or /..$, $ is the end of the string.
        } else if (*path == '/' && *(path + 1) == '.' && *(path + 2) == '.' && (*(path + 3) == '/' || *(path + 3) == '\0')) {
            path = path + 3;
            if (length > 1) {
                while (*(result + --length) != '/') {
                    *(result + length) = '\0';
                }
                *(result + length) = '\0';
            }
        // parse /xxxx/ or /xxxx$, xxxx is directory, minimum length of 1.
        } else if (*path == '/' && *(path + 1) != '/' && *(path + 1) != '.' && *(path + 1) != '\0') {
            *(result + length++) = *path++;
            while (*path != '/' && *path != '\0') {
                *(result + length++) = *path++;
            }
        } else {
            *(result + length++) = *path++;
        }
    }
    // if last character is /, strip it first.
    if (*(result - 1 + length) == '/') {
        *(result - 1 + length--) = '\0';
    }
    // if nothing left, add one / back.
    if (length == 0) {
        *result = '/';
    }
    return result;
}


int main() {
    char *a = "/..///BRXvYnNWVWZlNgWkBPj/./oHaBJef/../qTBNaY///./hXwnd/ifSezVjiZwysfd/./OjibMMcWhrZi/feengAlYRFU/../QmMbppNHgHUOtKcFoQ/ZivEhDiwlKXpq/../L/sBIP/dcYXbHmnmHtm/////////mdiWlPtGaMJR///./AHrjHKLlSaEj///////hzA///BvAxrV/YYg/uKO/SRwqZnFeWzk/////HHQXINWTZfSMNjP///ROQRCswLcWZBlmib/jVvtGnVvmnpRZCafLm/./////XyQOYSjLdGet///WOwnVCNOLyQKLACdVVx/////..///./../.././PQkwWtVtEzBJAMt/lkGU/cvSCeZoGJTOWKHEp///FiuUiD/MrowmfWLWCXXLeS/../LKZYGRMIWKJz/./MGanflzTIObMcYW/foVUAQoKn/LV/..///atASvsoPWi/..///QtHzIALfZTnrFexbdN/./rAqbMT/EvoXWaxt///./ghgOAHGju/.././NzIBQf/vKpzDLscwb/eaJaFJOkvhSU/DKP/iTaZxkkKhbezkHVpLtR///./PUFNJj///../DqjXUgPAgvl/SHe///../../VrKFEIGwczB/mUZOAodCb/.///JeFFworqTPM/MFrHDOawDiONMmUkDf/..///UMJ/./XlY/////../JmTCbNmmSu/mM/../////KEnULhjoqqSDD///.././YTDLFWIgiCBVIUAorhro/../../../././//./lIc/vldNjYF/sRleisiHoV/./hFvIuUpgolGDkb/IBacUlnaEizF///./CnkzsWwOelXjxMM/DureAleALWXA/oMbuYpZYHVidf/WHZUbEwZRjrZS/YZzNnK/.//";
    char *result = simplifyPath(a);
    printf("%s\n", result);
    free(result);
}
