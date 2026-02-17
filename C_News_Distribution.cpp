#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
simple dsu



*/
struct DSU{
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n);
        size.assign(n,1);

        for(int i=0;i<n;++i) parent[i]=i;
    }

    int find(int x){

        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];

    }

    void unite(int u,int v){
        u = find(u);
        v = find(v);

        if(u==v) return;

        if(size[u]<size[v]) swap(u,v);

        parent[v]=u;
        size[u]+=size[v];

    }

    int count(int x){
        return size[find(x)];
    }

};


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    DSU dsu(n+1);

    for(int i=0;i<m;++i){
        int s;cin>>s;
        if(s==0) continue;

        int f;cin>>f;

        for(int j=1;j<s;++j){
            int x;cin>>x;
            dsu.unite(f,x);

        }

    }

    for(int i=1;i<=n;++i) cout<< dsu.count(i) <<" ";
    cout<<endl;


}