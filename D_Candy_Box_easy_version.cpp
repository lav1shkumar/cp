#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    vector<int> a(n,0);

    for(int i=0;i<n;++i){
        int x;cin>>x;
        a[--x]++;
    }

    sort(a.rbegin(),a.rend());
    int ans=0;

    int prev=LLONG_MAX;


    for(int v:a){
        int delta=min(prev,v);
        
        if(delta<=0) break;

        ans+=delta;
        prev=delta-1;
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