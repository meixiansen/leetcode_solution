#include<cstdlib>
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((x & (1 << i)) ^ (y & (1 << i))) {
                ++res;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout<<s.hammingDistance(1577962638,1727613287)<<endl;

}
