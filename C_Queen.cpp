#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<vector<int>> adj;
vector<bool> node,ans;

void dfs(int n,int p){
    bool found=true;

    for(int c:adj[n]){
        if(c==p) continue;
        if(!node[c]) found=false;

        dfs(c,n);
    }

    if(node[n] && found) ans[n]=1;

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
    node.assign(n+1,0);
    ans.assign(n+1,0);

    
    int root;
    for(int i=1;i<=n;++i){
        int p,c;cin>>p>>c;

        if(p==-1){
            root=i;
            continue;
        }

        node[i]=c;

        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    dfs(root,-1);
    
    bool found=false;
    for(int i=1;i<=n;++i){
        if(ans[i]){
            cout<<i<<" ";
            found=true;
        }
    }

    if(!found) cout<<-1;
}