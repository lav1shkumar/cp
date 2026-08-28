#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,m;cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> s(n);
    for(int i=0;i<n;++i) cin>>s[i];

    vector<vector<int>> dp(n,vector<int> (n,LLONG_MAX));


    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;

    pq.push({0,0,0});
    dp[0][0]=0;

    while(!pq.empty()){
        auto [cost,node,idx] = pq.top();
        pq.pop();

        if(dp[node][idx]<cost) continue;

        for(auto [child,w]:adj[node]){
            int ncost1 = cost+w*s[idx];
            int ncost2 = cost+w*s[node];

            if(dp[child][idx]>ncost1){
                dp[child][idx]=ncost1;
                pq.push({ncost1,child,idx});
            }

            if(dp[child][node]>ncost2){
                dp[child][node]=ncost2;
                pq.push({ncost2,child,node});
            }

        }

    }

    int ans=LLONG_MAX;

    for(int i=0;i<n;++i) ans=min(ans,dp[n-1][i]);

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