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

    int n,d;cin>>n>>d;

    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];


    int ans=0;
    int j=0;

    for(int i=0;i<n;++i){

        while(j<n && v[j]-v[i]<=d) j++;


        // i , 2 from i+1 to j-1 
        int range = j-i-1;

        if(range<2) continue;

        ans+=range*(range-1)/2;

    }

    cout<<ans<<endl;
}
