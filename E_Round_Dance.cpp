#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
so basically use dsu to find diff disjoint sets == max val
min ==? is size--2 can merge to one



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

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return; // already in same set

        // union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return;
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
    vector<int> arr(n);
    vector<int> st(n+1,0);
    for(int i=0;i<n;++i) cin>>arr[i];

    DSU ds(n+1);
    int cycles=0;
    for(int i=1;i<=n;++i) ds.unite(i,arr[i-1]);

    int sets=0;
    for(int i=1;i<=n;++i){
        int par = ds.find(i);
        if(st[par]==0){
            sets++;
            st[par]++;
        }
    }
    st.assign(n+1,0);
    int pairs = 0;
    for(int i=1;i<=n;++i){
        st[i]=arr[i-1];
        if(st[arr[i-1]]==i) pairs++;
    }
    sets-=pairs;
    //cout<<pairs<<" "<<sets<<endl;

    if(pairs>0) cout<<sets+1<<" "<<sets+pairs<<endl;
    else{
        cout<<sets<<" "<<sets<<endl;
    }


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