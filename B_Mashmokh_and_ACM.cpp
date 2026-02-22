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


    vector<int> ahead(n+1,0),cur(n+1,1);

    for(int i=0;i<k-1;++i){

        for(int j=1;j<=n;++j){
            for(int d=j;d<=n;d+=j){
                ahead[d]= (ahead[d] + cur[j])%MOD;
            }
        }
        cur=ahead;
        ahead.assign(n+1,0);
    }

    int ans=0;
    for(int i=1;i<=n;++i) ans=(cur[i]+ans)%MOD;

    cout<<ans<<endl;
}