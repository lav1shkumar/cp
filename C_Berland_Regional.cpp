#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
group skill by uni, then prefix sum
i can use mod to see how much i need to take


*/


void solve(){
    int n;cin>>n;

    vector<int> u(n);
    vector<int> s(n);

    for(int i=0;i<n;++i) cin>>u[i];
    for(int i=0;i<n;++i) cin>>s[i];


    vector<vector<int>> bundle(n);

    for(int i=0;i<n;++i) bundle[u[i]-1].push_back(s[i]);


    for(auto &v:bundle){
        sort(v.rbegin(),v.rend());
    }

    // big to small now, i can do prefix sum
    // remain = size%k, total - this shit

    for(auto &v:bundle){
        int s=v.size();
        for(int i=1;i<s;++i){
            v[i]+=v[i-1];
        }
    }

    // 1 2 3 1 2 1 2
    vector<int> ans(n+1);

    for(auto &v:bundle){
        int s=v.size();
        for(int k=1;k<=s;++k){
            
            int idx = (s/k) * k;
            if(idx==0) continue;
            ans[k]+= v[idx-1];

        }

    
    }
    
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;


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