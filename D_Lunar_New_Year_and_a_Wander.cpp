#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i have to traverse all nodes, lowest num possible first
can i do bfs and go with the smallest number first, hmmm
use a min heap maybe, also pust the visited edges somewhere

*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n;cin>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;++i){
        int u,v;cin>>u;cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,0);
    vis[1]=1;
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(1);

    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        cout << node << " ";
        for(int child:adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                pq.push(child);
            }
        }
    }
    cout<<endl;



}