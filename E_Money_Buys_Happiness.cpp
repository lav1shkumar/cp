#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



void solve(){
    int m,x;cin>>m>>x;
    
    vector<pair<int,int>> v;

    int MAXI = 1;

    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
        MAXI+=b;
    }


    vector<int> dp(MAXI,LLONG_MAX);
    dp[0]=0;

    int ans=0;

    for(int i=0;i<m;++i){
        int c=v[i].first,h=v[i].second;

        for(int j=MAXI-h-1;j>=0;--j){
            if(dp[j]==LLONG_MAX) continue;
            
            if(dp[j]+c <= i*x){

                dp[j+h]=min(dp[j+h],dp[j]+c);
                
                ans=max(ans,j+h);
            }
        }

    }

    cout<<ans<<endl;

}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}