#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;
    cin>>n;

    vector<int> seq(n);
    vector<int> dp(n+1);
    dp[n-1] =1;
    for(int i=0;i<n;++i) cin>>seq[i];
    for(int i=n-2;i>=0;--i){
        int val = seq[i];
        int jump = i+val+1;

        if(jump>n) dp[i]=dp[i+1]+1;
        else dp[i]=min(dp[i+1]+1,dp[jump]);

    }

    cout << dp[0] << endl;


    

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}