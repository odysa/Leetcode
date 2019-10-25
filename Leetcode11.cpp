#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx=-123123123;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            if((right-left)*min(height[left],height[right])>maxx) maxx=(right-left)*min(height[left],height[right]);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return maxx;
    }
};