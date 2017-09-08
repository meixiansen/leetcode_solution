//19. Remove Nth Node From End of List
//Given a linked list, remove the nth node from the end of list and return its head.

//For example,

//   Given linked list: 1->2->3->4->5, and n = 2.

//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //最简单的想法，先统计链表长度，然后找到删除的节点的id，然后进行删除
//    ListNode* removeNthFromEnd(ListNode* head, int id) {
//        ListNode *pf = head;
//        ListNode *pn = head;
//        int i = 0;
//        while(pn!=NULL)
//        {
//            i++;
//            pn = pn->next;
//        }
//        pn = head;
//        id = i - id+1;
//        if(id ==1){return head->next;delete head;}
//        int j=0;
//        while(pn!=NULL)
//        {
//            j++;
//            if(j==id)
//            {
//                pf->next=pn->next;break;
//                delete pn;
//            }
//            if(i>1) pf = pn;
//            pn = pn->next;
//        }
//        return head;
//    }
    ListNode* removeNthFromEnd(ListNode* head, int id) {
        ListNode *pn = head;
        vector<ListNode *> pListNode ;
        while(pn!=NULL)
        {
            pListNode.push_back(pn);
            pn = pn->next;
        }
        id = pListNode.size() - id+1;
        if(id ==1){return head->next;}
        pListNode[id-2]->next =  pListNode[id-1]->next;
        return head;
    }
};

int main()
{
    int i=2;
    int id = 5;
    ListNode node(1);
    ListNode* head = &node;
    ListNode* pnext = &node;
    while(i<=5)
    {
        ListNode* n = new ListNode(i);
        pnext->next = n;
        pnext = n;
        i++;
    }
    Solution solu;
    ListNode * result,*pre;
    result =  solu.removeNthFromEnd(head,id);
    pre =result;
    while(pre!=NULL)
    {
        cout<<pre->val<<endl;
        pre=pre->next;
    }
    return 0;
}
