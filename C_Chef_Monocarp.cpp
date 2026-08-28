#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
dp[i][j] = dp[i+1][j+1]+abs(i-j)
dp[i][j] = dp[i][j+1]

*/

int n;
vector<int> a;
vector<vector<int>> dp;


void solve(){
    cin>>n;

    a.assign(n,0);
    for(int i=0;i<n;++i) cin>>a[i];


    sort(a.begin(),a.end());

    dp.assign(n+1,vector<int> (2*n+2,INT_MAX));

    for(int j=1;j<=2*n+1;++j) dp[n][j]=0;

    for(int i=n-1;i>=0;--i){
        for(int j=2*n;j>0;--j){

            int ans = dp[i+1][j+1];
            if(ans!=INT_MAX) ans+=abs(a[i]-j);

            dp[i][j]=min(ans,dp[i][j+1]);
        }
    }

    cout<<dp[0][1]<<endl;

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