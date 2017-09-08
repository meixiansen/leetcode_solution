
//7. Reverse Integer
//Reverse digits of an integer.

//Example1: x = 123, return 321
//Example2: x = -123, return -321
// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.


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
//    int reverse(int x) {
//        const int int_thre = 1147483647;
//        bool negative = false;
//        if( x<0) negative = true;
//        x = abs(x);
//        string num;
//        stringstream stream;
//        stream<<x;
//        num = stream.str();
//        int i=0;
//        int newnum =0;
//        if (num.size()>10) return 0;
//        for(i=0;i<num.size();i++)
//        {

//            if(i==9&&num[i]-48>1)
//            {
//               int judge = newnum + 1*pow(10,i);
//               if( (!negative&&judge>int_thre)||(negative&&judge>int_thre+1))return 0;
//            }
//            newnum += int(num[i]-48)*pow(10,i);
////            cout<<num[i]<<" "<<newnum<<endl;
//        }
//        if(negative) return newnum*(-1);
//        return newnum;
//    }

    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
int main()
{
    int a = -123;
    Solution s;
    cout<<s.reverse(a)<<endl;
}

