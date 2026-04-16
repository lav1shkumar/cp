#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
we want sum=n
1 2 3 4 5 6 ... k numbers

at least one number >=d

no of ways, thats the problem

dp state? = sum,max,



*/

int n,k,d;
int dp[101][101];

int solve(int sum,int maxi){
    if(sum>n) return 0;

    if(sum==n && maxi>=d) return 1;

    if(dp[sum][maxi]!=-1) return dp[sum][maxi];

    int cnt=0;

    for(int i=1;i<=k;++i){
        cnt = (cnt + solve(sum+i,max(maxi,i)))%MOD;
    }

    return dp[sum][maxi]=cnt;

}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>n>>k>>d;

    memset(dp,-1,sizeof(dp));

    cout<<solve(0,0)<<endl;


}