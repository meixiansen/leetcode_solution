#include<malloc.h>
#include<iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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

    /*{
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
                if(sum>10)
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
    }*/
};
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode *p = l1, *q = l2;
//        ListNode *r = (ListNode *)malloc(sizeof(ListNode));
//        ListNode *s = r;
//        int shi_val = 0;
//        while(p && q){
//            ListNode *t = (ListNode *)malloc(sizeof(ListNode));
//            t->val = (p->val + q->val + shi_val) % 10;
//            shi_val = (p->val + q->val + shi_val) / 10;
//            s->next = t;
//            s = t;
//            p = p->next;
//            q = q->next;
//        }
//        while(p){
//            ListNode *t = (ListNode *)malloc(sizeof(ListNode));
//            t->val = (p->val + shi_val) % 10;
//            shi_val = (p->val + shi_val) / 10;
//            s->next = t;
//            s = t;
//            p = p->next;
//        }
//        while(q){
//            ListNode *t = (ListNode *)malloc(sizeof(ListNode));
//            t->val = (q->val + shi_val) % 10;
//            shi_val = (q->val + shi_val) / 10;
//            s->next = t;
//            s = t;
//            q = q->next;
//        }
//        if(shi_val){
//            ListNode *t = (ListNode *)malloc(sizeof(ListNode));
//            t->val = shi_val;
//            s->next = t;
//            s = t;
//        }
//        s->next = NULL;
//        return r->next;
//    }
//};
int main()
{
    Solution s;
    ListNode *pt1,*pt2;
    ListNode l1(),l2(9),l3(9);
    pt1 = &l1;
    l1.next=&l2;
    pt2 = &l3;
    ListNode *result= s.addTwoNumbers(pt1,pt2);
    while(result!=NULL)
    {
        std::cout<<result->val<<std::endl;
        result=result->next;
    }

    return 0;
}
