#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically degree==2
and graph should be 2 coulorable

cycle length == even

*/
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false; // already in same set

        // union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

void solve(){
    int n;cin>>n;
    vector<int> cnt(n+1);
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;++i){
        int a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
        arr[i]={a,b};
    }
    for(int i=1;i<=n;++i){
        if(cnt[i]!=2){
            cout<<"NO"<<endl;
            return;
        }
    }

    DSU dsu(n+1);

    for(auto [u,v]:arr){
        dsu.unite(u,v);
    }

    for(int i=1;i<=n;++i){
        int p=dsu.find(i);
        if(dsu.size[p]&1){
            cout<<"NO"<<endl;
            return;
        }

    }

    cout<<"YES"<<endl;
    
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