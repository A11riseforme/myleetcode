#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int start = 0;
    int gasLeft = 0;
    int gasDebt = 0;
    for (int i = 0; i < gasSize; i++) {
        gasLeft += gas[i] - cost[i];
        if (gasLeft < 0) {
            gasDebt += gasLeft;
            start = i + 1;
            gasLeft = 0;
        }
    }
    return gasLeft + gasDebt >= 0 ? start : -1;
}


int main(void) {
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int count = sizeof(gas) / sizeof(*gas);
    printf("can %scomplete the circuit\n", canCompleteCircuit(gas, count, cost, count) != -1 ? "" : "not ");
    return 0;
}
