#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

1 2 3 1 2 1 4 1 2 1 3 1 2 1 5

basically at every 2^pow, ans+=ans+1;
rest i can iterate, but this can tle too

i can look at maximum set bit, and do these operations
then another set bit and so on

*/
int run(int x){
    int ans=1;
    while(x--){
        ans+=(ans+1);
    }
    return ans;

}

void solve(){
    int n;cin>>n;

    int ans=0;
    for(int b=60;b>=0;--b){
        if(n&(1ll<<b)) ans+=run(b);
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