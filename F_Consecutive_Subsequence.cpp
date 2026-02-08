#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
dp[i]= max(dp[i],dp[i-1]+1);

1  2  5  2   5
using last 5 is always better

i can use map here

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
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];


    unordered_map<int,int> dp;
    int maxiNum=0;
    int maxilen=0;
    for(int i=0;i<n;++i){
        dp[arr[i]] = max(dp[arr[i]],dp[arr[i]-1]+1);

        if(dp[arr[i]]>maxilen){
            maxilen=dp[arr[i]];
            maxiNum=arr[i];
        }
    }

    cout<<maxilen<<endl;

    vector<int> ans;
    for(int i=n-1;i>=0;--i){
        if(maxiNum==arr[i]){
            ans.push_back(i+1);
            maxiNum--;
        }
    }

    for(int i=ans.size()-1;i>=0;--i) cout<<ans[i]<<" ";
    cout<<endl;


}