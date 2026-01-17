#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically common divisors will get +

3x1 + 5x1x2 == 1(3+5x2) = 1x13 

gcd of (a,b) = gcd(a,b-a)
gcd(a+x,b+x)== gcd(a+x,b-a) .. gcd(a+x,b-a,c-a......)
easy, just need differences

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
    vector<int> b(m);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];

    int first=a[0];
    int g=0;
    for(int i=1;i<n;++i){
        int d = abs(a[i]-first);
        g= gcd(g,d);
    }

    for(int v:b){
        int ans = gcd(g,first+v);
        cout<<ans<<" ";
    }
    cout<<endl;

}