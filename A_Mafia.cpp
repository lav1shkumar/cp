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

    int t = accumulate(a.begin(),a.end(),0ll);
    int maxi = *max_element(a.begin(),a.end());

    int l=0,r=t;

    int ans=0;

    while(r>=l){
        int m = (l+r)/2;

        if(m*(n-1)>=t){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }

    cout<<max(ans,maxi)<<endl;
}