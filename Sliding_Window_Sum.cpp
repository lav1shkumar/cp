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

    int x,a,b,c; cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0]=x;

    for(int i=1;i<n;++i){
        arr[i] = ((a*arr[i-1]) + b) % c;

    }

    vector<int> pref(n);
    pref[0]=arr[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+arr[i];

    int XOR=pref[k-1];

    for(int i=k;i<n;++i){
        int win_xor = pref[i]-pref[i-k];
        XOR^=win_xor;
    }

    cout<<XOR<<endl;


}