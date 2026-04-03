#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];

    vector<int> ans(n);


    int prev = gcd(a[0],a[1]);
    ans[0]=prev;
    ans[n-1] = gcd(a[n-1],a[n-2]);

    for(int i=1;i<n-1;++i){

        int cur = gcd(a[i],a[i+1]);
        ans[i] = (prev*cur)/gcd(prev,cur);
        prev=cur;

    }
    int cnt=0;
    for(int i=0;i<n;++i){
        if(ans[i]!=a[i]) cnt++;
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