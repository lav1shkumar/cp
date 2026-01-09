#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
okay, so distance is basically depth
set S has ---  no node same dis to root
               no two nodes are connected by edge

and color
min operation to color all edges

          1
    2  3    4  5

    then it will take 5 op to make them black

so i cannot pick element at same delph
if there are x element at some depth then op==max(x) at all depths
also parent child cant be in the same set
but at same depth par can be diff

if 1par + xchild == x+1 diff set required
so ans == max of these two consition

for assignment, use lvl order traversal
ans try to assign numbers from 0 to ans-1

use mod to propogate parent in lvl order
*/

int n;
vector<vector<int>> adj;
vector<int> depths;
vector<int> parent;
vector<vector<int>> level;
int ans;

void dfs(int node,int par,int d){
    depths[d]++;
    parent[node]=par;
    level[d].push_back(node);
    int kids=0;
    for(int child:adj[node]){
        if(child==par) continue;
        kids++;
        dfs(child,node,d+1);
    }
    ans = max(ans, kids+1);
}


void solve(){
    int n;cin>>n;
    
    adj.assign(n,{});
    depths.assign(n+1,0);
    parent.assign(n,-1);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=0;

    level.assign(n,{});
    dfs(0,-1,0);
    int max_d = *max_element(depths.begin(),depths.end());
    ans=max(max_d,ans); // 0 1 2 ... maxi-1



    vector<int> order(n,-1);
    order[0]=0;  // root is a part of 1st set
    for(int i=1;i<n;++i){
        set<int> st;
        int x =level[i].size();
        for(int i=0;i<=x;++i) st.insert(i); //+1 for par

        for(int j=0;j<x;++j){
            order[level[i][(j+1)%x]] = order[parent[level[i][j]]];
            st.erase(order[parent[level[i][j]]]);
        }

        for(int node:level[i]){
            if(order[node]==order[parent[node]]){
                order[node]=*st.begin();
                st.erase(st.begin());
            }
        }
    }
    vector<vector<int>> res(ans);
    for(int i=0;i<n;++i){
        res[order[i]].push_back(i+1);
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;++i){
        int s=res[i].size();
        cout<<s<<" ";
        for(int val:res[i]) cout<<val<< " ";
        cout<<endl;
    }

    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}