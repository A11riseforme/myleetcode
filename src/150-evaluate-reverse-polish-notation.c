#include <stdio.h>
#include <stdbool.h>

int evalRPN(char** tokens, int tokensSize) {
    int *element = calloc(tokensSize, sizeof(int));
    int size = 0;
    int tmp;
    for (int i = 0; i < tokensSize; i++) {
        // if replace "tokens[i][1] != '\0'" to "isdigit(tokens[i][0])"
        // runtime will increase from 0ms to 4ms, I think it is because
        // isdigit(tokens[i][0]) is doing two checks as :
        // tokens[i][1] >= '0' && tokens[i][1] <= '9', but tokens[i][1] != '\0' only did one check.
        if (isdigit(tokens[i][0]) || tokens[i][1] != '\0') {
            element[size++] = atoi(tokens[i]);
        } else {
            switch (tokens[i][0]) {
            case '+':
                tmp = element[size - 2] + element[size - 1];
                size -= 2;
                element[size++] = tmp;
                break;
            case '-':
                tmp = element[size - 2] - element[size - 1];
                size -= 2;
                element[size++] = tmp;
                break;
            case '*':
                tmp = element[size - 2] * element[size - 1];
                size -= 2;
                element[size++] = tmp;
                break;
            case '/':
                tmp = element[size - 2] / element[size - 1];
                size -= 2;
                element[size++] = tmp;
                break;
            }
        }
    }
    int result = element[0];
    free(element);
    return result;
}


int main() {
    char **tokens = calloc(5, sizeof(char *)); //["2", "1", "+", "3", "*"]
    *(tokens + 0) = "2";
    *(tokens + 1) = "1";
    *(tokens + 2) = "+";
    *(tokens + 3) = "3";
    *(tokens + 4) = "*";
    printf("%d\n", evalRPN(tokens, 5));
    free(tokens);
    return 0;
}
