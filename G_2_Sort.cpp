#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,k;cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    
    int cnt=0,ans=0;


    for(int i=0;i<k;++i){
        if(arr[i] < 2*arr[i+1]) cnt++;
    }

    int l=0;
    for(int r=k;r<n-1;++r){
        if(cnt==k) ans++;

        if(arr[l]<2*arr[l+1]) cnt--;
    
        if(arr[r]<2*arr[r+1]) cnt++;

        l++;

    }
    if(cnt==k) ans++;

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