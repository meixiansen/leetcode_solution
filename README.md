# leetcode_solution
solution of problems in leetcode

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

## 1. Two Sum


```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int i;
         vector<int> result;
        for(i=0;i<nums.size();i++)
        {
            int e = target-nums[i];
            if(map.find(e)!=map.end())
            {
                result.push_back(i);
                 result.push_back(map[e]);
                 break;
            }
            else
            {
            map.insert(make_pair(nums[i],i));
            }
        }
       return result;
    }
};

```
