#include<bits/stdc++.h>
using namespace std;
class Solution {
public:  
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int len1=nums1.size()-1;        
    int len2=nums2.size()-1;
    int i=0,j=0;
    while(i<=len1&&j<=len2) ans.push_back(nums1[i]<=nums2[j]?nums1[i++]:nums2[j++]);
    while(i<=len1) ans.push_back(nums1[i++]);
    while(j<=len2) ans.push_back(nums2[j++]);
    if(ans.size()%2==0)
    {
        int num=ans.size()-1;
        num/=2;
        return (double)(ans[num]+ans[num+1])/2;
    }
    else
    {
        int num=ans.size()-1;
        num/=2;
        return ans[num];
    }
    
}
};