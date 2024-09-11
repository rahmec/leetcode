# Best Time to Buy and Sell Stock (121)

## Description
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Code 

'''
int maxProfit(int* prices, int pricesSize) {

    int buying = 0;
    int selling = 0;
    int profit = 0;

    for(int i=0; i<pricesSize; i++){
        if(prices[i]<prices[buying]){
            buying=i;
        } else if(prices[i] > prices[selling]){
            if(profit < (prices[i]-prices[buying]))
                profit = prices[i]-prices[buying];
        }

    }

    return profit;
    
}
'''

Semplificabile in:

'''
int maxProfit(int* prices, int pricesSize) {

    int buying = 0;
    int profit = 0;

    for(int i=0; i<pricesSize; i++){
        
        if(prices[i]<prices[buying]){
            buying=i;
        }
        else if(profit < (prices[i]-prices[buying])){
                profit = prices[i]-prices[buying];
        }
    }

    return profit;
    
}
'''

