#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<int> a;
int n;

int dfs(int i,bool flag,vector<vector<int>> &dp){
    if(i<-1 || i>=n) return 0;

    if(i==-1) return -1;

    if(dp[i][flag]==-3) return -1;

    if(dp[i][flag]!=-2) return dp[i][flag];

    int val=a[i];

    int ans=0;

    dp[i][flag]=-3;


    if(flag){
        int ret = dfs(i-val,!flag,dp);
        if(ret==-1) return dp[i][flag]=-1;
        ans=ret+val;
    }
    else{
        int ret = dfs(i+val,!flag,dp);
        if(ret==-1) return dp[i][flag]=-1;
        ans=ret+val;
    }


    return dp[i][flag]=ans;
}



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    n--;

    a.assign(n,0);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<vector<int>> dp(n,vector<int>(2,-2));

    for(int i=0;i<n;++i){
        if(dfs(i,1,dp)==-1){
            cout<<-1<<endl;
        }
        else cout<<dfs(i,1,dp)+i+1<<endl;
    }


}