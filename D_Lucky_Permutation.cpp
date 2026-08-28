#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
3 4 1 2 - 1 4 3 2 - 1 2 3 4 and +1

2 4 3 1 = 1 4 3 2 = 1 2 3 4 and +1

*/
struct DSU{
    vector<int> size,parent;

    DSU(int n){
        size.assign(n+1,1);
        parent.assign(n+1,0);
        for(int i=0;i<=n;++i) parent[i]=i;

    }

    int find(int u){
        if(parent[u]==u) return u;

        return parent[u]=find(parent[u]);
    }


    void unite(int u,int v){
        int a=find(u),b=find(v);

        if(a==b) return;

        if(size[b]>size[a]) swap(a,b);

        size[a]+=size[b];
        parent[b]=a;

    }
};


void solve(){
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    DSU dsu(n);

    for(int i=1;i<=n;++i){
        dsu.unite(i,a[i-1]);
    }

    unordered_set<int> st;
    for(int i=1;i<=n;++i){
        int a = dsu.find(i);
        st.insert(a);
    }

    int cycles=st.size();

    int ans=INT_MAX;

    for(int i=1;i<n;++i){

        int a = dsu.find(i);
        int b = dsu.find(i+1);

        if(a==b){
            ans=min(ans,n-(cycles+1));
        }
        else{
            ans=min(ans,n-(cycles-1));
        }
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