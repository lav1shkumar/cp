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

    int n,m;cin>>n>>m;

    vector<vector<int>> grid(n,vector<int> (m));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cin>>grid[i][j];
    }

    vector<vector<int>> dp1(n+1,vector<int> (m+1,0));
    vector<vector<int>> dp2(n+1,vector<int> (m+1,0));
    vector<vector<int>> dpout1(n+1,vector<int> (m+1,0));
    vector<vector<int>> dpout2(n+1,vector<int> (m+1,0));

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+grid[i-1][j-1];
        }
    }

    for(int i=n-1;i>=0;--i){
        for(int j=1;j<=m;++j){
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+grid[i][j-1];
        }
    }


    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            dpout1[i][j]=max(dpout1[i+1][j],dpout1[i][j+1])+grid[i][j];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=m-1;j>=0;--j){
            dpout2[i][j]=max(dpout2[i-1][j],dpout2[i][j+1])+grid[i-1][j];
        }
    }

    
    int ans=0;

    for(int i=1;i<n-1;++i){
        for(int j=1;j<m-1;++j){

            int res=dp1[i][j+1]+dpout1[i+1][j]+dp2[i][j]+dpout2[i+1][j+1];
            res=max(res,dp1[i+1][j]+dpout1[i][j+1]+dp2[i+1][j+1]+dpout2[i][j]);
            ans=max(ans,res);
        }
    }


    cout<<ans;

}