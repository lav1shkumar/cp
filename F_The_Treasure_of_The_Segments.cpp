#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    vector<pair<int,int>> v(n);
    vector<int> f(n),s(n);

    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
        f[i]=v[i].first;
        s[i]=v[i].second;
    }

    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    int ans=n;

    for(auto [x,y]:v){
        int r = upper_bound(f.begin(),f.end(),y)-f.begin();

        int l = lower_bound(s.begin(),s.end(),x)-s.begin();
        l--;

        ans=min(ans,(n-r)+l+1);

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