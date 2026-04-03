#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
we can check for prefix and suffix
then try adding both pref[i]+suff[i+1]



*/
int n,h;


void solve(){
    cin>>n>>h;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<vector<int>> water(n,vector<int> (n,0));

    for (int i=0;i<n;++i){
        int v = a[i];

        for (int j=i;j<n;++j){
            v = max(v,a[j]);
            int val = max(0ll,h-v);

            water[i][j] = val;
            water[j][i] = val;
        }

    }

    vector<int> pref(n,0);
    
    for(int i=0;i<n;++i){
        int s=0;

        for(int j=0;j<i;++j) s+=water[i][j];

        for(int j=i;j<n;++j){
            s+=water[i][j];
            pref[j] = max(pref[j],s);
        }

    }

    vector<int> suff(n,0);
    
    for(int i=n-1;i>=0;--i){
        int s=0;

        for(int j=n-1;j>i;--j) s+=water[i][j];

        for(int j=i;j>=0;--j){
            s+=water[i][j];
            suff[j] = max(suff[j],s);
        }

    }

    int ans=0;

    for(int i=0;i<n;++i){
        int curr = pref[i] + ((i<n-1)?suff[i+1]:0);
        ans=max(ans,curr);
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