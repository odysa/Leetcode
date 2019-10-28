#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();//第一个大于等于target的元素
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin();//第一个大于target的元素
        if(y==x) return {-1,-1};
        return {x,y-1};   
    }
};
int main(){
    return 0;
}