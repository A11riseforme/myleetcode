#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int totalProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        totalProfit += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
    }
    return totalProfit;
}


int main(void) {
    int prices[14] = {5,2,3,2,6,6,2,9,1,0,7,4,5,0};
    printf("the maximum profit is %d", maxProfit(prices, 14));
}
