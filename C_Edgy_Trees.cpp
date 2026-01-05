#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

1
|
|
2--------3

k==5, remove same ele == 3^5-3 == 3x1x1x1x1 == 3 choices first then one only
next if the seq consists of 2 and 3 only
22322 33222 32232 etc == 2x2x2x2x2 two options for all five == 2^5 + 1

3^5-2^5-1 == 210 Correct

i can use dsu, fins the distinct set of these red only nodes
if size of these nodes -- 3 , 4 === -3^k
but wait i have sutracted that fist case too, so lets do it later on after we know all the no
of edges present in dsu

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

    int getSize(int x) {
        return size[find(x)];
    }
};

long long binpow(long long a, long long b, long long mod) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) 
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n;cin>>k;

    DSU ds(n+1);

    for(int i=0;i<n;++i){
        int u,v,x;
        cin>>u;cin>>v;cin>>x;
        if(x==0) ds.unite(u,v);
    }
    // now we have red nodes sets
    vector<int> count(n+1,0);
    for(int i=1;i<=n;++i){
        int par = ds.find(i);
        count[par]++;
    }
    int minus = 0;
    int c=0;
    for(int val:count){
        if(val>1){
            c+=val;
            minus=(minus+binpow(val,k,MOD))%MOD;
        }
    }
    minus+=n-c;
    int total = (binpow(n,k,MOD)-minus+MOD)%MOD;
    cout << total <<endl;


}