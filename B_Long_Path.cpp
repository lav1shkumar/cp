#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<int> a;
int n;

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    a.assign(n,0);

    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]--;
    }

    vector<int> dp(n+1,0);


    for(int i=0;i<n;++i){
        dp[i+1]= (dp[i]+1 + (dp[i]-dp[a[i]]+MOD)%MOD + 1)%MOD;
    }


    cout<<dp[n];

}
