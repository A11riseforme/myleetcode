#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 0)
        return 0;
    int i;
    int price = prices[0];
    int profit = 0;
    for(i = 1; i < pricesSize; i++) {
        if(prices[i] < price)
            price = prices[i];
        if(profit < prices[i] - price)
            profit = prices[i] - price;
    }
    return profit;
}


int main(void) {
    int prices[6] = {7,1,5,3,6,4};
    printf("the maximum profit is %d", maxProfit(prices, 6));
}
