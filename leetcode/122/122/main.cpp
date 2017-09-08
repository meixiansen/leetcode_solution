

//Say you have an array for which the i th element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete as many transactions
//as you like (ie, buy one and sell one share of the stock multiple times). However, you may
//not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
        int sum = 0;
        for(i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1])
            {
                id_end = i+1;
            }
            else
            {
                if(id_begin<id_end) {sum+=(prices[id_end]-prices[id_begin]);id_begin=++id_end;}
                else id_begin++;
            }
        }
        if(id_end==prices.size()-1) sum+=(prices[id_end]-prices[id_begin]);
        return sum;
    }
};
int main()
{
    vector<int> prices = {1,2,3,4,5,6,7};
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
}
