#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<vector<int>> adj;
vector<int> sum,cost,a,delta,depth;

void dfs(int node,int par,int dist){
    sum[node] = a[node];

    int maxi=0;

    for(int c:adj[node]){
        if(c==par) continue;
        dist++;

        dfs(c,node,dist);

        maxi=max(maxi,depth[c]);
        sum[node]+=sum[c];
        cost[node]+= cost[c] + sum[c];

    }
    depth[node]=maxi+1;
}

void dfs1(int node,int par){
    int max1=0,max2=0;

    for(int c:adj[node]){
        if(c==par) continue;
        if(depth[c]>max1){
            max2=max1;
            max1=depth[c];
        }
        else if(depth[c]>max2) max2=depth[c];
    }

    int max_d=0;
    for(int c:adj[node]){
        if(c==par) continue;
        
        int d = max1;
        if(depth[c]==max1) d=max2;

        dfs1(c,node);

        max_d=max({delta[c],d*sum[c],max_d});

        //cout<<c<<" "<<d<<endl;

    }
    delta[node] = max_d;

}


void solve(){
    int n;cin>>n;

    a.assign(n,0);
    for(int i=0;i<n;++i) cin>>a[i];

    adj.assign(n,{});
    sum.assign(n,0);
    cost.assign(n,0);
    delta.assign(n,0);
    depth.assign(n,0);
    
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }


    dfs(0,-1,0);
    dfs1(0,-1);

    for(int i=0;i<n;++i){
        cout<<delta[i]+cost[i]<<" ";
    }
    cout<<endl;

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