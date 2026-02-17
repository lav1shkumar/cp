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


    vector<int> pos(n+1,0),neg(n+1,0);

    for(int i=1;i<=n;++i){

        if(a[i-1]<0){
            pos[i] = neg[i-1];
            neg[i] = pos[i-1]+1;
        }

        else{
            pos[i] = pos[i-1]+1;
            neg[i] = neg[i-1];
        }

    }

    int ans = accumulate(pos.begin(),pos.end(),0ll);

    cout<<1ll*n*(n+1)/2 - ans << " "<<ans<<endl;

}