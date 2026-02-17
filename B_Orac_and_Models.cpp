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



    // recurrence = dp[i]= +1 over all factors if > that

    vector<int> dp(n+1,1);


    for(int i=1;i<=n;++i){

        for(int j=2*i;j<=n;j+=i){

            if(a[j-1]>a[i-1]){

                dp[j] = max(dp[j],dp[i]+1);
            }

        }

    }

    int ans = *max_element(dp.begin(),dp.end());

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