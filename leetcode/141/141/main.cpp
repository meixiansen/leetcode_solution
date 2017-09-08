


//141. Linked List Cycle
//Given a linked list, determine if it has a cycle in it.

//Follow up:
//Can you solve it without using extra space?

/**
 * Definition for singly-linked list. */
#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        std::map<ListNode *,int> m;
        while(cur!=NULL)
        {
            if(m.find(cur)==m.end()) {m[cur] = 1;cur=cur->next;}
            else return true;
        }
        return false;
    }
};
int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l1;
    Solution s;
    cout<<s.hasCycle(&l1)<<endl;
    return 0;
}
