#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    vector<int> gap(n+1,0);
    vector<int> last_pos(n+1,-1);
    for(int i=0;i<n;++i) cin>>arr[i];

    for(int i=0;i<n;++i){
        int l=last_pos[arr[i]];
        gap[arr[i]]= max(gap[arr[i]],i-l);
        last_pos[arr[i]]=i;
    }
    for(int i=0;i<n;++i){
        int l=last_pos[arr[i]];
        gap[arr[i]]= max(gap[arr[i]],n-l);

    }
    unordered_map<int,int> mp;
    for(int i=1;i<=n;++i){
        if(mp.find(gap[i])!=mp.end()) continue;
        mp[gap[i]] = i;
    }
    int prev=LLONG_MAX;
    for(int gap=1;gap<=n;++gap){
        if(mp.find(gap)!=mp.end()) prev=min(prev,mp[gap]);

        cout << (prev==LLONG_MAX? -1:prev) << " ";

    }
    cout<<endl;



}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}