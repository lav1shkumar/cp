#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
no pair in the range a to b should exist

lets say for some idx i, x subarray possible
i dont want any pair to be included so,
                                        i need biggest r till the idx, then l+1 to i all pos
                                        subnarrays
                                        btw, in pairs r>=l

                                        if r are same, i want bigger l first

basically there is a bound here, left bopund is monotonic, will only move right

*/


void solve(){
    int n,m;cin>>n>>m;

    vector<int> bound(n+1);

    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        if(v>u) swap(u,v);
        
        bound[u] = max(bound[u],v+1);
    }

    int cnt=0;
    int l=1;

    for(int i=1;i<=n;++i){
        int r=i;
        
        l = max(l,bound[i]);

        int n=r-l+1;
        cnt+=n;
        //cout<<l<<" "<<r<<endl;
    }

    cout<<cnt<<endl;


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