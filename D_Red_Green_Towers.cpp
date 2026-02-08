#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
for h, r+g => h(h+1)/2

now i have h,

dp[i][j] == no of ways to make tower of height i, with j red blocks

base case: dp[0][0]=1 dont do anything, dp[1][0]=1 use green one, dp[1][1] = 1 use red one

j red block = total-j green 
at some lvl i will use either i green or i red blocks, hmm
 
transition : dp[i][j] = dp[i-1][j-i] (red) + dp[i-1][j] (green) % mod
but 



*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r,g;cin>>r>>g;
    int h=1;
    int x=0;

    while(x+h<=r+g){
        x+=h;
        h++;
    }
    h--;

    vector<int> prev(r+1,0),curr(r+1,0);
    prev[0]=1;
    curr[0]=1;
    curr[1]=1;
    
    for(int i=1;i<=h;++i){
        for(int j=0;j<=r;++j){
            curr[j]= ((j>=i? prev[j-i] : 0) + prev[j]) % MOD;   
        }
        prev=curr;
    }

    int cnt=0;
    for(int i=0;i<=r;++i){
        if(h*(h+1)/2 -i <=g) cnt = (cnt + prev[i])%MOD;
    }

    cout<<cnt<<endl;
} 