#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
lets first find the row of n
1 2 3 4 5 6 7  
1+2+3+4>=9 so 9 is in 4th row

either one or 2 boxes above, one in the case of edge element
for row 4 last ele = n*(n+1)/2;
first ele = last-row+1;
if ele is = first or last then only single call, else double;

in case:
    first = go to first-(row-1)
    last = goto last-row
    else go to ele-row ans ele-row+1

due to memoization tc will be at max row == 2023 
So, 2023*(2023+1)/2 calls = 10^6
i will memoize this globally to furthur optimize 
*/

vector<int> dp,dpsum;
void run(){
    int maxr=2023,maxval=2023*(2024)/2;
    // 1 to 2023 rows
    dp.assign(maxval+1,0),dpsum.assign(maxval+1,0);
    dp[1]=1,dpsum[1]=1;

    int curr=2; // value
    for(int r=2;r<=maxr;++r){
        int prev = curr-r+1;
        for(int i=0;i<r;++i){
            dpsum[curr]= curr*curr + ((i>0)? dpsum[prev+i-1]:0); // added diag ele
            dp[curr] = dpsum[curr]+ ((i<r-1)? dp[prev+i] : 0);
            curr++;
        }
    }
}



void solve(){
    int n;cin>>n;
    cout<<dp[n]<<endl;
}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    int t; cin >> t;
    while(t--) solve();

}