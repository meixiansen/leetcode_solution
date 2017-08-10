# leetcode_solution
solution of problems in leetcode


## 1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


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

## 2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


```
class Solution {
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool add = false;
        bool iSfirst = true;
         ListNode *first_node = new ListNode(0);
        ListNode *pre = first_node;
        while(l1!=NULL||l2!=NULL)
        {
            int sum=0;
            if(l1!=NULL&&l2!=NULL)
            {
                std::cout<<"here"<<std::endl;
                sum = l1->val+l2->val;
                if(add)
                {
                    sum++;
                    add = false;
                }
                if(sum>=10)
                {
                    add =true;
                    sum = sum%10;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1!=NULL)
            {
//                std::cout<<"here"<<std::endl;
                sum = l1->val;
                if(add)
                {
                    sum++;
                    add = false;
                }
                if(sum>=10)
                {
                    add =true;
                    sum = sum%10;
                }
                l1 = l1->next;
            }
            else if(l2!=NULL)
            {
                sum = l2->val;
                if(add)
                {
                    sum++;
                    add = false;
                }
                if(sum>=10)
                {
                    add =true;
                    sum = sum%10;
                }
                l2 = l2->next;
            }

            if(iSfirst)
            {
                iSfirst =false;
                pre->val = sum;
            }
            else
            {
                ListNode *t = new ListNode(sum);
                pre->next=t;
                pre = t;
            }
        }
        if(add)
        {
            ListNode *t = new ListNode(1);
            pre->next=t;
            pre = t;
        }

        return first_node;
    }
};

```
second AC

```
class Solution {
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *first_node = new ListNode(0);
        ListNode *cur = first_node;
        int add =0;
        while(l1!=NULL||l2!=NULL)
        {
            int sum = 0;
             int num = 0;
            int x = l1!=NULL?l1->val:0;
            int y =  l2!=NULL?l2->val:0;
            sum = x+y+add;
            num = sum%10;
            cur->next =  new ListNode(num);
            cur = cur->next ;
            add = sum/10;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(add>0)
        {
            cur->next = new ListNode(add);
        }
        return first_node->next;
    }
};

```

## 3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


first AC


```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> m;
        int x=0,y=1;
        int max = 1;
        int i=0;
        while(i<s.length())
        {
            char c = (char)s[i];
            unordered_map<char,int>::iterator  t ;
            t= m.find(c);
            if(t==m.end())
            {
                y= i;
                m.insert(unordered_map<char,int>::value_type(c,i));
                if(i==s.length()-1)
                {
                max = y-x+1>max?y-x+1:max;
                }
            }
            else
            {
                max = y-x+1>max?y-x+1:max;
                i = t->second;
                m.clear();
                x=y=i+1;
            }
            i++;
        }
        return max;
    }
};

```

## 4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


Reference to MissMary's ideas 

AC code 

```
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(),size2 = nums2.size();
        if (size1>size2) return findMedianSortedArrays(nums2,nums1);
        int imin = 0,imax = size1;
        int i= (imax+imin)/2,j=(size1 + size2 +1)/2-i;
        int left = 0,right = 0;
        if(size1==0)
        {
            if(size2==0)
            {
                return 0;
            }
            else if(size2==1)
            {
                return double(nums2[0]);
            }
            else
            {
                j = (1+size2)/2;
                left = nums2[j-1];
                right = nums2[j];
            }
        }
        else if(size1==1)
        {
            if(size2==1)
            {
                return (nums2[0]+nums1[0])/2.0;
            }
            else{
                int half = size2/2;
                if (size2%2==0)
                {
                    if(nums2[half]<=nums1[0]) return nums2[half];
                    if(nums2[half-1]>=nums1[0]) return nums2[half-1];
                    else return nums1[0];
                }
                if(size2%2==1)
                {
                    if(nums2[half-1]<nums1[0]&&nums2[half+1]>nums1[0])    return (nums2[half]+nums1[0])/2.0;
                    else if(nums2[half-1]>nums1[0]) return (nums2[half]+nums2[half-1])/2.0;
                    else if(nums2[half+1]<nums1[0]) return (nums2[half]+nums2[half+1])/2.0;
                }
            }
        }
        else{
            while(imin<=imax)
            {
                i = (imax+imin)/2;
                j = (size1 + size2 +1)/2-i;
                cout<<imin<<" "<<i<<" "<<j<<" "<<imax<<endl;
                if(i<size1&&nums2[j -1]>nums1[i]) imin = i+1;
                else  if(i>0&&nums1[i -1]>nums2[j]){ imax = i-1; }
                else if(i==0&&j<size2) {left = nums2[j-1];right= min(nums1[i],nums2[j]);break;}
                else if(i==0&&j==size2) {left = nums2[j-1];right= nums1[i];break;}
                else if(i==size1&&j>0) {left = max(nums2[j-1],nums1[i-1]);right= nums2[j];break;}
                else if(i==size1&&j==0) {left = nums1[i-1];right= nums2[j];break;}
                else  if(nums2[j -1]<=nums1[i]&&nums1[i -1]<=nums2[j])
                {
                    left = max(nums2[j -1],nums1[i -1]);right = min(nums1[i],nums2[j]);break;
                }
            }
        }
        double result;
        if ((size1+size2)%2==0) {result= (left+right)/2.0;  }
        if ((size1+size2)%2==1) result = left;
        return result;
    }
```


