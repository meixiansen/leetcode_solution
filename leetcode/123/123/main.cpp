
//Add to List
//123. Best Time to Buy and Sell Stock III
//DescriptionHintsSubmissionsDiscussSolution
//Discuss Pick One
//Say you have an array for which the ith element is the price of a given stock on day i.

//Design an algorithm to find the maximum profit. You may complete at most two transactions

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
