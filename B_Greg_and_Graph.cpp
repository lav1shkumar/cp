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

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cin>>dp[i][j];
    }


    vector<int> nodes(n);
    for(int i=0;i<n;++i){
        cin>>nodes[n-1-i]; 
        nodes[n-1-i]--;
    }

    vector<int> curr;

    vector<int> res(n);

    for(int k=0;k<n;++k){
        int x=nodes[k];
        curr.push_back(x);

        int ans=0;

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][j]);
            }
        }
        for(int i:curr){
            for(int j:curr) ans+=dp[i][j];
        }

        res[n-1-k]=ans;
    }

    for(int v:res) cout<<v<<" ";

}