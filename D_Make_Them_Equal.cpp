#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
at max i can double by picking x==1

1 -- 2 -- 4 -- 8 -- 16 -- 32   
so min op to make 1 to b: 
                            2^k>=b, min k
                            basically i can convert one to any number
                            i need to left shift one to make it equal to msb of b

                            so steps will be -- msb idx + popcount - 1

                            1--2--4--8-- i can add 1,2,4,8 to 8 in one c
                            msb + popcnt - 1 == steps needed

Wrong shit! lmao
just brute force steps
b is till 10^3, i can precalculate this

dp[i] = min(dp[i],dp[i-(i/x)]) , x from 1 to i

*/
vector<int> dp;
void run(){
    dp[1]=0;

    for(int i=1;i<1001;++i){
        for(int j=1;j<=i;++j){
            int p=i+(i/j);
            if(p<1001) dp[p]=min(dp[p],dp[i]+1);
        }
    }
}

void solve(){
    int n,k;cin>>n>>k;

    vector<int> c(n);
    vector<int> b(n);
    for(int &i:b) cin>>i;
    for(int &i:c) cin>>i;

    vector<int> steps(n);
    for(int i=0;i<n;++i){
        steps[i]=dp[b[i]];
    }

    // now i have steps needed, i need to maximize costs and min steps
    // i can do knapsack here
    // step can be at max 12 for 1001
    // max weight == 12*n == kmax
    // dp transition = dp[idx][w] = max(dp[idx-1][w],dp[idx-1][w-steps]+cost)
    vector<int> prev(12*n+1,0);
    vector<int> curr(12*n+1,0);

    for(int i=0;i<n;++i){
        int v=steps[i],cost=c[i];
        for(int j=0;j<=12*n;++j){
            if(j>=v) curr[j]=max(prev[j],prev[j-v]+cost);
        }
        prev=curr;
    }
    int x = min(k,12*n);
    cout<<prev[x]<<endl;
}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp.assign(1001,LLONG_MAX);
    run();
    int t; cin >> t;
    while(t--) solve();

}