
//104. Maximum Depth of Binary Tree
//Given a binary tree, find its maximum depth.

//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node./**


// Definition for a binary tree node.
#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else  if(root->left||root->right)return std::max(maxDepth(root->left),maxDepth(root->right))+1;
        else return 1;
    }
    //深度优先遍历
    void depthFirstSearch(TreeNode *root){
        stack<TreeNode *> nodeStack;  //使用C++的STL标准模板库
        nodeStack.push(root);
        TreeNode *node;
        while(!nodeStack.empty()){
            node = nodeStack.top();
            cout<<node->val<<endl;  //遍历根结点
            nodeStack.pop();
            if(node->left){
                nodeStack.push(node->left);  //先将右子树压栈
            }
            if(node->right){
                nodeStack.push(node->right);  //再将左子树压栈
            }
        }
    }
    //广度优先遍历
    void breadthFirstSearch(TreeNode* root){
        queue<TreeNode *> nodeQueue;  //使用C++的STL标准模板库
        nodeQueue.push(root);
        TreeNode *node;
        while(!nodeQueue.empty()){
            node = nodeQueue.front();
            nodeQueue.pop();
            cout<<node->val<<endl;
            if(node->left){
                nodeQueue.push(node->left);  //先将左子树入队
            }
            if(node->right){
                nodeQueue.push(node->right);  //再将右子树入队
            }
        }
    }
    int maxdepth(TreeNode* root) {
        int ret = 0;
        int depth = 0;
        stack< pair<TreeNode*, int> > stk;
        while (root) {
            stk.push(make_pair(root, ++depth));
            if (depth > ret) ret = depth;
            root = root->left;
        }
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (node.first->right) {
                root = node.first->right;
                depth = node.second;
                while (root) {
                    stk.push(make_pair(root, ++depth));
                    if (depth > ret) ret = depth;
                    root = root->left;
                }
            }
        }
        return ret;
    }
    bool isBalanced(TreeNode *root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return true;
        TreeNode *node = root;
        if(abs(maxdepth(node->left)-maxdepth(node->right))<2&&isBalanced(node->left)&&isBalanced(node->right)) return true;
        else return false;
    }
};
int main()
{
    TreeNode root(1);
    TreeNode r1(2);
    TreeNode r2(3);
    TreeNode r3(4);
    TreeNode r4(5);
    TreeNode r5(6);
    TreeNode r6(7);
    root.left = &r1;
    root.right = &r2;
    r2.left = &r3;
     r3.left = &r4;
    Solution s;
    cout<<s.isBalanced(&root)<<endl;
    return 0;
}
