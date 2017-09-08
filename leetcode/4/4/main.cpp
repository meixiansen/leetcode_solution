
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int size1 = nums1.size(),size2 = nums2.size();
          if (size1>size2) return findMedianSortedArrays(nums2,nums1);
          int imin = 0,imax = size1;
          int i= (imax+imin)/2,j=(size1 + size2 +1)/2-i;
          int left = 0,right = 0;
          if(size1==0)
          {
              if(size2==0)
              {
                  return 0;
              }
              else if(size2==1)
              {
                  return double(nums2[0]);
              }
              else
              {
                  j = (1+size2)/2;
                  left = nums2[j-1];
                  right = nums2[j];
              }
          }
          else if(size1==1)
          {
              if(size2==1)
              {
                  return (nums2[0]+nums1[0])/2.0;
              }
              else{
                  int half = size2/2;
                  if (size2%2==0)
                  {
                      if(nums2[half]<=nums1[0]) return nums2[half];
                      if(nums2[half-1]>=nums1[0]) return nums2[half-1];
                      else return nums1[0];
                  }
                  if(size2%2==1)
                  {
                      if(nums2[half-1]<nums1[0]&&nums2[half+1]>nums1[0])    return (nums2[half]+nums1[0])/2.0;
                      else if(nums2[half-1]>nums1[0]) return (nums2[half]+nums2[half-1])/2.0;
                      else if(nums2[half+1]<nums1[0]) return (nums2[half]+nums2[half+1])/2.0;
                  }
              }
          }
          else{
              while(imin<=imax)
              {
                  i = (imax+imin)/2;
                  j = (size1 + size2 +1)/2-i;
                  cout<<imin<<" "<<i<<" "<<j<<" "<<imax<<endl;
                  if(i<size1&&nums2[j -1]>nums1[i]) imin = i+1;
                  else  if(i>0&&nums1[i -1]>nums2[j]){ imax = i-1; }
                  else if(i==0&&j<size2) {left = nums2[j-1];right= min(nums1[i],nums2[j]);break;}
                  else if(i==0&&j==size2) {left = nums2[j-1];right= nums1[i];break;}
                  else if(i==size1&&j>0) {left = max(nums2[j-1],nums1[i-1]);right= nums2[j];break;}
                  else if(i==size1&&j==0) {left = nums1[i-1];right= nums2[j];break;}
                  else  if(nums2[j -1]<=nums1[i]&&nums1[i -1]<=nums2[j])
                  {
                      left = max(nums2[j -1],nums1[i -1]);right = min(nums1[i],nums2[j]);break;
                  }
              }
          }
          double result;
          if ((size1+size2)%2==0) {result= (left+right)/2.0;  }
          if ((size1+size2)%2==1) result = left;
          return result;
      }
//        //AC code
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int size1 = nums1.size(),size2 = nums2.size();
//        if (size1>size2) return findMedianSortedArrays(nums2,nums1);
//        int imin = 0,imax = size1;
//        int i= (imax+imin)/2,j=(size1 + size2 +1)/2-i;
//        int left = 0,right = 0;
//        //when  nums1's size1 == 0 , only consider nums2 ,
//        //case 1 : size2  is 0 , return 0 ;
//        //case 2 : size2 is odd , return nums2[j];
//        //case 3 : size2 is even , (nums2[j-1]+nums2[j])/2.0 .
//        if(size1==0)
//        {
//            j = size2/2;
//            if(size2==0) return 0;
//            else if(size2%2 == 1) return double(nums2[j]);
//            else return (nums2[j-1]+nums2[j])/2.0;
//        }
//        //when  nums1's size1 == 1 , we find cout the median of nums , and find out  whether nums1[0] is adjacent to nums' median
//        //case 1 : size2  is 1 , return (nums2[0]+nums1[0])/2.0 ;
//        //case 2 : size2 is odd , if nums1[0] is  nums' median nums[j], return (nums2[half]+nums1[0])/2.0;
//        //if nums1[0] is not adjacent to median nums[j],and is bigger than median , return (nums2[half]+nums2[half+1])/2.0;
//         //if nums1[0] is not adjacent to median nums[j],and is smaller than median , return (nums2[half]+nums2[half-1])/2.0;
//        //case 3 : size2 is even ,if nums1[0]  is smaller than median return nums2[half-1];
//       //if nums1[0]  is bigger than median return nums2[half];
//        else if(size1==1)
//        {
//            if(size2==1)
//            {
//                return (nums2[0]+nums1[0])/2.0;
//            }
//            else{
//                int half = size2/2;
//                if (size2%2==0)
//                {
//                    if(nums2[half]<=nums1[0]) return nums2[half];
//                    if(nums2[half-1]>=nums1[0]) return nums2[half-1];
//                    else return nums1[0];
//                }
//                if(size2%2==1)
//                {
//                    if(nums2[half-1]<nums1[0]&&nums2[half+1]>nums1[0])    return (nums2[half]+nums1[0])/2.0;
//                    else if(nums2[half-1]>nums1[0]) return (nums2[half]+nums2[half-1])/2.0;
//                    else if(nums2[half+1]<nums1[0]) return (nums2[half]+nums2[half+1])/2.0;
//                }
//            }
//        }
//        //when  nums1's size1 > 1 , reference to MissMary's ideas
//        else{
//            while(imin<=imax)
//            {
//                i = (imax+imin)/2;
//                j = (size1 + size2 +1)/2-i;
//                cout<<imin<<" "<<i<<" "<<j<<" "<<imax<<endl;
//                if(i<size1&&nums2[j -1]>nums1[i]) imin = i+1;
//                else  if(i>0&&nums1[i -1]>nums2[j]){ imax = i-1; }
//                else if(i==0&&j<size2) {left = nums2[j-1];right= min(nums1[i],nums2[j]);break;}
//                else if(i==0&&j==size2) {left = nums2[j-1];right= nums1[i];break;}
//                else if(i==size1&&j>0) {left = max(nums2[j-1],nums1[i-1]);right= nums2[j];break;}
//                else if(i==size1&&j==0) {left = nums1[i-1];right= nums2[j];break;}
//                else  if(nums2[j -1]<=nums1[i]&&nums1[i -1]<=nums2[j])
//                {
//                    left = max(nums2[j -1],nums1[i -1]);right = min(nums1[i],nums2[j]);break;
//                }
//            }
//        }
//        double result;
//        if ((size1+size2)%2==0) {result= (left+right)/2.0;  }
//        if ((size1+size2)%2==1) result = left;
//        return result;
//    }
    //exist some problems when size1==1 or ==0;
//        double findMedianSortedArrays(int A[], int m, int B[], int n) {
//            if (m > n) return findMedianSortedArrays(B, n, A, m);
//            int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
//            while (minidx <= maxidx)
//            {
//              i = (minidx + maxidx) >> 1;
//              j = mid - i;
//              if (i<m && j>0 && B[j-1] > A[i]) minidx = i + 1;
//              else if (i>0 && j<n && B[j] < A[i-1]) maxidx = i - 1;
//              else
//              {
//                if (i == 0) num1 = B[j-1];
//                else if (j == 0) num1 = A[i - 1];
//                else num1 = max(A[i-1],B[j-1]);
//                break;
//              }
//            }
//            if (((m + n) & 1)) return num1;
//            if (i == m) num2 = B[j];
//            else if (j == n) num2 = A[i];
//            else num2 = min(A[i],B[j]);
//            return (num1 + num2) / 2.;
//          }
};
int main()
{
    int a[] ={};
    int b[] = {1,3,5};
    vector<int> num1(a,a);
    vector<int> num2(b,b+3);
    Solution s;
    cout<< s.findMedianSortedArrays(num1,num2)<<endl;
//    cout<< s.findMedianSortedArrays(a,4,b,4)<<endl;
}
