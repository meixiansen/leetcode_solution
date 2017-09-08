//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<stdio.h>
#include<limits.h>
using namespace std;
class Solution {
public:
   //misunderstanding the question ,this code is for finding longest common string amongst an array of strings
//    string longestCommonPrefix_betweenTwo(string str , string substring)
//    {
//        if(substring==""||str=="") return "";
//        string::size_type position = 0;
//        int length = -1;
//        int begin = 0,end = 0;
//        for(int i=0;i<substring.size();i++)
//        {
//            while((position = str.find_first_of(substring[i],position))!= string::npos)
//            {
//                int position2 = position+substring.size()>str.size()?str.size():position+substring.size();
//                for(int m = position;m< position2; m++)
//                {
//                    if(str[m]!=substring[m-position]) {position2 = m;break;}
//                }
////                cout<<position<<" "<<position2<<endl;
//                if(position2-int(position)>length)
//                {
//                    begin = int(position);
//                    end = int(position2);
//                    length = end -begin;
//                }
//                position++;
//            }
//        }
//        string result = "";
//        for(int i=begin;i<end;i++)
//        {
//            result+=str[i];
//        }
//        return result;
//    }
//    string longestCommonPrefix(vector<string>& strs) {
//        string result = "";
//        if(strs.size()>1)
//        {
//            int i,j,min_id = -1,min = INT_MAX;
//            for(i=0;i<strs.size();i++)
//            {
//                if(strs[i].size()<min)
//                {
//                    min = strs[i].size();
//                    min_id = i;
//                }
//            }
//            if(min==0) return result;
//            string substring = strs[min_id];
//            for(j=0;j<strs.size();j++)
//            {
//                if(j!=min_id)
//                {
//                    substring = longestCommonPrefix_betweenTwo(strs[j],substring);
////                    cout<<substring<<endl;
//                }
//            }
//            result = substring ;
//        }
//        else if(strs.size()==1){
//            return  strs[0];
//        }
//        return result;
//    }
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size()>1)
        {
            int i,j,min_id = -1,min = INT_MAX;
            for(i=0;i<strs.size();i++)
            {
                if(strs[i].size()<min)
                {
                    min = strs[i].size();
                    min_id = i;
                }
            }
            if(min==0) return result;
            string substring = strs[min_id];
            for(j=0;j<strs.size();j++)
            {
                if(j!=min_id)
                {
                    int t ;
                   for(t=0;t<substring.size();t++)
                   {
                       if(substring[t]!=strs[j][t]) break;
                   }
                   if(t==0) return "";
                   string s;
                   s.assign(substring,0,t);
                   substring =s ;
                }
            }
            result = substring ;
        }
        else if(strs.size()==1){
            return  strs[0];
        }
        return result;
        }
};
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string prefix = "";
//        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
//            for(int i=0; i<strs.size(); i++)
//                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
//                    return prefix;
//        return prefix;
//    }
//};
int main()
{
    Solution ss;
    vector<string> strs ;
    strs.push_back("c");
    strs.push_back("c");
//    strs.push_back("a");
    //      strs.push_back("c");
    //      strs.push_back("c");
    cout<<ss.longestCommonPrefix(strs)<<endl;
    //     cout<<ss.longestCommonPrefix_betweenTwo(strs[0],strs[1])<<endl;
    //    string s("1aaab3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i");
    //    string flag;
    //    string::size_type position;
    //    flag="a";
    //     position=0;
    //     int i=1;
    //     while((position=s.find_first_of(flag,position))!=string::npos)
    //     {
    //      //position=s.find_first_of(flag,position);
    //      cout<<"position  "<<i<<" : "<<position<<endl;
    //      position++;
    //      i++;
    //     }
    return 0;
}
