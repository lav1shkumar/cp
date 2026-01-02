#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
so basically, if xor of all number equal to zero or not

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    vector<int> prexor(n);

    int lastidx = -1;

    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(i!=0) prexor[i]=prexor[i-1]^arr[i];
        else prexor[0]=arr[i];
        if(prexor[i]==0) lastidx = i;
    }

    if(prexor[n-1]==0){
        cout << "YES" <<endl;
        return;
    }
    
    for(int i=0;i<lastidx;++i){
        if(prexor[n-1]==prexor[i]){
            cout << "YES" <<endl;
            return;
        }
    }

    cout << "NO" <<endl;
    return;




    



}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}