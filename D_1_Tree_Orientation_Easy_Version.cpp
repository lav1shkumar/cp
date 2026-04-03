#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




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

vector<bool> check;
vector<vector<int>> adj;

void dfs(int node){
    check[node]=1;
    for(int child:adj[node]){
        if(check[child]) continue;
        dfs(child);
    }
}


void solve(){
    int n;cin>>n;

    vector<string> t(n);

    for(int i=0;i<n;++i) cin>>t[i];

    vector<pair<int,int>> ans;

    vector<int> cnt(n,0);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
         if(t[i][j]=='1') cnt[i]++;
        }
    }


    vector<int> p(n);
    iota(p.begin(),p.end(),0);

    sort(p.begin(),p.end(),[&](int a,int b){
        return cnt[a]<cnt[b];
    });

    vector<int> cov(n,-1);

    for(int i=0;i<n;++i){
        for(int idx=n-1;idx>=0;--idx){
            int v=p[idx];

            if(i!=v && t[i][v]=='1'){

                if(cov[v]!=i){
                    ans.push_back({i,v});

                    if(ans.size()>=n){
                        cout<<"No\n";
                        return;
                    }
                    
                    for(int k=0;k<n;++k){
                        if(t[v][k]=='1') cov[k]=i;
                    }
                }
            }
        }
    }

    if(ans.size()!=n-1){
        cout<<"No\n";
        return;
    }
    DSU dsu(n);
    adj.assign(n,{});

    for(auto [u,v]:ans){
        dsu.unite(u,v);
        adj[u].push_back(v);
    }

    if(dsu.getSize(0)!=n){
        cout<<"No\n";
        return;
    }

    for(int i=0;i<n;++i){
        check.assign(n,0);
        dfs(i);

        for(int j=0;j<n;++j){
            char c = (check[j]?'1':'0');
            if(t[i][j]!=c){
                cout<<"No\n";
                return;
            }
        }
    }


    cout<<"Yes\n";

    for(auto [u,v]:ans){
        cout<<u+1<<" "<<v+1<<endl;
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