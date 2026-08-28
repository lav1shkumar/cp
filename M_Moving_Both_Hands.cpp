#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    vector<vector<pair<int,int>>> adj(2*n+1);

    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v+n].push_back({u+n,w});
    }

    for(int i=1;i<=n;++i){
        adj[i].push_back({i+n,0});
    }


    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    vector<int> dis(2*n+1,LLONG_MAX);
    dis[1]=0;

    while(!pq.empty()){
        auto [cost,node] = pq.top();
        pq.pop();

        if(cost>dis[node]) continue;

        for(auto [child,weight]:adj[node]){
            int ncost = cost+weight;

            if(dis[child]>ncost){
                dis[child]=ncost;
                pq.push({ncost,child});
            }

        }

    }


    for(int i=2;i<=n;++i){
        cout<<((dis[i+n]==LLONG_MAX)?-1:dis[i+n])<<" ";
    }

}