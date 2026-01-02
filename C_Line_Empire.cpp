#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/

void solve(){
    int n,a,b;
    cin>>n;cin>>a;cin>>b;

    vector<int> kingdom(n+1);
    kingdom[0]=0;
    for(int i=0;i<n;++i) cin>>kingdom[i+1];

    vector<int> suffix(n+1);
    suffix[n]=kingdom[n];
    for(int i=n-1;i>=0;--i) suffix[i]=suffix[i+1]+kingdom[i];


    int mincost = LLONG_MAX;
    for(int i=0;i<=n;++i){
        int val=kingdom[i];
        
        int cost = i!=n ? (a+b)*val+b*(suffix[i+1]-(n-i)*val) : (a+b)*val;

        mincost=min(mincost,cost);

    }

    cout << mincost <<endl;




}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}