#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }

        return true;
    }
};



void solve(){
    int n,m,k;cin>>n>>m>>k;

    
    vector<tuple<int,int,int>> edges;

    int close=INT_MAX;

    for(int i=0;i<m;++i){
        int u,v,x;cin>>u>>v>>x;
   
        close=min(close,abs(k-x));

        edges.push_back({x,u,v});
    }

    sort(edges.begin(),edges.end());

    DSU dsu(n+1);

    int ans=0;

    for(auto [x,u,v]:edges){
        if(dsu.unite(u,v)){
            if(x>k) ans+=x-k;
        }
    }

    if(ans==0) ans=close;

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