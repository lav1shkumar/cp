#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

1 2 1 3 3 5 2 1 

0 1 0 1 0 1 0 0
0 0 1 0 0 0 1 1

maybe i need pref and suff,
want --- inc... peak ... dec
so just find peaks for both l and r
propogate?? then their peak must be at same idx


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<int> l(n),r(n);

    l[n-1]=n-1;
    for(int i=n-2;i>=0;--i){
        if(a[i]<=a[i+1]) l[i]=l[i+1];
        else l[i]=i;
    }

    r[0]=0;
    for(int i=1;i<n;++i){
        if(a[i]<=a[i-1]) r[i]=r[i-1];
        else r[i]=i;
    }

    // for(int i=0;i<n;++i) cout<<l[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;++i) cout<<r[i]<<" ";


    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        a--,b--;

        if(l[a]<r[b]) cout<<"No"<<endl;

        else cout<<"Yes"<<endl;

    }
}