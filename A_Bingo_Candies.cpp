#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    unordered_map<int,int> mp;

    bool check=false;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int a;
            cin>>a;
            mp[a]++;
        }
    }

    for(auto [k,v]:mp){
        if(v>n*(n-1)) check = true;
    }
    if(check) cout<<"NO\n";
    else cout<<"YES\n";



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