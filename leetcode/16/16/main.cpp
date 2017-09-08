
//16. 3Sum Closest
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//    For example, given array S = {-1 2 1 -4}, and target = 1.

//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool compare_ab(int a ,int b)
    {
        return a<b;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int min=INT_MAX;
        sort(nums.begin(),nums.end(),compare_ab);
        int i,j,t;
        for(i=0;i<nums.size();i++)
        {
            j=i+1;
            t = nums.size()-1;
            while(j<t)
            {
                int dis =nums[i]+nums[j]+nums[t]-target;
                if(dis== 0) {min = 0;break;}
                else if(dis>0) {t--;min=abs(dis)>abs(min)?min:dis;}
                else {j++;min=abs(dis)>abs(min)?min:dis;}
            }
        }
        return target+min;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,2,4,8,16,32,64,128};
    int target =82;
    cout<<s.threeSumClosest(nums,target)<<endl;
    return 0;
}
