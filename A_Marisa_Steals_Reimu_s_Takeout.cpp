#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];


    int zero=0,one=0,two=0;
    for(int v:a){
        if(v==0) zero++;
        else if(v==1) one++;
        else two++;

    }

    int common=min(one,two);
    one-=common;
    two-=common;

    int ans = zero+common+one/3+two/3;

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