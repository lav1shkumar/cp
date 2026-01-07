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


*/

int n;
vector<vector<int>> adj;
vector<int> depths;
int ans;

void dfs(int node,int par,int d){
    depths[d]++;
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

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=0;

    dfs(0,-1,1);

    int max_d = *max_element(depths.begin(),depths.end());
    cout << max(max_d,ans)<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}