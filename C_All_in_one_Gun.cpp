#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
we need max damage at start for optimal swap

prefix suffix swap= origional + max suf - min pref


*/


void solve(){
    int n,h,k;cin>>n>>h>>k;
    vector<int> arr(n);

    for(int i=0;i<n;++i) cin>>arr[i];

    int t = accumulate(arr.begin(),arr.end(),0ll);

    vector<int> suff(n+1,-1);
    for(int i=n-1;i>=0;--i) suff[i]=max(suff[i+1],arr[i]);


    int ans = LLONG_MAX;
    int sum=0;
    int pref_min=LLONG_MAX;

    for(int i=1;i<=n;++i){
        sum+=arr[i-1];

        pref_min = min(pref_min,arr[i-1]);

        int delta = 0;

        if(i<n){
            if(suff[i]>pref_min){
                delta = suff[i]-pref_min;
            }
        }

        int l = sum + delta;

        int remain = max(0ll,h-l);

        int cnt = (remain + t-1)/t;

        ans=min(ans,cnt*(n+k)+i);

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