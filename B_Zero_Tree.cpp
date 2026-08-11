#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/

vector<int> v;
vector<vector<int>> adj;

pair<int,int> dfs(int node,int par){
    pair<int,int> res = {0,0};

    for(int child:adj[node]){
        if(child==par) continue;
        auto x = dfs(child,node);

        res.first=max(res.first,x.first);
        res.second=max(res.second,x.second);
    }

    int remain = v[node]+res.first-res.second;

    if(remain>0) res.second+=remain;
    else res.first-=remain;

    //cout<<res.first<<" "<<res.second<<" "<<node<<endl;

    return res;
}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    adj.assign(n,{});
    v.assign(n,0);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;++i) cin>>v[i];


    auto ans = dfs(0,-1);

    cout<<ans.first+ans.second;

}