
#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
//struct Node
//{
//    int value;
//    struct Node *next;
//    Node(int v):value(v),next(NULL){}
//};
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        unordered_map<int,int> m;
        int num = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end()) {m[nums[i]]=1;num++;}
        }
        return num;
    }
};
int main()
{
//    Node h(0);
//    Node n1(1);
//    h.next = &n1;
//    Node n2(2);
//    n1.next = &n2;
//    Node n3(3);
//    n2.next = &n3;
//    Node n4(4);
//    n3.next = &n4;
//    Node n5(5);
//    n4.next = &n5;
//    //    Node *head = &h;
//    Node *head = new Node(-1);
//    head->next=&h;
//    head->value = -1;
//    Node *temp = head;
////    cout<<temp->value<<endl;
//    while(temp!=NULL)
//    {
//        cout<<temp->value<<endl;
//        temp = temp->next;
//    }
//    cout<<head->value<<endl;
    vector<int> nums = {1,1,2,2,4,5,6,7,8,9,9};
    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
}
