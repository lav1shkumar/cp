#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/

vector<vector<int>> adj,ans;
vector<int> cnt;


bool dfs(int node,int par){

    vector<int> order;

    for(int child:adj[node]){
        if(child==par) continue;
        if(!dfs(child,node)) return false;

        order.insert(order.end(), ans[child].begin(), ans[child].end());
    }

    if(order.size()<cnt[node]) return false;

    order.insert(order.begin()+cnt[node],node);
    ans[node]=order;

    return true;
}



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    adj.assign(n+1,{});
    ans.assign(n+1,{});
    cnt.assign(n+1,0);

    int root=-1;
    for(int i=1;i<=n;++i){
        int par;cin>>par;
        int ci;cin>>ci;

        if(par==0) root=i;

        cnt[i]=ci;
        adj[par].push_back(i);

    }

    if(!dfs(root,0)){
        cout<<"NO"<<endl;
        return 0;
    }

    vector<int> order = ans[root];

    vector<int> res(n+1);
    for(int i=0;i<n;++i){
        res[order[i]]=i+1;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;++i) cout<<res[i]<<" ";

}