
//12. Integer to Roman
//Given an integer, convert it to a roman numeral.

//Input is guaranteed to be within the range from 1 to 3999.
#include<iostream>
#include<limits.h>
#include<cmath>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result="";
        unordered_map<string,int> map;
        map["I"] = 1;
        map["IV"] = 4;
        map["V"] = 5;
        map["IX"] = 9;
        map["X"] = 10;
        map["XL"] = 40;
        map["L"] = 50;
        map["XC"] = 90;
        map["C"] = 100;
        map["CD"] = 400;
        map["D"] = 500;
        map["CM"] = 900;
        map["M"] = 1000;
        string ca[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i = 0;
        while(i<13){
            int n = num/map[ca[i]];
            for(int j = 0;j<n;j++)
            {
                result+=ca[i];
            }
            num = num %map[ca[i]];
            i++;
        }
        return result;
    }
};

int main()
{
    int num=9;
    Solution s;
    cout<<s.intToRoman(num)<<endl;
    return 0;
}
