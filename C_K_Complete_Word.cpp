#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
abaaba ---> as n%k==0, so any k segment should also be a palindrome
// can use dsu too 


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

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};

void solve(){
    int n,k;cin>>n;cin>>k;

    string str(n,0);
    for(int i=0;i<n;++i) cin>>str[i];

    DSU ds(n);

    for(int i=0;i<n;++i){
        int idx=i%k;
        ds.unite(idx,i);
    }
    int i=0,j=k-1;
    while(j>i) ds.unite(i++,j--);

    vector<vector<int>> freq(k,vector<int> (26,0));
    for(int i=0;i<n;++i){
        int p = ds.find(i);
        freq[p][str[i]-'a']++;
    }
    int count=0;
    for(auto it:freq){
        int maxf = 0;
        int size=0;
        for(int f:it){
            maxf=max(maxf,f);
            size+=f;
        }
        count+=size-maxf;
    }

    cout<<count<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}