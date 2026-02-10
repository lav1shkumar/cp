#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,x;cin>>n>>x;

    int cur = 0;
    int mx = LLONG_MIN; 

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cur +=(b-1)*a;
        mx =max(mx, a*b - c);
    }

    if(cur>= x){
        cout <<0<<endl;
        return;
    }

    if(mx<=0){
        cout <<-1<<endl;
        return;
    }

    int rem = x-cur;
    cout <<(rem+mx-1)/mx<<endl;
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