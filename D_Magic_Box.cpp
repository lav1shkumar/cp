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

    int p1,p2,p3;cin>>p1>>p2>>p3;
    int x,y,z;cin>>x>>y>>z;

    vector<int> v(6);
    for(int i=0;i<6;++i) cin>>v[i];

    int ans=0;

    if(p1>x) ans+=v[5];
    if(p1<0) ans+=v[4];

    if(p2>y) ans+=v[1];
    if(p2<0) ans+=v[0];

    if(p3>z) ans+=v[3];
    if(p3<0) ans+=v[2];


    cout<<ans<<endl;
}