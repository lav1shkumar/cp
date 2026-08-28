#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




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

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    sort(a.begin(),a.end());

    vector<vector<int>> dp(n+1,vector<int> (n+1,0));

    for(int len=2;len<=n;++len){

        for(int j=1;j<=n;++j){
            int i=j-len+1;

            if(i-1>=0){
                dp[i][j]=a[j-1]-a[i-1]+min(dp[i+1][j],dp[i][j-1]);
            }

        }

    }

    cout<<dp[1][n]<<endl;

}