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
