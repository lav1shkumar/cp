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

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];


    unordered_map<int,int> mp;

    int ans=0;


    for(int i=0;i<n;++i){
        int val=a[i];

        vector<int> div;
        for(int j=2;j*j<=val;++j){
            if(val%j==0){
                div.push_back(j);
                if(j*j!=val) div.push_back(val/j);
            }

        }

        if(val!=1) div.push_back(val);

        int optimal=0;

        for(auto d:div){
            if(mp.find(d)==mp.end()) continue;
                
            optimal=max(optimal,mp[d]);
        }
        
        for(auto d:div){
            mp[d]=max(mp[d],optimal+1);
        }

        ans=max(ans,optimal+1);

    }

    cout<<ans<<endl;



}
