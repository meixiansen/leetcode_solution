//20. Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<stdio.h>
#include<limits.h>
#include<stack>
using namespace std;

class Solution {
public:
    //    bool isValid(string s) {
    //        int i ;
    //        vector<int> label;
    //        for(i=0;i<s.size();i++)
    //        {
    //            if(s[i]=='{') label.push_back(3);
    //            else if(s[i]=='(') label.push_back(2);
    //            else if(s[i]=='[') label.push_back(1);
    //            else  {
    ////                cout<<i<<endl;
    //                if(s[i]==']')  label.push_back(-1);
    //                if(s[i]==')') label.push_back(-2);
    //                if(s[i]=='}')  label.push_back(-3);
    //                int j;
    //                for(j=i-1;j>0;j--)
    //                {
    //                    if(label[i]+label[j]!=0&&label[j]!=0) return false;
    //                    else if(label[i]+label[j]==0) {label[i]=0;label[j]=0;break;}
    //                }
    //            }
    //        }
    //        int sum = 0;
    //        for(int i=0;i<label.size();i++)
    //        {
    //            sum+=label[i];
    //        }
    //        if(sum==0)return true;

    //        else return false;
    //    }
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int i=0;i<s.size();i++)
        {

            c = s[i];
            switch (c) {
            case '{': st.push(c);break;
            case '(': st.push(c);break;
            case '[': st.push(c);break;
            case '}': if(st.empty()||st.top()!='{'){return false;}else st.pop();break;
            case ')': if(st.empty()||st.top()!='('){return false;}else st.pop();break;
            case ']': if(st.empty()||st.top()!='['){return false;}else st.pop();break;
            default:
                break;
            }
        }
       return st.empty() ;
    }
};
int main()
{
    string in = "]";
    Solution s;
    cout<<s.isValid(in)<<endl;
}
