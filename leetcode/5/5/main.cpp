
//5. Longest Palindromic Substring
//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//Example:
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example:
//Input: "cbbd"
//Output: "bb"
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string result ="";

        if(s.size()==1) result.push_back(s[0]);
        else if(s.size()==2)  {
            if(s[0]==s[1]) return s;
            result.push_back(s[0]);
        }
        else{
            pair<int,int> resu;
            int i;
            int size = 0;
            for(i=0;i<s.size();i++)
            {
                int t ;
                int j ;
                for(int g=1;g<3;g++)
                {
                    t = i;
                    j = i + g;
                    if(s[t]==s[j]){
                        bool Is_break = false;
                        while(t>=0&&j<=s.size()-1)
                        {
                            if(s[t]!=s[j]) { Is_break=true; break;}
                            t--;
                            j++;
                        }
                        t++;
                        j--;
                        if( j - t > size)
                        {
                            resu.first = t;
                            resu.second = j;
                            size = j - t;
                        }
                    }
                }
            }
            result.assign(s,resu.first,resu.second-resu.first+1);
        }
        return result;
    }
};
int main()
{
    Solution solution;
    string s ={"aaaa"};
    cout<<solution.longestPalindrome(s)<<endl;
    return 0;
}
