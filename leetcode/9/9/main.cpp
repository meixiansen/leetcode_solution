
//#9. Palindrome Number
//#Determine whether an integer is a palindrome. Do this without extra space.
//#Could negative integers be palindromes? (ie, -1)

//#If you are thinking of converting the integer to string, note the restriction of using extra space.

//#You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

//#There is a more generic way of solving this problem.
#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;
class Solution {
public:
    //first AC
    //    bool isPalindrome(int x) {
    //        long  long result=0;
    //        if(x>0){
    //            int y = x;
    //            while(x)
    //            {
    //                result = result*10+x%10;
    //                x=x/10;
    //            }
    //            if(INT_MIN<result&&result<INT_MAX)
    //            {
    //                if(y==result) return true;
    //                else return false;
    //            }
    //            else return false;
    //        }
    //        else if(x<0)  return false;
    //        else return true;
    //    }
    //second AC
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0)) return false;
        int result = 0;
        while(result<x)
        {
            result = result*10+x%10;
            x=x/10;
            if(result==x)
            {
                return true;
            }
        }
        if(result/10==x) return true;
        return false;
    }
    //       else if(x<0)  return false;
    //       else return true;
    //   }
};

int main()
{
    int x =;
    Solution s;
    if(s.isPalindrome(x)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
