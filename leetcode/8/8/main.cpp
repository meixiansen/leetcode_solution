#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
class Solution {
public:
    //    int myAtoi(string str) {
    //        if(str.empty()) return 0;
    //        long long result = 0;
    //        int i;
    //        int a = 0;
    //        bool haveNum =false;
    //        for(i=0;i<str.size();i++)
    //        {

    //            char c =char(str[i]);
    //            if(c=='+'||c=='-') {
    //                a=c=='+'? 1:-1;
    //                i++;
    //                result=0;
    //                for(;i<str.size();i++)
    //                {
    //                    char c =char(str[i]);
    //                    if(c=='+'||c=='-') return 0;
    //                    else if(c>='0'&&c<='9') result=result*10+c-'0';
    //                    else break;
    //                    if(result>INT_MAX)break;
    //                }
    //                break;
    //            }
    //            else if(c>='0'&&c<='9') {
    //                haveNum=true;
    //                result=result*10+c-'0';
    //            }
    //            else if(haveNum) {
    //                i = str.size();
    //                break;
    //            }
    //            else if(c!=' ') return 0;
    //            if(result-2>INT_MAX){ break;}
    //        }
    //        if (a<0) result*=-1;
    //         if(result>INT_MAX)result = INT_MAX;
    //         if(result<INT_MIN)result = INT_MIN;
    //        return result;
    //    }
    int myAtoi(string str) {
        if(str.empty()) return 0;
        long long result = 0;
        int i;
        int a = 1;
        i = str.find_first_not_of(' ');
        char b =char(str[i]);
        if(b!='-'&&b!='+'&&(b<'0'||b>'9')) return 0;
        else if(b=='-'||b=='+') {a=b=='-'?-1:1;i++;}
        for(;i<str.size();i++)
        {
            if(result-2>INT_MAX) break;
            char c =char(str[i]);
             if(c>='0'&&c<='9') result=result*10+c-'0';
             else break;
        }
        if (a<0) result*=-1;
        if(result>INT_MAX)result = INT_MAX;
        if(result<INT_MIN)result = INT_MIN;
        return result;
    }
};
int main()
{
    string s ="123";
    Solution solution;
    cout<<solution.myAtoi(s)<<endl;
}
