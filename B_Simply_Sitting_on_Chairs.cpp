#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

4
4 2 1 3
1 2 3 4

now, if perm>c, then it blocks at least one move, so its bad
only sit id c>=perm

*/


void solve(){\
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    int cnt=0;

    for(int i=1;i<=n;++i){
        if(a[i-1]<=i) cnt++;
    }

    cout<<cnt<<endl;

}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}