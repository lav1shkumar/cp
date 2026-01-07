#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;


// Observations
/*




*/


void solve(){
    int n,m,d; cin>>n>>m>>d;

    vector<string> grid(n);
    for(int i=0;i<n;++i) cin>>grid[i];

    vector<vector<int>> dp(n,vector<int> (m,0)); // no of ways to reach i,j
    vector<int> pref(m,0);

    for(int i=0;i<m;++i){
        if(grid[n-1][i]=='X') dp[n-1][i]=1;
    }
    // in a single row i can move in colums
    // sqrt((r1 - r2)2 + (c1 - c2)2) == (ci-c2)^2<=d^2 = c1-c2<=d
    // for i row up diff == 1 , 1+(c1+c2)^2<=d^2 == c1+c2<=root(d^2-1)

    int max_dist = sqrt(d*d-1);
    pref[0]=dp[n-1][0];
    for(int j=1;j<m;++j) pref[j]=(pref[j-1]+dp[n-1][j])%MOD;
    for(int j=0;j<m;++j){
        //i-d to i+d
        if(grid[n-1][j]=='#') continue;
        int dis = d;
        int l=(j-dis-1)<0? -1:j-dis-1;
        int r=(j+dis)>=m? m-1:j+dis;
        if(l==-1) dp[n-1][j]=pref[r]%MOD; // stay on same row added
        else dp[n-1][j]=(pref[r]-pref[l]+MOD)%MOD;
    }

    pref[0]=dp[n-1][0];
    for(int j=1;j<m;++j) pref[j]=(pref[j-1]+dp[n-1][j])%MOD;

    // now for other rows up, i can come from max_dist distance from both sides

    for(int i=n-2;i>=0;--i){

        for(int j=0;j<m;++j){
            // ways to reach some i,j from prev pos rows;
            if(grid[i][j]=='#') continue;
            int dis = max_dist;
            int l=(j-dis-1)<0? -1:j-dis-1;
            int r=(j+dis)>=m? m-1:j+dis;
            if(l==-1) dp[i][j]=pref[r]%MOD;
            else dp[i][j]=(pref[r]-pref[l]+MOD)%MOD;
        }
        pref[0]=dp[i][0];
        for(int j=1;j<m;++j) pref[j]=(pref[j-1]+dp[i][j])%MOD;

        for(int j=0;j<m;++j){
            //i-d to i+d
            if(grid[i][j]=='#') continue;
            int dis = d;
            int l=(j-dis-1)<0? -1:j-dis-1;
            int r=(j+dis)>=m? m-1:j+dis;
            if(l==-1) dp[i][j]=pref[r]%MOD; 
            else dp[i][j]=(pref[r]-pref[l]+MOD)%MOD;
        }
        pref[0]=dp[i][0];
        for(int j=1;j<m;++j) pref[j]=(pref[j-1]+dp[i][j])%MOD;

    }
    cout<<pref[m-1]<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}