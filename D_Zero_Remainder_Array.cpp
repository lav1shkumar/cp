#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,k;cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<int> r(n);

    unordered_map<int,int> mp;

    for(int i=0;i<n;++i){
        int v = (a[i]%k);
        if(v==0) continue;

        v=k-v;
        r[i]=v;
        mp[r[i]]++;
    }

    int cnt=0,num=0;

    for(auto it:mp){
        int k = it.first;
        int v = it.second;
        
        if(v>cnt){
            cnt=v;
            num=k;
        }
        else if(v==cnt && k>num){
            num=k;
        }

    }

    if(cnt==0){
        cout<<0<<endl;
        return;
    }

    int ans = k*(cnt-1);
    ans+=(num+1);


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