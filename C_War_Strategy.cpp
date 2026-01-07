#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
two dirs, 
7 7 4 == . . . (.) . . . 
         . X X X X X X or X X X X X X . in svn days
assymetric case:
    try both sides


*/

int count(int a, int b, int m) {
    int maxi = 0;
    for (int x = 0; x <= a; ++x) {
        int min_d = (x==0? 0:2*x - 1);
        
        if (min_d>m) break;
        
        int t = (m + x-1) / 2;
        t = max(t,min_d);
        if (t>m) t = m;

        int r = m-t;
        int temp = (t+1)-x;
        int y = min({b,r,temp});
        
        if (y < 0) y = 0;
        maxi = max(maxi,x+y+1);
    }
    return maxi;
}

void solve(){
    int n,m,k; cin>>n>>m>> k;

    int l = k-1;
    int r = n-k;

    cout << max(count(l,r,m),count(r,l,m))<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}