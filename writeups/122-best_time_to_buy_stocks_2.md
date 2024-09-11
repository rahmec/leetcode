# Best Time To Buy Stocks 2

## Description

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

## Reasoning

Buy at local minimums and sell at local highs.

## Code
'''
int maxProfit(int* prices, int pricesSize) {

    int totalProfit = 0;
    bool holding = false;

    for(int i=0; i < pricesSize-1; i++){
        if(!holding && prices[i] < prices[i+1]){
        // Local minimum => buy
            totalProfit -= prices[i];
            holding = true;
        } else if(holding && prices[i] > prices[i+1]){ // If it's a local maximum I sell
            totalProfit += prices[i];
            holding = false;
        }
    }

    if(holding){
        totalProfit += prices[pricesSize - 1];
    }

    return totalProfit;
}
'''

