#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
odd not poss
2 two's to one four
100/4 = 

*/


void solve(){
    int n;cin>>n;

    if(n&1){
        cout<<0<<endl;
        return;
    }

    cout<<(n/4)+1<<endl;

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