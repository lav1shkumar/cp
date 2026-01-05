#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
there must be even nodes overall
dfs, if size of subtree is even i can cut



*/
vector<vector<int>> adj;
int c = 0;

int dfs(int node,int par){
    int size=1;

    for(int child:adj[node]){
        if(child==par) continue;
        size+=dfs(child,node);
    }
    if(size%2==0) c++;
    //cout<<size<< " " << node << endl;
    return size;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    adj.assign(n+1,{});
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a=dfs(1,-1);
    if(a&1){
        cout<<-1<<endl;
    }
    else cout<<c-1<<endl;
}