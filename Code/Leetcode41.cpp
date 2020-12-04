#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minn=2147483647;
        int num=0;
        for(int x:nums){
            if(x>0&&x<=nums.size()){
                ++num;
                minn=minn>x?x:minn;
            }
        }
        if(minn!=1) return 1;
        bool check[num+1];
        memset(check,0,sizeof(check));
        for(int x:nums){
            if(x>0&&x<=num){
                check[x-1]=1;
            }
        }
        for(int i=0;i<=num;++i){
            if(!check[i]) return i+1;
        }
        return 1;
    }
};
