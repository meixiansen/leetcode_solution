#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    //    int lengthOfLongestSubstring(string s) {
    //        if(s.empty()) return 0;
    //        unordered_map<char,int> m;
    //        int x=0,y=1;
    //        int max = 1;
    //        int i=0;
    //        while(i<s.length())
    //        {
    //            char c = (char)s[i];
    //            unordered_map<char,int>::iterator  t ;
    //            t= m.find(c);
    //            if(t==m.end())
    //            {
    //                y= i;
    //                m.insert(unordered_map<char,int>::value_type(c,i));
    //                if(i==s.length()-1)
    //                {
    //                max = y-x+1>max?y-x+1:max;
    //                }
    //            }
    //            else
    //            {
    //                max = y-x+1>max?y-x+1:max;
    //                i = t->second;
    //                m.clear();
    //                x=y=i+1;
    //            }
    //            i++;
    //        }
    //        return max;
    //    }


    //    int lengthOfLongestSubstring(string s) {
    //        if(s.empty()) return 0;
    //        unordered_map<char,int> m;
    //        int x=0,y=1;
    //        vector<pair<int ,int>> length;
    //        int i=0;
    //        while(i<s.length())
    //        {
    //            char c = (char)s[i];
    //            unordered_map<char,int>::iterator  t ;
    //            t= m.find(c);
    //            if(t==m.end())
    //            {
    //                y= i;
    //                m.insert(unordered_map<char,int>::value_type(c,i));
    //                if(i==s.length()-1)
    //                {
    //                    pair<int,int> c(x,y);
    //                    length.push_back(c);
    //                }
    //            }
    //            else
    //            {
    //                pair<int,int> c(x,y);
    //                length.push_back(c);
    //                i = t->second;
    //                m.clear();
    //                x=y=i+1;
    //            }
    //            i++;
    //        }
    //        int max=0;
    //        for(int j=0;j<length.size();j++)
    //        {
    //            if(max<length[j].second-length[j].first)
    //            {
    //                max =length[j].second-length[j].first;
    //            }
    //        }
    //        return ++max;
    //    }

    //        int lengthOfLongestSubstring(string s) {
    //            vector<int> dict(256, -1);
    //                    int maxLen = 0, start = -1;
    //                    for (int i = 0; i != s.length(); i++) {
    //                        if (dict[s[i]] > start)
    //                            start = dict[s[i]];
    //                        dict[s[i]] = i;
    //                                  cout<<i<<" "<<start<<endl;
    //                        maxLen = max(maxLen, i - start);

    //                    }
    //                    return maxLen;
    //        }

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int x=-1;
        int max =0;
        int i=0;
        while(i<s.length())
        {
            unordered_map<char,int>::iterator  t ;
            t= m.find((char)s[i]);
            if(t!=m.end())
            {
                if(t->second>x)
                {
                    x = t->second;
                }
            }
            max = std::max(max,(i-x));
            m[(char)s[i]] = i;
            i++;
        }
        return max;
    }
};
int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("abba")<<endl;
    return 0;
}
