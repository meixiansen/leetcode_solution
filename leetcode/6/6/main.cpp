#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
//    string convert(string s, int numRows) {
//        string result = "";
//        if(s.empty())  return result;
//        if(numRows==1) return s;
//        vector<string> v_result;
//        int t;
//        for(t=0;t<numRows&&t<s.size();t++)
//        {
//            v_result.push_back("");
//        }
//        int size =s.size();
//        int length = 2*numRows-2;
//        int num = size/length+1;
//        int i;
//        for(i=0;i<num;i++)
//        {
//            int j;
//            for(j=0;j<length&&j<s.size()-i*length;j++)
//            {
//                int ind = j+i*length;
//                if(j<numRows)
//                {
//                    v_result[j]+=s[ind];
//                }
//                else
//                {
//                    v_result[length-j]+=s[ind];
//                }
//            }
//        }
//        for(int t=0;t<numRows&&t<s.size();t++)
//        {
//            result+=v_result[t];
//        }
//        return result;
//    }
    string convert(string s, int numRows) {
        string result = "";
        if(s.empty())  return result;
        if(numRows==1) return s;
        string* v_result = new string [numRows];
        int size =s.size();
        int length = 2*numRows-2;
        int num = size/length+1;
        int i;
        for(i=0;i<num;i++)
        {
            int j;
            for(j=0;j<length&&j<s.size()-i*length;j++)
            {
                int ind = j+i*length;
                if(j<numRows)   v_result[j]+=s[ind];
                else v_result[length-j]+=s[ind];
            }
        }
        for(int t=0;t<numRows&&t<s.size();t++)
        {
            result+=v_result[t];
        }
        delete[] v_result;
        return result;
    }

};

int main()
{

    Solution solution;
    string s = "asdda";
    cout<<solution.convert(s,1)<<endl;
}
