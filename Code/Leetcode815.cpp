#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int numBusesToDestination(vector< vector<int> > &routes, int S, int T) {
    if(S==T) return 0;
    bool visted[12312311]={false},took[12312311]={false};
    map< int, vector<int> > buses;
    queue<int> now_que,next_que;
    int ans=1;
    for(int i=0;i<routes.size();++i)
        for(int j: routes[i])
            buses[j].push_back(i);
    for(int i:buses[S]) took[i]=true,now_que.push(i);
    visted[S]=true;
    while(!now_que.empty())
    {
        while(!now_que.empty())
        {
            int cur_bus=now_que.front();
            now_que.pop();
            for(int i: routes[cur_bus])
            {
                if(i==T) return ans;
                if(visted[i]) continue;
                visted[i]=true;
                for(int bus: buses[i])
                {
                    if(took[bus]) continue;
                    next_que.push(bus);
                    took[bus]=true;
                }
                
            }
        }
        swap(now_que,next_que);
        ++ans;
    }
   return -1;
}
};