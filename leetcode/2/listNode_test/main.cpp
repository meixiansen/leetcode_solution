#include<malloc.h>
#include<iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode *addTwoNumbers() {
        ListNode first_node(0);
        ListNode node1(1);
        ListNode node2(2);
        ListNode node3(3);
        ListNode node4(4);
        first_node.next = &node1;
        node1.next = &node2;
        node2.next=&node3;
        node3.next = &node4;
        return &first_node;
    }
    ListNode *Createlist()
    {
        ListNode *first_node = new ListNode(0);
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        first_node->next = node1;
        node1->next = node2;
        node2->next=node3;
        node3->next = node4;
        return first_node;
    }

int main()
{
    ListNode *pt1,*pt2;
    ListNode l1(1),l2(9),l3(9);
    pt1 = &l1;
    l1.next=&l2;
    pt2 = &l3;
    ListNode *result= addTwoNumbers();
//    std::cout<<result->next->next->val<<std::endl;
    while(result)
    {
        std::cout<<result->val<<std::endl;
        result=result->next;
    }
    return 0;
}
