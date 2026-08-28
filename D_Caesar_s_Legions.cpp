#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e8;


// Observations
/*




*/
int n1,n2,k1,k2;

int dp[101][101][2];

int solve(int a1,int a2,bool prev){
    if(a1==n1 && a2==n2) return 1;
    if(a1>n1 || a2>n2) return 0;

    if(dp[a1][a2][prev]!=-1) return dp[a1][a2][prev];

    int ans=0;

    if(prev){
        for(int i=1;i<=k1;++i){
            ans=(ans+solve(a1+i,a2,0))%MOD;
        }
    }
    else{
        for(int j=1;j<=k2;++j){
            ans=(ans+solve(a1,a2+j,1))%MOD;
        }
    }
    
    return dp[a1][a2][prev]=ans;
}



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n1>>n2>>k1>>k2;

    memset(dp,-1,sizeof(dp));
    int ans=solve(0,0,0);

    memset(dp,-1,sizeof(dp));
    ans=(ans+solve(0,0,1))%MOD;

    cout<<ans<<endl;
}