#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
they can do like left..right until k
then reimu will catch her

n<4 ans == 1
so like == k+dis?




*/


void solve(){
    int n,x1,x2,k;cin>>n>>x1>>x2>>k;

    int dis = abs(x2-x1);


    if(n<4) cout<<1<<endl;

    else cout<<min(dis,n-dis)+k<<endl;


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