#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    inline void remove(string& s,int k){
        int match=0,curr=0,Begin=0;
        while(curr<s.size()){
            if(s[curr]==s[match]){
                if(curr-Begin+1==k){
                    s.erase(Begin,k);
                }
                ++curr;
            }
            else{
                match=curr;
                Begin=curr;
                ++curr;
            }
        }
       // cout<<s<<endl;
    }
    string removeDuplicates(string s, int k) {
        while(true){
            int len=s.size();
            remove(s,k);
            if(s.size()==len) return s;
        }
    }
};
int main(){
    Solution ss;
    cout<<ss.removeDuplicates("deeedbbcccbdaa",3);
    return 0;
}