#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
bs? for time t, is it possible to complete?





*/
unordered_map<int,int> mp;
int n,m;
bool check(int t){
    int total=0;
    for(int i=1;i<=n;++i){
        if(mp[i]>t) total+=t;
        else total += min(t,mp[i]+(t-mp[i])/2);
    }    

    return total>=m;

}

void solve(){
    cin>>n>>m;
    mp.clear();
    
    for(int i=0;i<m;++i){
        int x;cin>>x;
        mp[x]++;
    }

    int l=1,r=2*m+1;
    int ans;
    while(r>=l){
        int mid=(l+r)/2;

        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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