#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int n,m;
string s1,s2;

vector<vector<int>> dp;

int solve(int i,int j){
    if(i==n || j==m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;

    if(s1[i]==s2[j]) ans=max(ans,solve(i+1,j+1)+2);

    ans=max(ans,solve(i+1,j)-1);
    ans=max(ans,solve(i,j+1)-1);

    return dp[i][j]=ans;

}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin>>s1>>s2;

    dp.assign(n,vector<int> (m,-1));

    int ans = solve(0,0);
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) ans=max(ans,dp[i][j]);
    }
    
    cout<<ans;
}