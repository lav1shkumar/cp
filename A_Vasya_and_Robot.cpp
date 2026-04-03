#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
LRLRLRLRLLLLLL
or
RLRLRLRLRRRR

if R>L R comes first, to min panelty




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,l,r,ql,qr; cin>>n>>l>>r>>ql>>qr;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<int> pref(n+1,0);
    for(int i=0;i<n;++i) pref[i+1]=pref[i]+a[i];



    int ans = LLONG_MAX;

    for(int L=0;L<=n;++L){
        int R = n-L;

        int energy = pref[L]*l + (pref[n]-pref[L])*r;

        if(R>L) energy+=(n-2*L-1)*qr;
        if(L>R) energy+=(2*L-n-1)*ql;

        ans=min(ans,energy);
    }

    cout<<ans<<endl;




}