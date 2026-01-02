#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
n=8
a=[1,0,1,1,0,1,1,1]

either +3 or 4 in dp

waiti can also pick 1 or 2 hmmm


*/
vector<int> dp;
int points(int idx,vector<int> &bosses){
    if(idx>=bosses.size()) return 0;

    if(dp[idx]!=-1) return dp[idx];

    // p
    int minp = min(points(idx+3,bosses)+bosses[idx],points(idx+2,bosses)+bosses[idx]);
    
    if(idx!=bosses.size()-1){
        minp=min(points(idx+4,bosses)+bosses[idx]+bosses[idx+1],minp);
        minp=min(points(idx+3,bosses)+bosses[idx]+bosses[idx+1],minp);
    }

    return dp[idx]=minp;
}

void solve(){
    int n;cin>>n;
    vector<int> bosses(n);
    for(int i=0;i<n;++i) cin>>bosses[i];

    dp.assign(n,-1);

    cout << points(0,bosses) <<endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}