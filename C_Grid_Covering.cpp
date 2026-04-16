#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
so basically can he cover all the paths in like circular movement
depends on n,a and m,b

when its not pos: if they have like common div
so gcd must be 1

also alternate: so, like +a and +b ...
0,0 a,b 2a,2b, 3a,3b --- lcm m,n
0,b a,2b 2a,3b ...  -- lcm m,n ---> 2x lcm m,n >= mxn

2*mxn/gcd>=mxn
gcd<=2 


*/


void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    if(gcd(n,a)==1 && gcd(m,b)==1 && gcd(n,m)<=2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


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