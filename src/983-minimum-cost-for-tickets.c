#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b)) ? (b) : (a)

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int *dp = malloc((days[daysSize - 1] + 1) * sizeof(int));
    bool *needT = malloc((days[daysSize - 1] + 1) * sizeof(bool));
    memset(needT, false, days[daysSize - 1] + 1);
    for (int i = 0; i < daysSize; ++i) {
        needT[days[i]] = true;
    }
    dp[0] = 0;
    int tmp1, tmp7, tmp30;
    for (int i = 1; i <= days[daysSize - 1]; ++i) {
        if (!needT[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        tmp1 = dp[i - 1] + costs[0];
        tmp7 = dp[i - 7 > 0 ? i - 7 : 0] + costs[1];
        tmp30 = dp[i - 30 > 0 ? i - 30 : 0] + costs[2];
        dp[i] = MIN(tmp1, MIN(tmp7, tmp30));
    }
    free(needT);
    int result = dp[days[daysSize - 1]];
    free(dp);
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int days[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    int costs[] = {2, 7, 15};
    printf("%d", mincostTickets(days, sizeof(days) / sizeof(days[0]), costs, sizeof(costs) / sizeof(costs[0])));
    return 0;
}
