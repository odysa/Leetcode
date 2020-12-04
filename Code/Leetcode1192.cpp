#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    int dfn[101000],low[101000],num=0;
    struct Edge{
        int v;
        int next;
    }edges[600000];
    int tot=0,First[101000];
    inline void addEdge(int x,int y)
    {
        edges[++tot].next=First[x];
        edges[tot].v=y;
        First[x]=tot; 
    }
    void tarjan(int u,int father)
    {
        dfn[u]=low[u]=++num;
        for(int i=First[u];i;i=edges[i].next)
        {
            int v=edges[i].v;
            if(!dfn[v])
            {
                tarjan(v,u);
                int w=low[v];
                low[u]=low[u]>w?w:low[u];
                if(w>dfn[u]) ans.push_back({u,v});
            }
            else if(v!=father) low[u]=low[u]>dfn[v]?dfn[v]:low[u];
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connesctions) {
        memset(dfn,0,sizeof(dfn));
        memset(First,0,sizeof(First));
        for(int i=0;i<connesctions.size();++i)
        {
            addEdge(connesctions[i][0],connesctions[i][1]);
            addEdge(connesctions[i][1],connesctions[i][0]);
        }
        for(int i=0;i<n;++i) if(!dfn[i]) tarjan(i,i);
        return ans;
    }
};
int main()
{
    //cout<<"yes";
    vector<vector<int>> input={{0,1},{1,2},{2,0},{1,3}};
   // cout<<input.size();
    Solution oo;
    vector<vector<int>> ans=oo.criticalConnections(4,input);
    cout<<ans.size();
    //for(int i=0;i<ans.size();++i) cout<<ans[i][0]<<ans[i][1]<<endl;
    return 0;
}