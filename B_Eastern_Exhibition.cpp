#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

    if odd, then median point
    else median poins and range inclusive


*/


void solve(){
    int n;cin>>n;

    vector<int> px(n);
    vector<int> py(n);

    for(int i=0;i<n;++i){
        cin>>px[i];
        cin>>py[i];
    }

    sort(px.begin(),px.end());
    sort(py.begin(),py.end());

    if(n&1){
        cout << 1 <<endl;
    }
    else{
        int a = px[(n/2)-1];
        int b = px[n/2];
        int rangepx = b-a+1;

        int c = py[(n/2)-1];
        int d = py[n/2];
        int rangepy = d-c+1;

        cout << rangepx*rangepy <<endl;
    }


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}