#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

nc2 = n!/2x(n-2)!

n*(n-1)/2

ncr = n!/(n-r)!*r!

*/
int n,k;
vector<vector<int>> adj;
vector<int> cnt;
vector<int> fact;
int total;

int binexpo(int a,int b){
    a%=MOD;
    if(a==0) return 0;
    // a^b
    int res=1;
    int pow=a;

    while(b!=0){
        if(b&1){
            res=(res*pow)%MOD;
        }
        pow=(pow*pow)%MOD;

        b=b>>1;
    }

    return res;
}

int dfs(int node,int par){
    int s=1;

    for(int child:adj[node]){
        if(child==par) continue;
        s+=dfs(child,node);
    }

    return cnt[node]=s;
}


void calc(int node,int par){
    int up = cnt[node];
    int down = n-up;

    if(up>=k/2 && down>=k/2){
        int delta1 = (fact[up]*binexpo(fact[up-(k/2)]*fact[k/2],MOD-2))%MOD;
        int delta2 = (fact[down]*binexpo(fact[down-(k/2)]*fact[k/2],MOD-2))%MOD;
        
        total = (total+(delta1*delta2)%MOD)%MOD;
    }

    for(int child:adj[node]){
        if(child==par) continue;
        calc(child,node);
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

    cin>>n>>k;

    if(k&1){
        cout<<1<<endl;
        return 0;
    }

    adj.assign(n,{});
    cnt.assign(n,0);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fact.assign(n+1,1);
    for(int i=1;i<=n;++i) fact[i]=(fact[i-1]*i)%MOD;

    total=0;

    int tmp = dfs(0,-1);
    calc(0,-1);

    int denom = (fact[n]*binexpo(fact[n-k]*fact[k],MOD-2))%MOD;
    
    int ans=(1+total*binexpo(denom,MOD-2))%MOD;

    cout<<ans<<endl;

}