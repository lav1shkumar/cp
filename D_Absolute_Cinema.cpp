#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    vector<int> f(n+1);

    for(int i=1;i<=n;++i) cin>>f[i];

    if(n==2){
        cout<<f[2]<<" "<<f[1]<<endl;
        return;
    }
    
    vector<int> ans(n+1);

    for(int i=2;i<n;++i){
        ans[i] = (f[i-1]+f[i+1]-2*f[i])/2;
    }

    int cur=0;
    int a=0;
    for(int i=2;i<n;++i){
        cur++;
        a+=ans[i]*cur;
    }

    // f1 = a + an(n-1)
    ans[n] = (f[1] - a)/(n-1);
    a=0;
    cur=1;
    for(int i=3;i<=n;++i){
        a+=(ans[i]*cur);
        cur++;
    }

    ans[1] = f[2]-a;

    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
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