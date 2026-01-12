#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
no of flips == m/k;

last flip time remaining = m%k

after each flip remain sand = min(0,-m%k)


*/


void solve(){
    int s,k,m;cin>>s>>k>>m;
    int flips = m/k;
    int rem = m%k;

    int start;
    if(k>=s) start=s;
    else {
        if (flips%2==0) start=s;
        else start=k;
    }
    int ans = start - rem;
    if (ans<0) ans=0;
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