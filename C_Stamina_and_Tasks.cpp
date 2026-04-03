#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int MOD = 1e9+7;


// Observations
/*

just make max of e or e*(1-....)


*/

void solve(){
    int n;cin>>n;
    vector<pair<ld,ld>> a(n);

    for(int i=0;i<n;++i) cin>>a[i].first>>a[i].second;

    ld ans=0;

    for(int i=n-1;i>=0;--i){
        auto [x,y] = a[i];
        ans=max(ans,x+ans*(1-y/100));

    }

    cout<<fixed<<setprecision(10)<<ans<<endl;
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