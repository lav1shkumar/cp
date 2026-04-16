#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,k;cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];

    int t=accumulate(a.begin(),a.end(),0ll);

    if(t%2==0 && ((k*n)&1)){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    


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