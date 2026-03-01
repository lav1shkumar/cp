#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int n;
vector<int> a(n),b(n);
vector<vector<int>> dp;

int ans(int idx,int prev){
    
    if(idx>=n) return 0;

    if(dp[idx][prev]!=-1) return dp[idx][prev];

    int res=0;

    if(prev==0){
        res=max(ans(idx+1,1)+a[idx],res);
        res=max(ans(idx+1,2)+b[idx],res);
    }
    else if(prev==1){
        res=max(ans(idx+1,0),res);
        res=max(ans(idx+1,2)+b[idx],res);
    }
    else{
        res=max(ans(idx+1,0),res);
        res=max(ans(idx+1,1)+a[idx],res);
    }

    return dp[idx][prev]=res;
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

    a.assign(n,0);
    b.assign(n,0);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];

    dp.assign(n,vector<int> (3,-1));

    cout<<ans(0,0)<<endl;

}