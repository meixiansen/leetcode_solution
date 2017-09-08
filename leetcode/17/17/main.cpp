
//17. Letter Combinations of a Phone Number
//Given a digit string, return all possible letter combinations that the number could represent.

//A mapping of digit to letters (just like on the telephone buttons) is given below.



//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//Although the above answer is in lexicographical order, your answer could be in any order you want.

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
//    vector<string> letterCombinations(string digits) {
//        vector<string> result;
//        const  string dict[] = {""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//        int nums[10] = {0};
//        int i,j;
//        for(i=0;i<digits.size();i++)
//        {
//            int num = digits[i] - '0';
//            switch(num)
//            {
//            case 0:nums[0]++;break;
//            case 1:nums[1]++;break;
//            case 2:nums[2]++;break;
//            case 3:nums[3]++;break;
//            case 4:nums[4]++;break;
//            case 5:nums[5]++;break;
//            case 6:nums[6]++;break;
//            case 7:nums[7]++;break;
//            case 8:nums[8]++;break;
//            case 9:nums[9]++;break;
//            }
//        }
//        int t;
//        vector< vector<string> > a_str;
//        for(j=0;j<10;j++)
//        {
//            vector<string> str;
//            get_str(str,dict[j],nums[j]);
//            a_str.push_back(str);
//        }
//        return result;
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> result;
//        if(digits.empty()) return vector<string>();
//        result.push_back("");
//        const  string dict[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//        int i,j;
//        int t;
//        for(i=0;i<digits.size();i++)
//        {
//            int num = digits[i] - '0';
//            if(num==1||num==0) continue;
//            vector<string> temp;
//            for(t=0;t<dict[num].size();t++)
//            {
//                for(j=0;j<result.size();j++)
//                {
//                    temp.push_back(result[j]+dict[num][t]);
//                }
//            }
//            result.swap(temp);
//        }
//        return result;
//    }
//    vector<string> letterCombinations1(string digits) {
//        vector<string> result;
//        if(digits.empty()) return vector<string>();
//        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//        result.push_back("");   // add a seed for the initial case
//        for(int i = 0 ; i < digits.size(); ++i) {
//            int num = digits[i]-'0';
//            if(num < 0 || num > 9) break;
//            const string& candidate = v[num];
//            if(candidate.empty()) continue;
//            vector<string> tmp;
//            for(int j = 0 ; j < candidate.size() ; ++j) {
//                for(int k = 0 ; k < result.size() ; ++k) {
//                    tmp.push_back(result[k] + candidate[j]);
//                }
//            }
//            result.swap(tmp);
//        }
//        return result;
//    }
};
int main()
{
    Solution s;
    string  str = "122";
    vector<string> result= s.letterCombinations(str);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    cout<<result.size()<<endl;
    return 0;
}
