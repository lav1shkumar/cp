#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
Sum |ai-bi| over all edges,
how will i maximize this??
diff must be larger == ai small bi large or vice versa

if i do small-- large-- small-- large , will it be optimal??
yep, is we increase some small, 
wait we can pick and l,r whichever giver bigger distance
any two edges, there are 4 assignments this way
two choices for a vertex

*/
vector<pair<int,int>> range;
vector<vector<int>> adj;

pair<int,int> dfs(int node,int par){
    int l=0;
    int r=0;

    for(int child:adj[node]){
        if(child==par) continue;
        auto res = dfs(child,node);
        // here i need to assign edges
        // check for all 4 combinations, but how?
        // dp[node][0]+=max(dp[child][0],dp[child][1]); also add distances

        l+=max((res.first+abs(range[node].first-range[child].first)),
            (res.second+abs(range[node].first-range[child].second)));

        r+=max((res.first+abs(range[node].second-range[child].first)),
            (res.second+abs(range[node].second-range[child].second)));

    }

    return {l,r};
}




void solve(){
    int n;cin>>n;

    range.assign(n,{});
    for(int i=0;i<n;++i) cin>>range[i].first>>range[i].second;

    adj.assign(n,{});
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    auto ans = dfs(0,-1);
    cout<<max(ans.first,ans.second)<<endl;
  
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