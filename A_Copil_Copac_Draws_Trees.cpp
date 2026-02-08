#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
just brute force?

its gonna be n square, lets try
tle, lets optimize


wait if not in vis, then i need at least one other op
prev val depends on future one, maybe some dp solution
wait , depth? but it sdepends on the order, 
so if child is before parent then ++

*/
vector<vector<int>> adj;
map<pair<int,int>,int> order;
vector<int> dp;

void dfs(int node,int par){

    for(int child:adj[node]){
        if(child==par) continue;

        if(order[{node,child}]<=order[{par,node}]) dp[child]=dp[node]+1;
        else dp[child]=dp[node];

        dfs(child,node);
    }
}


void solve(){
    int n;cin>>n;
    adj.assign(n+1,{});

    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        order[{u,v}]=i;
        order[{v,u}]=i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.assign(n+1,0);

    order[{0,1}]= LLONG_MAX;
    order[{1,0}]= LLONG_MAX;

    dfs(1,0);

    int ans=0;

    for(int i=1;i<=n;++i){
        ans=max(ans,dp[i]);
    }

    cout<<ans<<endl;

}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}