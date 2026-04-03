#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

5 3 5 3 4 == 5 5 3 == 5 5 == 5 == 5

3 3 4 5 4 == 

8,4  6,3  5,5  = 8+

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

    int a[100002]={0};
    int maxi=100001;
    
    for(int i=0;i<n;++i){
        int x;cin>>x;
        a[x]++;
    }

    int ans=0;
    int dp[maxi+1]={0};
    dp[1]=a[1];

    for(int i=2;i<=maxi;++i){
        dp[i] = max(dp[i-1],dp[i-2]+a[i]*i);
    }
 

    cout<<dp[maxi]<<endl;

}