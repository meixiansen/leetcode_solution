


#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
//    int numTrees(int n) {
//        if(n==0) return 0;
//        else if(n==1||n==2) return n;
//        int sum = 0;
//        for(int i=1;i<=n;i++)
//            {
//            if(i==1)sum+=numTrees(n-i);
//            else if(i==n)sum+=numTrees(i-1);
//            else sum+=numTrees(n-i)*numTrees(i-1);
//        }
//        return sum;
//    }
//    int numTrees(int n) {
//        if(n==0) return 0;
//        else if(n==1||n==2) return n;
//        int sum = 0;
//        int mid = n/2;
//        for(int i=1;i<=mid;i++)
//            {
//            if(i==1)sum+=2*numTrees(n-i);
//            else sum+=(2*numTrees(n-i)*numTrees(i-1));
//        }
//        if(n%2==1) sum+=numTrees(mid)*numTrees(mid);
//        return sum;
//    }
    int numTrees(int n) {
           if(n<1)
           {
               return 1;
           }
           int dp[n+1]={0};
           dp[0]=1;
           for(int i=1;i<=n;i++)
           {
               for(int j=0;j<i;j++)
               {
                   dp[i]+=(dp[j]*dp[i-j-1]);
               }
           }
           return dp[n];
       }
};
int main()
{
    Solution s;
    cout<<s.numTrees(19)<<endl;
}
