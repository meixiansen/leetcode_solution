//13. Roman to Integer
//Given a roman numeral, convert it to an integer.

//Input is guaranteed to be within the range from 1 to 3999.
#include<iostream>
#include<limits.h>
#include<cmath>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int i;
        int result = map[s[s.size()-1]];
        for(i = s.size()-2;i>=0;i--)
        {
            if(map[s[i]]>= map[s[i+1]])
            {
               result+=map[s[i]];
            }
            else
            {
                result= result - map[s[i]];
            }
        }
        return result;
    }
};
int main()
{
    string num="MCMXCVI";
    Solution s;
    cout<<s.romanToInt(num)<<endl;
    return 0;
}
