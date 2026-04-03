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

    vector<int> basis;

    for(int v:a){

        for(int b:basis){
            v=min(v,v^b);
        }

        if(v!=0) basis.push_back(v);

    }


    int ans=0;

    for(int b:basis){
        if((ans^b) > ans) ans^=b;
    }

    cout<<ans<<endl;

}