# Best Time To Buy Stocks 2

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

