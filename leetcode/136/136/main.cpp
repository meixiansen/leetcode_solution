
//136. Single Number
//Given an array of integers, every element appears twice except for one. Find that single one.

//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,j;
                unordered_map<int,int> m;
                int result = 0;
                for(i=0;i<nums.size();i++)
                    {
                    if(m.find(nums[i])==m.end()) m[nums[i]] = 1;
                    else m[nums[i]] = 0;
                }
                for(i=0;i<n;i++)
                    {
                     if(m[nums[i]] == 1)
                     {result = nums[i];break;}
                }
                return result;
    }
};
int main()
{

}
