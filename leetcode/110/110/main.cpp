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
