
//121. Best Time to Buy and Sell Stock
//Say you have an array for which the ith element is the price of a given stock on day i.

//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5

//max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//Input: [7, 6, 4, 3, 1]
//Output: 0

//In this case, no transaction is done, i.e. max profit = 0.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        int i,id_begin,id_end;
        id_begin = 0;
        id_end = 0;
        int max = 0;
        for(i=1;i<prices.size();i++)
        {
            if(prices[id_end]<prices[i])
            {
                id_end = i;
                if(id_end>id_begin&&max< prices[id_end]-prices[id_begin]) max =  prices[id_end]-prices[id_begin];
            }
            else if(prices[id_begin]>prices[i]&&prices[id_end]>prices[i])
            {
                id_begin = i;
                id_end=i;
            }
        }
        return max;
    }
};
int main()
{
    vector<int> prices = {2,9,1,10,3,2,4,7};
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
}

