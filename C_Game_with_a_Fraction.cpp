#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int MOD = 1e9+7;


// Observations
/*

p/q = 2/3  
10 14

closest = 8/12  
10-8 = 2 and 14-12 == 2

2+2 so alice can reduce one, bob can reduice other

so from 2/3 to any mul, if we have diff equal for both p and q, its possible

+2 +2 +2 for p
+3 +3 +3 for q

but p and q are 10^18

how can i efficiently do it?

bob win if q>p and 2k,3k is reachable = 2*q<=3*p




*/


void solve(){
    int p,q;cin>>p>>q;


    if(q>p && 2*q<=3*p) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;



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