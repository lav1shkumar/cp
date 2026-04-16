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

    int r,g,b;cin>>r>>g>>b;

    vector<int> v;
    v.push_back(r);
    v.push_back(g);
    v.push_back(b);

    sort(v.rbegin(),v.rend());
    
    int t = r+g+b;


    cout<<min(t/3,v[1]+v[2])<<endl;

}