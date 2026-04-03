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

    int n,k;cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];


    sort(a.rbegin(),a.rend());

    int ans=a[0];
    int l=0,cost=0;
    int freq=1;

    for(int r=1;r<n;++r){
        cost+= a[l]-a[r];

        while(cost>k){
            int d = a[l]-a[l+1];
            l++;
            int len = r-l+1;

            cost-=d*len;
        }

        int len = r-l+1;
        if(len>=freq){
            freq=len;
            ans=a[l];
        }


    }

    cout<<freq<<" "<<ans<<endl;

}