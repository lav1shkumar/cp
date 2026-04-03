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

    if(n*(n-1)/2 < k+1){
        cout<<"no solution\n";
        return 0;
    }


    int cnt=0;
    for(int i=0;i<n;++i){
        if(cnt==n) break;
        for(int j=0;j<n;++j){
            if(cnt==n) break;
            cout<<i<<" "<<j<<endl;          
            cnt++;
        }
    }

    return 0;

}