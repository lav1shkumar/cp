#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

j - i = a[j] - a[i]

j - a[j]  = i - a[i]

*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    vector<int> b(n);

    for(int i=0;i<n;++i) cin>>b[i];

    vector<int> dp(n,0);
    for(int i=0;i<n;++i) dp[i] = b[i]-i;

    unordered_map<int,int> mp;

    for(int i=0;i<n;++i){
        mp[dp[i]]+=b[i];
    }

    int ans=0;
    for(auto it:mp){
        ans=max(ans,it.second);
    }


    cout<<ans<<endl;


}